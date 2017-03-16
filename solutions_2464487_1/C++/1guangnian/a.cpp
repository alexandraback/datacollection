#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
#include<string>
using namespace std;
const int MAX=2005;
const double inf=1e20;
#define  eps 1e-6
#define ll long long
#define PB push_back
#define PII pair<int,int>
#define MP(x,y) make_pair(x,y)
ll r,t;
bool check(ll x)
{
    //cout<<(double)(x*(2.0*r+2.0*x-1.0))<<endl;
    return (double)(x*(2.0*r+2.0*x-1.0))<=(double)t;
}
int main()
{
    int T;
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%lld%llld",&r,&t);
        ll l = 1LL, r = (1LL<<60),mid,res = 1LL;
        //cout<<r<<endl;
        while(l<=r)
        {
            mid = (l + r) >> 1;
            //  cout<<"mid="<<mid<<endl;
            if (check(mid))
            {
                res = mid;
                l = mid+1;
            }
            else
                r = mid - 1;
        }
        printf("Case #%d: %lld\n",cas,res);
    }
}
