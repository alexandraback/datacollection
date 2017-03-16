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
LL c;
LL get(LL m,LL s)
{
    m=2*m-1;
    LL a,b,c,d,e,f,g,h,x,y,z;
    a=m*(m+1)/2ll;
    b=m/2;
    a=a-2*b*(b+1);
    b=m*(m+1)/2ll;
    b=(b*(m*2+1))/3ll;
    c=m/2;
    b=b-4*(c*(c+1)*(c*2+1))/3ll;
    a=a*2*s;
    //if(c-a<b)return c+1;
    return a+b;
}

main()
{
    LL a,b,d,e,f,g,h,x,y,z;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>a;
    for(z=1;z<=a;z++)
    {
        cin>>b>>c;
        d=1;
        e=(LL)1000;
        f=(e+d)/2;
        while(d<f)
        {
            g=get(f,b);
            if(g<=c)d=f;
            else e=f-1;
            f=(d+e)/2;
        }
        g=get(f+1,b);
        if(g<=c)f++;
        cout<<"Case #"<<z<<": "<<f<<endl;
    }
}
