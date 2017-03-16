//
//  main.cpp
//  TaskB
//
//  Created by Quoc-Huy Tran on 12/04/2014.
//  Copyright (c) 2014 *. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double minTime(double X, double s, double C, double f) {
    if (X>C && C/s+X/(s+f) < X/s)
        return C/s+minTime(X,(s+f),C,f);
    else
        return X/s;
    
}

int main()
{
    int T;
    cin>>T;
    
    double C, f, X;
    for (int i=0; i<T; i++) {
        cin>>C>>f>>X;
        cout<<"Case #"<<i+1<<": "<<setiosflags(ios::fixed)<<setprecision(7)<<minTime(X,2,C,f)<<endl;
    }

    return 0;
}

