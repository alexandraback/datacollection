//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
int vis[3000],ar[1000][100];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     freopen("B.in","r",stdin);
    freopen("out.txt","w",stdout);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        memset(vis,0,sizeof(vis));
        for(i=0;i<2*n-1;i++)
        {
            for(j=0;j<n;j++)
            {
                sn("%d",&ar[i][j]);
                vis[ar[i][j]]++;
            }
        }
        vector<int>ans;
        for(i=1;i<=2500;i++)
        {
            if(vis[i]%2==1)
                ans.pb(i);
        }
        sort(ans.begin(),ans.end());
        pf("Case #%d:",cs++);
        for(i=0;i<n;i++)
            pf(" %d",ans[i]);
        pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
