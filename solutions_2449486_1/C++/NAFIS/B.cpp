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
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)
#define PI 3.141592653589793238462643383279502884197169399375


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){T t=bigmod(p,e/2,M);return (t*t)%M;}
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int val[101][101],ar[101][101];
void is_won(int lx,int ud,int g,int h)
{
    int a,b,c,d,x,y,z;
    if(ud==0)
    {
        a=0;
        for(x=0;x<h;x++)
        {
            a=max(a,val[lx][x]);
        }
        for(x=0;x<h;x++)ar[lx][x]=min(ar[lx][x],a);
    }
    else
    {
        a=0;
        for(x=0;x<g;x++)
        {
            a=max(a,val[x][lx]);
        }
        for(x=0;x<g;x++)ar[x][lx]=min(ar[x][lx],a);
    }
}
main()
{
    freopen("A.in","r",stdin);
    freopen("out.out","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    for(z=1;z<=a;z++)
    {
        b=0;
        cin>>g>>h;
        for(x=0;x<g;x++)
        {
            for(y=0;y<h;y++)
            {
                cin>>val[x][y];
                ar[x][y]=100;
            }
        }
        cout<<"Case #"<<z<<": ";
        for(x=0;x<g;x++)
        {
            is_won(x,0,g,h);
        }
        for(x=0;x<h;x++)
        {
            is_won(x,1,g,h);
        }
        for(x=0;x<g;x++)
        {
            for(y=0;y<h;y++)
            {
                if(ar[x][y]!=val[x][y])b++;
            }
        }
        if(b==0)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}
