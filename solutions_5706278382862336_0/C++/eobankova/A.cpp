#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define Int long long
using namespace std;
int t;
Int gcd(Int a, Int b)
{
    if(a>b) swap(a,b);
    if(a==0) return 1;
    while(a>0)
    {
        b%=a;
        if(a>b) swap(a,b);
    }
    return b;
}
bool check(Int y)
{
    while(y>1)
    {
        if(y%2) return 1;
        y/=2;
    }
    return 0;
}
int main() {
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        Int x, y;
        int ans = 1;
        scanf("%lld/%lld", &x, &y);
        Int d = gcd(x,y);
        x/=d;y/=d;
        if(x>y) ans=-1;
        else if(x<y)
            if(check(y)) ans = -1;
            else {
                while(2*x < y)
                {
                    ans++;x*=2;
                }
            }
        else ans = 0;
        if(ans<0) printf("Case #%d: impossible\n", i);
        else printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
