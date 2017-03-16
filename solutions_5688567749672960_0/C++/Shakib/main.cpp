//
//  main.cpp
//  General
//
//  Created by Shakib Ahmed on 4/27/15.
//  Copyright (c) 2015 Shakib Ahmed. All rights reserved.
//

//Bismillahir Rahmanir Rahmeem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define INF 1e9
#define lld long long int
#define CLR(a) memset(a,0,sizeof(a))
#define RESET(a) memset(a,-1,sizeof(a))
#define act(a) memset(a,1,sizeof(a))
#define setinf(a) memset(a,0b01111111,sizeof(a));
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define ui unsigned int
#define came "came"
#define pii pair<int,int>
#define plii pair<long long int, int>
#define pll pair<long long,long long>
#define pic pair<int,char>
#define ninf (-1e9)-2
#define inf (1e9)+2
#include<fstream>
#include <assert.h>
#include <bitset>

#define foreach(x) for(__typeof(x.begin()) it=x.begin(); it!=x.end();it++)

using namespace std;
#define pid pair<int,double>
#define pdi pair<double,int>

#define PB push_back
#define MP make_pair
#define pri(x) printf("%d\n",x)
#define pi 3.14159265359
#define F first
#define S second
#define vit vector<int>::iterator

//Problem A. Counter Culture

lld n;

lld memo[1000005];

lld rev(lld v)
{
    lld ret=0;
    while(v)
    {
        ret=ret*10+v%10;
        v/=10;
    }
    return ret;
}

lld func(lld val)
{
    if(val==n)
    {
        return 1 ;
    }
    else if(val>n)
    {
        return 1e7;
    }
    else
    {
        lld &ret=memo[val];
        lld r=rev(val);
        if(ret!=-1)
        {
            return ret;
        }
        ret=1e9;
        if(r>val)
        {
            lld v=func(r);
            ret=min(ret,v+1);
        }
        
        {
            lld v=func(val+1);
            ret=min(ret,v+1);
        }
        return ret;
    }
}

int main(int argc, const char * argv[])
{
    FRO
    FROut
    
    int t;
    scanf("%d",&t);
    
    int ca;
    
    for(ca=1;ca<=t;ca++)
    {
        RESET(memo);
        scanf("%lld",&n);
        lld ans=func(1);
        printf("Case #%d: %lld\n",ca,ans);
    }
    
    return 0;
}




