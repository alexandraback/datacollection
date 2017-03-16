//
//  main.cpp
//  Slides
//
//  Created by Qiu Xin on 8/5/16.
//  Copyright © 2016 Qiu Xin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    int runNum, B, M;
    cin >> runNum;
    for (int i=1;i<=runNum;i++)
    {
        cout<<"Case #"<<i<<":";
        cin>>B;
        cin>>M;
        vector<vector<int>> store(B,vector<int>(B,0));
        for (int j=0;j<B;j++)
        {
            for (int k=j+1;k<B;k++)
                store[j][k]=1;
        }
        double num=pow(2,B-2);
        if (M>num)
        {
            cout<<' '<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<' '<<"POSSIBLE"<<endl;
        if (M==num)
        {
            for (int j=0;j<B;j++)
            {
                for (int k=0;k<B;k++)
                    cout<<store[j][k];
                cout<<endl;
            }
            continue;
        }
        num/=2;
        int del=B-2;
        while(M)
        {
            if (M>=num)
            {
                M-=num;
                store[del][B-1]=0;
            }
            del--;
            num/=2;
        }
        for (int j=0;j<B;j++)
        {
            for (int k=0;k<B;k++)
                cout<<store[j][k];
            cout<<endl;
        }
    }
    return 0;
}

