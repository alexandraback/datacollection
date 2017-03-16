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

int k;
int freq[26];

char keyboard[105];

char target[205];

double memo[105][105][105];

bool flag[105][105][105];

int l,s;

int f[1000006];

void failure(char *a)
{
    CLR(f);
    int ln=(int)strlen(a+1);
    int i;
    f[1]=0;
    int k=0;
    for(i=2;i<=ln;i++)
    {
        while(k>0 && a[k+1]!=a[i])
        {
            k=f[k];
        }
        if(a[k+1]==a[i])
        {
            k++;
        }
        f[i]=k;
    }
}


int maxMatch;

double dp(int indx, int matchIndx, int matchNumber)
{
    if(matchIndx==l)
    {
        return dp(indx,f[l],matchNumber+1);
    }
    else if(indx==s+1)
    {
        maxMatch=max(maxMatch,matchNumber);
        return matchNumber;
    }
    else
    {
        double &ret=memo[indx][matchIndx][matchNumber];
        
        if(flag[indx][matchIndx][matchNumber])
        {
            return ret;
        }
        ret=0.0;
        flag[indx][matchIndx][matchNumber]=true;
        
        int omatchIndx=matchIndx;
        
        for(int i=0;i<26;i++)
        {
            if(!freq[i]) continue;
            matchIndx=omatchIndx;
            while(matchIndx && target[matchIndx+1]!=i+'A')
            {
                matchIndx=f[matchIndx];
            }
            if(target[matchIndx+1]==i+'A')
            {
                matchIndx++;
            }
            ret+=((double)freq[i]/k)*dp(indx+1,matchIndx,matchNumber);
        }
        return ret;
    }
}

int main(int argc, const char * argv[])
{
    
    FRO
    FROut
    
    
    int ca,t;
    scanf("%d",&t);
    
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d %d %d",&k,&l,&s);
        scanf("%s %s",keyboard+1,target+1);
        maxMatch=0;
        CLR(flag);
        CLR(freq);
        int i;
        for(i=1;i<=k;i++)
        {
            freq[keyboard[i]-'A']++;
        }
        failure(target);
        double ans=dp(1,0,0);
        printf("Case #%d: %.7f\n",ca,(double)maxMatch- ans);
    }
    
    return 0;
}




