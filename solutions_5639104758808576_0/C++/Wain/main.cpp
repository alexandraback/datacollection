//
//  main.cpp
//  CodeJam2015

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void runQuestion(int number)
{
    int maxNum;
    string target;
    cin >> maxNum >> target;
    int result = 0;
    int currentValue = target[0]-'0';

    for ( int i = 1 ; i < maxNum+1 ; i++ ) {
        if ( currentValue == 0 ) {
            result++;
            currentValue++;
        }
        
        currentValue = currentValue -1 + target[i]-'0';
    }
    
    cout << "Case #" << number << ": " << result;
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

