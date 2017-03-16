//
//  main.cpp
//  CookieClicker
//
//  Created by Alex Wang on 4/11/2014.
//  Copyright (c) 2014 Alex Wang. All rights reserved.
//

#include <iostream>
#include "math.h"
#include <algorithm>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        double c,f,x;
        cin>>c>>f>>x;
        double ans=x;
        double cost=0;
        for (long j=0;j<round(x);j++){
            ans=min(ans,cost+(x/(j*f+2)));
            cost=cost+c/(j*f+2);
        }
        cout<<"Case #"<<i+1<<": "<<fixed<<setprecision(7)<<ans<<endl;
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}

