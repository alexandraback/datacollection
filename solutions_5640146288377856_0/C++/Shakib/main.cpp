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


int r,c,w;

int mask[1<<20];




int main(int argc, const char * argv[])
{
    
    FRO
    FROut
    
    
    int ca,t;
    scanf("%d",&t);
    
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d %d %d",&r,&c,&w);
        int ans=c/w;
        if(c%w) ans++;
        ans+=w-1;
        printf("Case #%d: %d\n",ca,ans);
    }
    
    return 0;
}




