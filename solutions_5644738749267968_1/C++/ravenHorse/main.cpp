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
        
        int n;
        inFile>>n;
        
        vector<double> Noami(n, 0.0);
        vector<double> Ken(n, 0.0);
        
        for (int i = 0; i < n; i++)
        {
            inFile>>Noami[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            inFile>>Ken[i];
        }
       
        sort(Noami.begin(), Noami.end());
        sort(Ken.begin(), Ken.end());

        int kEnd = 0;
        int ans2 = 0;
        
        for (int i = 0; i < n ; i++)
        {
            if (Noami[i] > Ken[kEnd])
            {
                ans2++;
                kEnd++;
            }
        }
        
        int ans1 = 0;
        int kenIndex = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (kenIndex >= n) break;
            
            while(Ken[kenIndex] <= Noami[i] && kenIndex < n)
            {
                kenIndex++;
            }
            if (kenIndex == n) break;
            else
            {
                ans1++;
                kenIndex++;
            }
        }
            
        
        outFile<<"Case #"<<ca<<": "<<ans2<<" "<<n - ans1<<endl;
        
        
        
    }
    inFile.close();
    outFile.close();
    return 0;
}

