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

long long ans,T,t,i,j,A,B,l;
int d[100];

bool check(long long X)
{
    int i;
    l=0;
    while (X>0)
    {
        d[l++]=X%10;
        X/=10;
    }
    for (i=0;i<l;i++)
        if (d[i]!=d[l-i-1]) return 0;
    return 1;
}

vector <long long> G;

main()
{
    freopen("text.in","r",stdin);   freopen("text.out","w",stdout);

    for (i=1;i<=10000000;i++)
    if (check(i))
    G.pb(i);

    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>A>>B;
        ans=0;
        for (j=0;DID G[j]*G[j]<=B && j<G.S;j++)
        {
            if (DID G[j]*G[j]>=A)
            if (check(DID G[j]*G[j]))
            ans++;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }

}
