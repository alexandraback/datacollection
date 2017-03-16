/* ***********************************************
Author        :Eopxt
Created Time  :Sun 08 May 2016 05:31:18 PM CST
File Name     :B.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int cas; scanf("%d",&cas);
    rep(cs,cas) {
        int n,a[55][55]; lld m;
        scanf("%d%lld",&n,&m);
        mem(a,0);
        rep(i,n-2)
            For(j,i+1,n-1) a[i][j]=1;
        FOR(i,n-1,2) {
            if (m>=(1LL<<(i-2))) 
            {
                a[i][n]=1;
                m-=(1LL<<(i-2));
            }
        }
        if (m>=1) {
            a[1][n]=1;
            m-=1;
        }
        printf("Case #%d: ",cs);
        if (m>0) printf("IMPOSSIBLE\n");
        else {
            printf("POSSIBLE\n");
            rep(i,n) {
                rep(j,n) printf("%d",a[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
