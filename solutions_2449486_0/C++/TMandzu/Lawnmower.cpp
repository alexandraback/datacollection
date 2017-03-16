/*===============*\
|  ID: TMANDZU    |
|    LANG: C++    |
\*===============*/
//Tornike Mandzulashvili
//#pragma comment(linker,"/STACK:256000000")
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>

#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000500
#define mp make_pair
#define pb push_back
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int,int >
#define REP(i,a,n) for(i=a;i<n;i++)
#define sc scanf
#define pt printf
#define big long long
#define VI vector <int>
#define DID (long long)


using namespace std;

int d[1000][1000],A[1000],B[1000];
int i,j,N,M,maxx,T,t;
int flag;

main()
{
    freopen("text.in","r",stdin);   freopen("text.out","w",stdout);

    cin>>T;
    for (t=1;t<=T;t++)
    {
        scanf("%d %d",&N,&M);
        for (i=0;i<N;i++)
            for (j=0;j<M;j++)
            scanf("%d",&d[i][j]);

        for (i=0;i<N;i++)
        {
            maxx=0;
            for (j=0;j<M;j++)
                maxx=max(maxx,d[i][j]);
            A[i]=maxx;
        }

        for (j=0;j<M;j++)
        {
            maxx=0;
            for (i=0;i<N;i++)
            maxx=max(maxx,d[i][j]);
            B[j]=maxx;
        }

        flag=1;
        for (i=0;i<N;i++)
        for (j=0;j<M;j++)
        if (d[i][j]!=min(A[i],B[j])) flag=0;

        cout<<"Case #"<<t<<": ";

        if (flag) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
}
