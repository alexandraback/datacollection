
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

typedef long double LD;

int main(){

    int TC,c,d,a,b;

    scanf("%d",&TC);
    int casenum =1 ;
    while(TC--){
        LD C,F,X;
        cin >> C >> F >> X;
        LD rate = 2.0;
        LD numCookies = 0.0;
        LD numFarms = 0.0;
        LD time = 0.0;
        LD minTime = 1E30;
        while(true){
            // keep trying
            // at this rate how long will it take
            LD ctime = ((X - numCookies)/rate) + time;
            if(ctime > minTime) break;
            else if(ctime < minTime) minTime = ctime;
            // try to by more farms;
            // how much time till next farm.
            LD ftime = (C-numCookies)/rate;
            time += ftime;
            numCookies = 0.0;
            rate += F;
        }
        printf("Case #%d: %.7Lf\n",casenum++,minTime);
    }
}
