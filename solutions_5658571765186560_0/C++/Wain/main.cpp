//
//  main.cpp
//  CodeJam2015

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void runQuestion(int number)
{
    int result = 0;
    int xVal, rVal, cVal;
    
    cin >> xVal >> rVal >> cVal;

    if ( xVal >= 7 )                    // make hole and kick his ass.
        result = 1;
    else if ( xVal == 1 )               // no way
        result = 0;
    else if ( rVal*cVal % xVal != 0 )   // can't fill, anyway.
        result = 1;
    else if ( rVal*cVal < xVal )        // oversized
        result = 1;
    else if ( rVal < xVal && cVal < xVal )  // make long x-omino
        result = 1;
    else if ( rVal*2 < xVal || cVal*2 < xVal ) // make L x-omino
        result = 1;
  
    else if ( xVal == 2 || xVal == 3 )  // no way, too.
        result = 0;                     // automatically include ( rVal*cVal% xVal == 0 )
                                        // automatically include ( rVal <= 1, rVal & cVal < xVal )
    else if ( xVal == 5 ) {
        if ( ( cVal == 3 && rVal == 5 ) || ( cVal == 5 && rVal == 3 ) )
            result = 1;    // 5*3 has just 1 way to win : make 'w'
        else
            result = 0;    // every other case is derived from 5*3. ( with rVal*cVal%xVal == 0 )
                           // 'w' is possible to handle 10x3, and so on.
    }
    else {
        // xVal == 4 or 6
        // rVal*cVal%xVal = 0
        
        if ( rVal < cVal ) {
            int tmp = cVal;
            cVal = rVal;
            rVal = tmp;
        }
        // always cVal <= rVal

        // xVal(4) cVal >= 2
        // xVal(6) cVal >= 3
        
        if ( cVal == 2 && xVal == 4 ) {
            result = 1; // make T x-omino and win, any rVal.
        }
        else if ( cVal == 3 && xVal == 6 ) {
            /* make and win. any rVal.
                oo
                oo
               oo
            */
            result = 1;
        }
        
        // xVal(4) cVal >= 3
        // xVal(6) cVal >= 4
        else if ( xVal == 4 ) {   // 4x3 is possible, 4x4, 4x5, 4x6, 4x.., 8x3 8x6 8x9.. is automatically possible. 6x6 is possible too.
            result = 0;
        }
        else if ( xVal == 6 ) {     // 6x4 is possible, (can't divide 2 area)
            result = 0;
        }
        
        else
            result = 0;
    }
    
    
    if ( result == 1 ) {
      cout << "Case #" << number << ": " << "RICHARD";
    }
    else {
      cout << "Case #" << number << ": " << "GABRIEL";
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

