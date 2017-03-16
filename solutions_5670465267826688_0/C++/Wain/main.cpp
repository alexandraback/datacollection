//
//  main.cpp
//  CodeJam2015

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct IJK
{
    char character;
    int minus;
};

IJK runIJK(IJK a, char b) {
    IJK result;
    result.character='_';
    result.minus = 1;

    if ( a.character == 'i' ) {
        if ( b == 'i') {
            result.character = '_';
            result.minus = a.minus*(-1);
        }
        else if ( b == 'j' ) {
            result.character = 'k';
            result.minus = a.minus;
        }
        else if ( b == 'k') {
            result.character = 'j';
            result.minus = a.minus*(-1);
        }
        else {
            result.character = a.character;
            result.minus = a.minus;
        }
    }
    else if ( a.character == 'j' ) {
        if ( b == 'i') {
            result.character = 'k';
            result.minus = a.minus*(-1);
        }
        else if ( b == 'j' ) {
            result.character = '_';
            result.minus = a.minus*(-1);
        }
        else if ( b == 'k') {
            result.character = 'i';
            result.minus = a.minus;
        }
        else {
            result.character = a.character;
            result.minus = a.minus;
        }
    }
    else if ( a.character == 'k' ) {
        if ( b == 'i') {
            result.character = 'j';
            result.minus = a.minus;
        }
        else if ( b == 'j' ) {
            result.character = 'i';
            result.minus = a.minus*(-1);
        }
        else if ( b == 'k') {
            result.character = '_';
            result.minus = a.minus*(-1);
        }
        else {
            result.character = a.character;
            result.minus = a.minus;
        }
    }
    else {
        result.character = b;
        result.minus = a.minus;
    }
    
    
    return result;
}

IJK simplify(char* target, int length)
{
    IJK curResult;
    curResult.character = target[0];
    curResult.minus = 1;
    
    for ( int i = 1 ; i < length ; i++ ) {
        curResult = runIJK(curResult, target[i]);
    }
    
    return curResult;
}

void runQuestion(int number)
{
//    int result = 0;
    int charLength, charTimes;
    char target[10000];
    
    cin >> charLength >> charTimes;
    for ( int i = 0 ; i < charLength ; i++) {
        cin >> target[i];
    }
    IJK currentIJK;
    currentIJK.character = '_';
    currentIJK.minus = 1;
    
    int currentStage = 0;
    /*
     0: looking for i,
     1: looking for j,
     2: looking for k,
     3: trying to remove every left characters.
    */
    
//    int currentIndex = 1;
    
    IJK simpleTarget = simplify(target, charLength);
    int doSimplify = 0;
    
    for ( int j = 0 ; j < charTimes ; j++ ) {
        for ( int i = 0 ; i < charLength ; i++ ) {
            if ( doSimplify == 1 ) {
                currentIJK.minus = currentIJK.minus * simpleTarget.minus;
                currentIJK = runIJK(currentIJK, simpleTarget.character);
                i = charLength;
            }
            else {
                currentIJK = runIJK(currentIJK, target[i]);
            }
            if ( (currentStage == 0 && currentIJK.character == 'i') ||
                (currentStage == 1 && currentIJK.character == 'j') ||
                (currentStage == 2 && currentIJK.character == 'k') ) {
                currentStage++;
                currentIJK.character = '_';
            }
        }
        if ( currentStage == 3 )
            doSimplify = 1;
    }
    
    if ( currentStage == 3 && currentIJK.character == '_' && currentIJK.minus == 1 ) {
      cout << "Case #" << number << ": " << "YES";
    }
    else {
      cout << "Case #" << number << ": " << "NO";
    }
//    cout << "Case #" << number << ": " << result;
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

