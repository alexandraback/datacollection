//
//  main.cpp
//  war
//
//  Created by Zulkarnine on 4/13/14.
//  Copyright (c) 2014 Zulkarnine Mahmud. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <list>

using namespace std;

#define nl cout<<endl
#define MAX_W 2.0

int solveDeceit(vector<double> first, vector<double> second){
    int firstPoint=0;
    int secondPOint=0;
    
    int size=first.size();
    
    int prevPoint=size-1;
    for (int i=size-1; i>=0&&prevPoint>=0; i--) {
        for (int j=prevPoint; j>=0; j--) {
            if (second[j]<first[i]) {
                firstPoint++;
                second[j]=MAX_W;
                j=prevPoint;
                break;
            }
        }
    }
    //    firstPoint=size-secondPOint;
    return firstPoint;
}

int solveReal(vector<double> first, vector<double> second){
    int firstPoint=0;
    int secondPoint=0;
    
    int size=first.size();
    int prevpoint=0;
    for (int i=0; i<size; i++) {
        for (int j=prevpoint; j<size; j++) {
            if (second[j]>first[i]) {
                secondPoint++;
                second[j]=0;
                prevpoint=j;
                break;
            }
        }
    }
    
    firstPoint=size-secondPoint;
    return firstPoint;
}


void solveCase(vector<double> first,vector<double> second){
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    printf("%d %d\n",solveDeceit(first, second),solveReal(first,second));
    
}

int main(int argc, const char * argv[])
{
    int T,cas=0;
    
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    
    
    //        freopen("/Users/rezan_mahmud/Desktop/Codejam/t.inp", "r", stdin);
    //        freopen("/Users/rezan_mahmud/Desktop/Codejam/t.out", "w", stdout);
    
    
    
    cin>>T;
    while (T--) {
        int N;
        cin>>N;
        double temp;
        
        vector<double> firstPlayer;
        vector<double> secondPlayer;
        
        for (int i=0; i<N; i++) {
            cin>>temp;
            firstPlayer.push_back(temp);
        }
        
        for (int i=0; i<N; i++) {
            cin>>temp;
            secondPlayer.push_back(temp);
        }
        
        printf("Case #%d: ",++cas);
        solveCase(firstPlayer, secondPlayer);
        
    }
    
    
    return 0;
}
