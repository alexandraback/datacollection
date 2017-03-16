// -*- mode:c++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-  
#include <iostream>

using namespace std;

int main()
{
    long T, n;
    int i, j, k, x, y;
    cin >> T;
    
    for (i=0; i<T; i++) {
        cin >> x >> y;
        cout << "Case #" << i+1 << ": ";
        if (x > 0) {
            for (j=0; j<x; j++) 
                cout << "WE";
        }
        else {
            x = -x;
            for (j=0; j<x; j++) 
                cout << "EW";
        }
        
        if (y > 0) {
            for (j=0; j<y; j++) 
                cout << "SN";
        }
        else {
            y = -y;
            for (j=0; j<y; j++) 
                cout << "NS";
        }
            
        cout << endl;
    }
    return 0;
}
