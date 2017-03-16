//
//  main.cpp / Counting Sheep
//  CodeJam2016

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void runQuestion(int number)
{

    // input
    int inputNumber;
    cin >> inputNumber;

    // setting
    int maxCount = 999999;
    long result = 0;
    int target[10] = {0, 0,0,0, 0,0,0, 0,0,0 };
    int targetNullCount = 10;

    // calculation

    if ( target != 0 ) {
        for ( int i = 1 ; i < maxCount ; i++ ) {
            long targetNumber = i*inputNumber;
            while ( targetNumber > 0 && targetNullCount != 0 ) {
                int currentLevel = targetNumber % 10;
                targetNumber = ( targetNumber - currentLevel )/10;
                if ( target[currentLevel] == 0 ) {
                    target[currentLevel] = 1;
                    targetNullCount--;
                }
            }
            if ( targetNullCount == 0 ) {
                result = i*inputNumber;
                break;
            }
        }
    }
    else {
        result = 0;
    }

    // output
    if ( result == 0 ) {
        cout << "Case #" << number << ": INSOMNIA";
    }
    else {
        cout << "Case #" << number << ": " << result;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {

    int howManyTimes;

    scanf("%d", &howManyTimes);

    for ( int i = 0 ; i < howManyTimes ; i++ ) {
        runQuestion(i+1);
    }

    return 0;
}

