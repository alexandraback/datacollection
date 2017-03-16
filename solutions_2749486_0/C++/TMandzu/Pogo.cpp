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

string o,s;
int T,X,Y,i,j,t;

main()
{
    freopen("text.in","r",stdin);   freopen("text.out","w",stdout);

    cin>>T;
    for (t=1;t<=T;t++)
    {
        cin>>X>>Y;
        X=-X;
        Y=-Y;
        swap(X,Y);
        s=o;

        if (abs(X))
        {
            if (X<0)
            {
                for (i=0;i<abs(X);i++)
                s+="SN";
            }else
            {
                for (i=0;i<abs(X);i++)
                s+="NS";
            }
        }
        if (abs(Y))
        {
            if (Y<0)
            {
                for (i=0;i<abs(Y);i++)
                s+="WE";
            }else
            {
                for (i=0;i<abs(Y);i++)
                s+="EW";
            }
        }

        cout<<"Case #"<<t<<": ";
        cout<<s<<endl;
    }

}
