//
//  main.cpp
//  B
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
long long dp[110][110];
struct fff
{
    long long x,y;
}p[110],q[110];
int main(void)
{
    freopen("B.txt", "r", stdin);
    freopen("B.out", "w", stdout);
    int cas;
    scanf("%d",&cas);
    for(int cc=1;cc<=cas;cc++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld %lld",&p[i].x,&p[i].y);
       // cin>>p[i].x>>p[i].y;
        for(int i=1;i<=m;i++)
            scanf("%lld %lld",&q[i].x,&q[i].y);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
                long long type1=p[i+1].y;
                long long type2=q[j+1].y;
                long long sum1=0;
                long long sum3=0;
                //int mark2,mark4;
                for(int k=i+1;k<=n;k++)
                {
                    if(p[k].y == type1)
                       sum1+=p[k].x;
                    if(p[k].y == type2)
                        sum3+=p[k].x;
                    long long sum2=0;
                    long long sum4=0;
                    for(int l=j+1;l<=m;l++)
                    {
                        if(q[l].y == type1)
                            sum2+=q[l].x;
                        if(q[l].y == type2)
                            sum4+=q[l].x;
                        dp[k][l]=max(dp[k][l],dp[i][j]+min(sum1,sum2));
                        dp[k][l]=max(dp[k][l],dp[i][j]+min(sum3,sum4));
                    }
                }
            }
        printf("Case #%d: ",cc);
        cout<<dp[n][m]<<endl;
    }
    
    return 0;
}

