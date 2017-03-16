//
//  C.cpp
//  DESIGN
//
//  Created by Shankar, Penumaka Bhavani on 4/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int numDigits = 0;
int max10 = 10;
int rotate(int A)
{
    int ret = A%10;
    A /= 10;
    ret = ret * max10 + A;
    //cout << ret<< " ";
    return ret;
}
int f(int A, int B)
{
    max10 = 1;
    numDigits = 1;
    while(A/(max10*10) != 0 )
    {
        numDigits++;
        max10 *= 10;
    }
    int ret = 0;
    for ( int i = A; i <= B; i++ )
    {
        int val = i;
        set <int> s1;
        for( int j = 0 ; j < numDigits; j++ )
        {
            val = rotate(val);
            if ( val > i && val <= B)
            {
                s1.insert(val);
            }
        }
        ret += s1.size();
        
    }
    cout << ret<<endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for ( int i = 0 ; i < t; i++ )
    {
        cout << "Case #"<<(i+1)<<": ";
        int A,B;
        cin >> A >> B;
        f(A,B);
    }
}