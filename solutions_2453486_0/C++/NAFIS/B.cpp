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

char pp[5][5];
int is_won(char p)
{
    int a,b,c,d,x,y,z;
    c=0;
    d=0;
    for(x=0;x<4;x++)
    {
        a=0;
        b=0;
        for(y=0;y<4;y++)
        {
            if(pp[x][y]==p || pp[x][y]=='T')a++;
            if(pp[y][x]==p || pp[y][x]=='T')b++;
        }
        if(a==4 || b==4)return 1;
        if(pp[x][x]==p || pp[x][x]=='T')c++;
        if(pp[x][3-x]==p || pp[x][3-x]=='T')d++;
    }
    if(c==4 || d==4)return 1;
    return 0;
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
        for(x=0;x<4;x++)
        {
            scanf("%s",pp[x]);
            for(y=0;y<4;y++)if(pp[x][y]=='.')b++;
        }
        cout<<"Case #"<<z<<": ";
        if(is_won('X')==1)cout<<"X won";
        else if(is_won('O'))cout<<"O won";
        else if(b==0)cout<<"Draw";
        else cout<<"Game has not completed";
        cout<<endl;
    }
}
