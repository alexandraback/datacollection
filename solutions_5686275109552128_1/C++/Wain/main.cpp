//
//  main.cpp
//  CodeJam2015

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

bool sortfunc(int i, int j) { return (i>j); }

void runQuestion(int number)
{
    int result = 0;
    int input_maxNum;
    int target[1280];
    // 1024>512*2+1>256*4+3>128*8+7>64*16+15>32*32+31
    // 1024*n > 32*32*n + 31*n
    // max range :: 1024 > 1000 // additionally - 128
    cin >> input_maxNum;
    for ( int i = 0 ; i < input_maxNum ; i++) {
        cin >> target[i];
    }

    vector<double> myvector( target, target+input_maxNum );
    sort(myvector.begin(), myvector.end(), sortfunc);

    int minimalValue = myvector[0];
    int currentValue = 0;

    for ( double i = 2; i < myvector[0] ; i++ ) {
        currentValue = 0;
        for ( int j = 0 ; j < myvector.size() ; j++ ) {
            currentValue += ceil(myvector[j]/i)-1;
//            cout << i << ":" << myvector[j] << ":" << ceil(myvector[j]/i)-1 << endl;
        }
        currentValue += i;
        if ( minimalValue > currentValue )
            minimalValue = currentValue;
    }
    result = minimalValue;

//    for ( int i = 0 ; i < myvector.size() ; i++ ) {
//        cout << i << ":" << myvector[i] << endl;
//    }
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

