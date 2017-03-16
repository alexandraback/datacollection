//
//  main.cpp
//  zadB
//
//  Created by Tomasz Krzyżek on 5/12/13.
//  Copyright (c) 2013 Tomasz Krzyżek. All rights reserved.
//

#include <iostream>
#include <string>

#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP(q, T){
        int x, y;
        cin >> x >> y;
        string result;
        if(x >= 0){
            REP(i, x)
                result += "WE";
        }
        else{
            x = abs(x);
            REP(i, x)
                result += "EW";
        }
        if(y >= 0){
            REP(i, y)
                result += "SN";
        }
        else{
            y = abs(y);
            REP(i, y)
                result += "NS";
        }
        cout << "Case #" << q+1 << ": " << result << endl;

    }
    return 0;
}

/*int abs(int a){
    if(a < 0)
        a = -a;
    return a;
}*/

