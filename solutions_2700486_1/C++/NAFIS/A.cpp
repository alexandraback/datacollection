/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
*********************************************************************************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

float dp[20001][20001];
int lx,ly,lft;
double go(int xi,int yi)
{
    //cout<<xi<<" "<<yi<<" "<<ll<<" "<<lx<<" "<<ly<<endl;
    if(xi>=lx)return 1.0;
    if(lft==xi+yi)return 0.0;
    if(dp[xi][yi]!=-1.0)return dp[xi][yi];
    dp[xi][yi]=0.0;
    if(yi==ly)return dp[xi][yi]=go(xi+1,yi);
    else
    {
        return dp[xi][yi]=(go(xi+1,yi)+go(xi,yi+1))/2.0;
    }
}
main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    int cnt,pc;
    for(z=1;z<=a;z++)
    {
        cin>>b>>c>>d;
        e=abs(c)+abs(d);
        double ret=0.0;
        f=0;
        g=0;
        for(x=0;x<e;x+=2)
        {
            if(x==0)
            {
                f=1;
                g=1;
                continue;
            }
            f=f+4;
            g+=f;
        }
        if(g>=b)goto print;
        b=b-g;
        if(b<d+1)goto print;
        if(e==0)g=1;
        else g=f+4;
        if(d==e && b<g)
            goto print;
        else if(d==e)
        {
            ret=1.0;
            goto print;
        }
        for(x=0;x<=20000;x++)for(y=0;y<=20000;y++)dp[x][y]=-1.0;
        lft=b;
        lx=d+1;
        ly=e;
        ret=go(0,0);
        print:printf("Case #%d: %.9lf\n",z,ret);
    }
}

