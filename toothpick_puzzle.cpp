//
//  main.cpp
//  proj1kanungo
//
//  Created by SUBHRA KANUNGO on 20/01/2018.
//  Copyright © 2018 SUBHRA KANUNGO. All rights reserved.
//
/*
 Program #1: Toothpicks: Puzzle to equalize the number of toothpicks in three stacks.
 Class: CS 141
 Author: Subhra Kanungo
 Lab: Tuesday 5pm
 System:  C++ Mac Xcode
 
 Grading Rubric:
 
 50 Execution points
    5 Displays header info on screen when run
    5 Displays instructions
    5 Output is formatted as shown in sample output
    3 Handles both upper and lower case input
    5 Input can be adjacent or have spaces between them
    15 Makes moves correctly
    10 Handles the specified error conditions
    2 Gives appropriate end of program messages
 
 50 Programming Style (Given only if program runs substantially correctly)
    5 Program naming convention is followed
    10 Meaningful identifier names
    10 Comments: Has header.  Comments on each block of code
    10 Appropriate data and control structures
    10 Code Layout: Appropriate indentation and blank lines
 */
 
#include <iostream> // For cin and cout
#include <iomanip> // for formatted output using setw()
using namespace std;

int main() {
    // Display identifying information
    cout << "Hello!\n";
    cout << "Program #1: Toothpicks: Puzzle to equalize the number of toothpicks in each stack\n";
    cout << "Class: CS 141\n";
    cout << "Author: Subhra Kanungo\n";
    cout << "Lab: Tuesday 5PM\n";
    cout << "System: C++ Mac Xcode\n\n";
    cout << "Welcome to the Toothpick Puzzle, where the goal is to get an equal" << endl
         << "number of toothpicks in each stack, in three moves." << endl;
    cout << "\n                 Stack:  A  B  C" << endl
         << "  Number of Toothpicks: 11  7  6" << endl;
    cout << "\nA move consists of moving toothpicks from one stack to a second stack," << endl
         << "where the number of toothpicks moved is exactly the number that is in the" << endl
         << "destination stack.  In other words, to move from stack B (7 toothpicks)" << endl
         << "to stack C (6) as shown above, we would move 6 from B to C, leaving us" << endl
         << "with 1 in B and 12 in stack C." << endl;// endl means finish displaying this line of output and move cursor to next line
    cout << "\n Here we go...\n";
    
    cout << "\n                 Stack:  A  B  C" << endl
         << "  Number of Toothpicks: 11  7  6" << endl;
    
    // declare variables used in the program
    char stackFrom; // character initialized as the stack from which the toothpicks will be taken
    char stackTo; // character initialized as the stack to which the toothpicks will be transferred
    int toothpick_FirstStack = 11; // number of toothpicks in the first stack
    int toothpick_SecondStack = 7; // number of toothpicks in the second stack
    int toothpick_ThirdStack = 6; // number of toothpicks in the third stack
    
    // Demonstrate how you can use a loop to count. this is for the 3 tries that the user will get to input the values. it varies from 1..4
    int loopCounter = 1;
    while (loopCounter < 4){
        // add the loopcounter to the display as the number of tries done
        cout << "\n" << loopCounter << "." << "   enter FROM and TO stack letter:\n" << endl;
        cin >> stackFrom; // get user to input the first character
        cin >> stackTo; // get user to input the second character
        while (isspace(stackTo)){
            //as long as there is a 'whitespace' in the input by the user, this will ask u to input a character again which is valid
            cin >> stackTo;
        }
        // forces all the lowercase letters to uppercase letters in order for easier comparison
        stackFrom = toupper(stackFrom);
        stackTo = toupper(stackTo);
        // demonstrates the different options to compare from the user inputs given. therefore have used if-elseif statements.
        if (stackFrom == 'A' && stackTo == 'B'){
            // demonstrates the comparison of the integer value of the number of toothpicks in A and B
            if (toothpick_FirstStack > toothpick_SecondStack){
                toothpick_FirstStack = toothpick_FirstStack - toothpick_SecondStack;
                toothpick_SecondStack += toothpick_SecondStack;
            }
            // demonstrates the alternative if the INNER 'if condition' does not comply
            else {
                cout << "Sorry, not enough toothpicks in A. Retry...\n" << endl; // The \n is a newline character
                continue;//jump back up to the INNER loop to try again since the entry by the user was wrong
            }
        }
        // the else-if statement for a different condition of stack A TO C
        else if (stackFrom == 'A' && stackTo == 'C'){
            // this if condition demonstrates comparison of number of toothpicks in A and C
            if (toothpick_FirstStack > toothpick_ThirdStack){
                toothpick_FirstStack = toothpick_FirstStack - toothpick_ThirdStack;
                toothpick_ThirdStack += toothpick_ThirdStack;
            }
            // demonstrates the alternative if the INSIDE 'if condition' does not comply
            else {
                cout << "Sorry, not enough toothpicks in A. Retry...\n" << endl;
                continue; //jump back up to the INNER loop to try again since the entry by the user was wrong
            }
        }
        // the else-if statement for a different condition of stack B TO A
        else if (stackFrom == 'B' && stackTo == 'A'){
            // this if condition demonstrates comparison of number of toothpicks in B and A
            if (toothpick_SecondStack > toothpick_FirstStack){
                toothpick_SecondStack = toothpick_SecondStack - toothpick_FirstStack;
                toothpick_FirstStack += toothpick_FirstStack;
            }
            // demonstrates the alternative if the INSIDE 'if condition' does not comply
            else {
                cout << "Sorry, not enough toothpicks in B. Retry...\n" << endl;
                continue; //jump back up to the INNER loop to try again since the entry by the user was wrong
            }
        }
        // the else-if statement for a different condition of stack B TO C
        else if (stackFrom == 'B' && stackTo == 'C'){
            // this if condition demonstrates comparison of number of toothpicks in B and C
            if (toothpick_SecondStack > toothpick_ThirdStack){
                toothpick_SecondStack = toothpick_SecondStack - toothpick_ThirdStack;
                toothpick_ThirdStack += toothpick_ThirdStack;
            }
            // demonstrates the alternative if the INSIDE 'if condition' does not comply
            else {
                cout << "Sorry, not enough toothpicks in B. Retry...\n" << endl;
                continue; //jump back up to the INNER loop to try again since the entry by the user was wrong
            }
        }
        // the else-if statement for a different condition of stack C TO A
        else if (stackFrom == 'C' && stackTo == 'A'){
            // this if condition demonstrates comparison of number of toothpicks in C and A
            if (toothpick_ThirdStack > toothpick_FirstStack){
                toothpick_ThirdStack = toothpick_ThirdStack - toothpick_FirstStack;
                toothpick_FirstStack += toothpick_FirstStack;
            }
            // demonstrates the alternative if the INSIDE 'if condition' does not comply
            else {
                cout << "Sorry, not enough toothpicks in C. Retry...\n" << endl;
                continue; //jump back up to the INNER loop to try again since the entry by the user was wrong
            }
        }
        // the else-if statement for a different condition of stack C TO B
        else if (stackFrom == 'C' && stackTo == 'B'){
            // this if condition demonstrates comparison of number of toothpicks in C and B
            if (toothpick_ThirdStack > toothpick_SecondStack){
                toothpick_ThirdStack = toothpick_ThirdStack - toothpick_SecondStack;
                toothpick_SecondStack += toothpick_SecondStack;
            }
            // demonstrates the alternative if the INSIDE 'if condition' does not comply
            else {
                cout << "Sorry, not enough toothpicks in C. Retry...\n" << endl;
                continue; //jump back up to the INNER loop to try again since the entry by the user was wrong
            }
        }
        // this else statements demonstrates the execution only when all the if-elseif conditions fails.
        else {
            cout << "wrong character input\n";
            continue;// jump back to the beginning of the loop to try again.
        }
        //displays the number of toothpicks in stack after the calculations are done, with the changed values in each stack
        cout <<"\n                 Stack:  A  B  C" << endl;
        cout <<"  Number of Toothpicks: " << toothpick_FirstStack << "  " << toothpick_SecondStack << "  " << toothpick_ThirdStack << "  "  << endl;
        loopCounter += 1; // the loopcounter to go on to the next try for the user
    }// end of while loop
    // demonstrates to check whether all the stacks consist of the same number of toothpicks
    if (toothpick_ThirdStack != toothpick_SecondStack){
        // if not then you give the output to try again
        cout << "Nope, sorry, that's not it.  Try again." << endl;
        cout << "Ending program..." << endl;
    }
    return 0;
} // end main
