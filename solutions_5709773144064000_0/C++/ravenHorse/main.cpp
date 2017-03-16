//
//  main.cpp
//  2B
//
//  Created by Xiaowei Ma on 20/02/2014.
//  Copyright (c) 2014 Xiaowei Ma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;



int main()
{
    ifstream inFile;
    inFile.open("/Users/xiaoweima/Desktop/2B/2B/in.in");
    
    ofstream outFile;
    outFile.open("/Users/xiaoweima/Desktop/2B/2B/out.out");
    
    
    int T;
    inFile>>T;
    
    for (int ca = 1; ca <= T; ca++)
    {
        
        double C, F, X;
        inFile>>C>>F>>X;
        
       
        
        if (X <= C)
        {
            outFile<<"Case #"<<ca<<": "<<X/2.0<<endl;
            continue;
        }
        
        double t = C/2.0;
        double currentK = 2.0;
        
        while(true)
        {
            double meetPoint = C+C / F * currentK;
            
            if (meetPoint < X)
            {
                currentK += F;
                t += C/currentK;
            }
            else
            {
                double deltaH = X-C;
                double deltaT = deltaH/currentK;
                t += deltaT;
                outFile<<"Case #"<<ca<<": "<<setprecision(8)<<t<<endl;
                break;
                
            }
            
        }
        
        
       
    }
    inFile.close();
    outFile.close();
    return 0;
}

