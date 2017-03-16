//
//  main.cpp
//  A
//
//  Created by skywalker on 6-5月-2012.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
//#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>



using namespace std;

#define xx first
#define yy second
#define pi 3.14159265358979
#define p2 1.57079632679489
#define p4 0.78539816339744
#define rep(i,a,b) for(i=a;i<b;++i)
#define repr(i,a,b) for(i=a;i>b;--i)
#define mp(a,b) make_pair(a,b)
#define mm(a,b) memset(a,b,sizeof(a))
#define maxn 1080

int map[maxn][maxn];
int used[maxn];


int n,flag;


void readfile(void)
{
    cin>>n;
    int i,a,b,j;
    for (i=1; i<=n; ++i) {
        cin>>b;
        for (j=1; j<=b; ++j) {
            cin>>a;
            map[a][i]=1;
        }
    }
}

void DFS(int a)
{
    if (used[a]) {
        flag=true;
        return;
    }
    if(flag)
        return;
    int i;
    used[a]=true;
    for(i=1;i<=n && !flag ;++i)
        if (map[a][i]) {
            DFS(i);
        }
}

void process(void)
{
    int i;
    mm(used, 0);
    flag=false;
    for (i=1; i<=n; ++i) {
        used[1]=used[2]=used[3]=0;
        DFS(i);
        if (flag) {
            puts("Yes");
            return;
        }
        mm(used, 0);
        flag=false;
    }
    
    puts("No");
}

void clear(void)
{
    n=0;
    mm(map, 0);
    flag=false;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    freopen("A.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    int T,i;
    cin>>T;
    for (i=0; i<T; ++i) {
        readfile();
        printf("Case #%d: ",i+1);
        process();
        clear();
    }
    return 0;
}

