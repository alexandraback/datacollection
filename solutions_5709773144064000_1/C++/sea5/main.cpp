#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <iomanip>
inline int Max(int a,int b)
{
    return a>b?a:b;
}
inline int Min(int a,int b)
{
    return a<b?a:b;
}
const double pi=3.1415926;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> ii;
const long double inf=1000000007;
const long double eps=1e-6;
const int maxn=1005;
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
int g[10][10],v[10][10];
int use[20];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int cas,C=1;
    scanf("%d",&cas);
    while(cas--)
    {
        double now=2.0,c,f,x;
        double ans=0;
        scanf("%lf %lf %lf",&c,&f,&x);
        while(x/now>c/now+x/(f+now))
        {
            ans+=c/now;
            now+=f;
        }
        ans+=x/now;
        printf("Case #%d: %.7lf\n",C++,ans);
    }
    return 0;
}
