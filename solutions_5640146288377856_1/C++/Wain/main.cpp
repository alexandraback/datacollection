//  main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <array>
#include <assert.h>

#define foreach(i,n) for(int i = 0 ; i < n ; i++ )
#define swap(a,b) {int t;t=a;a=b;b=t;}
#define _testing false
#define TMPMAX_INT 987654321

using namespace std;

int getUnhappiness(array<int, 10000> *targetArray, int row, int col) {
    int result = 0;
    
    int curRow; // position%row
    int curCol; // (position-curRow)/row

    foreach(i, row*col) {
        curRow = i%row;
        curCol = (i-curRow)/row;
        if ( (*targetArray)[i] == 0 ) continue;
        if ( curRow < row-1 ) { // not right-most
            if ( (*targetArray)[i+1] >= 1 ) {
                result++;   // right has person.
            }
        }
        if ( curCol < col-1 ) { // not down-most
            if ( (*targetArray)[i+row] >= 1 ) {
                result++;
            }
        }
    }
    
    return result;
}

// 1 <= width <= col
// 1 <= col <= 10
// row = 1

int countMinimalNumber_notThere(int col, int width) {
    int firsthit = (col-col%width)/width;
    
    return firsthit;
}

// *만약 케이스가 row 가 확장되면,
// 1) 해당 row에 '없는지'를 체크하는 루틴을 빈 row 만큼 호출한다
// 2) 그 뒤에 기존의 '있다고 치고 체크하는' 루틴을 호출한다. 가로니까.
int countMinimalNumber_simple(int row, int col, int width) {
    
    int smallestValue = 0;
    
//    array<int, 400> roomArray;
//    foreach(i, 400) {
//        roomArray[i]=0;
//    }
    int smallestMissedRow = (row-1) * countMinimalNumber_notThere(col,width);
    if ( width == 1 ) return row*col;
    if ( width == col ) {
        return col + smallestMissedRow;
    }
    
    int firsthit = (col-col%width)/width;
    int lastStruggle = 1;
    if ( col%width == 0 ) lastStruggle = 0;
    int leftBodyPart = width-1;
    
    smallestValue = firsthit+lastStruggle+leftBodyPart + smallestMissedRow;
    return smallestValue;
}
int runFunction(int row, int col, int width) {
    
    return countMinimalNumber_simple(row, col, width);
}

void runQuestion(int questionNumber)
{
    int result = -1;
    
    int row, col, width;
    
    cin >> row >> col >> width;
    
    result = runFunction(row, col, width );
    
    cout << "Case #" << questionNumber << ": " << result << endl;
}

int main(int argc, const char * argv[]) {
    
    int howManyTimes;

   
    if ( _testing) {
        vector<int> testInput       = {3,4,2, 3,7,7, 3,10,7, 3,10,2, 3,9,3, 3,4,3, 3,5,1};
        vector<int> testOutput      = {    7,     9,     10,     16,    11,     6,    15};
        bool testError = false;
        foreach (i,testOutput.size()) {
            int output=0;
            output = runFunction(testInput[i*3], testInput[i*3+1], testInput[i*3+2]);
            if ( output != testOutput[i] )
            {
                testError = true;
                cout << "input " << testInput[i*3] <<","<< testInput[i*3+1] << " expect " << testOutput[i] << " result: " << output << endl;
            }
        }
        if ( testError ) {
            cout << "error." << endl;
        }
        else {
            cout << "done." << endl;
        }
        
        return 0;
    }
    
    scanf("%d", &howManyTimes);

    foreach(i,howManyTimes) {
        runQuestion(i+1);
    }

    return 0;
}

