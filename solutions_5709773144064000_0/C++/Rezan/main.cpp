//
//  main.cpp
//  cookie
//
//  Created by Zulkarnine on 4/12/14.
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

void printAnswer(double ans){
    printf("%.7lf\n",ans);
}

double farmRequiredTime(int farmNumber,double extraProduction,double farmCost){
    return farmCost/(2.0+extraProduction*(double)(farmNumber-1));
}

void solveCase(double farmCost,double additionalCookie,double target){
    double maxTime=target/2.0;
    double farmTime=farmCost/2.0;
    double productionRate=2.0;
    int maxFarm=maxTime/farmTime;
    
    if (farmTime>maxTime) {
        printAnswer(maxTime);
        return;
    }
    
    
    double answer=maxTime;
    double prevFarmTime=0.0;
    int farmCount=0;
    //    double prevAns=maxTime+2;
    do {
        double thisFarmTime=farmRequiredTime(++farmCount, additionalCookie, farmCost);
        productionRate=(2.0+(double)(farmCount)*additionalCookie);
        
        double requiredTime=prevFarmTime+thisFarmTime+(target/productionRate);
        if (requiredTime<answer) {
            //            prevAns=answer;
            answer=requiredTime;
            
        }else break;
        
        prevFarmTime+=thisFarmTime;
    }while (1);
    
    printAnswer(answer);
    
    
}


int main(int argc, const char * argv[])
{
    int T,cas=0;
    
    //    freopen("/Users/rezan_mahmud/Desktop/B-small-attempt1.in", "r", stdin);
    //    freopen("/Users/rezan_mahmud/Desktop/B-small-attempt1.out", "w", stdout);
    
    freopen("/Users/rezan_mahmud/Desktop/Codejam/B-small-attempt4.in", "r", stdin);
    freopen("/Users/rezan_mahmud/Desktop/Codejam/B-small-attempt4.out", "w", stdout);
    
    
    cin>>T;
    while (T--) {
        double farmCost;
        double additionalCookie;
        double target;
        
        cin>>farmCost>>additionalCookie>>target;
        printf("Case #%d: ",++cas);
        solveCase(farmCost,additionalCookie,target);
        
    }
    
    
    return 0;
}
