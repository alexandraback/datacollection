/*******************************************************************
** AUTHOR   : Wenzheng jiang
** EMAIL    : jwzh.hi@gmail.com 
** OS       : ArchLinux 
** EDITER   : VIM
******************************************************************/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define pf(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,k)printf("%d %d %d %d\n",x,y,z,k)
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,k) scanf("%d%d%d%d",&x,&y,&z,&k)
typedef unsigned long long ll;
double const eps = 1e-6;
const int inf = 0x3fffffff;
const int size = 100000 + 5;

int f(ll n)
{
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }
    return cnt-1;
}
ll cal(ll r,ll x)
{
    ll a = (2*x+2*r-1)  ;
    ll b = x;
    if(f(a)+f(x) >= 18) return -1;
    return a * b;
}
bool test(ll r ,ll mid,ll t)
{
    if(cal(r,mid) < 0) return false;
    return cal(r,mid) <= t;
}
int main()
{
    int  T;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
//    cout << cal(1,707106780) << endl;
    sf(T);    
    for(int nc = 1; nc <= T; nc++){
        ll r,t;
        cin >> r >> t ;
        ll low = 1,high = t/(2*r);
        while(low < high-1){
 //           cout << low << ' ' << high << endl;
            ll mid = (low + high) / 2;
            if(test(r,mid,t)) low = mid ;
            else  high = mid - 1;
        }
        if(test(r,low+1,t)) low++;
        printf("Case #%d: %lld\n",nc,low);
    }
}

