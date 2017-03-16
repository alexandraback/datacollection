#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,a,n) for(int i=(a);i<(n);i++)
#define dec(i,n) for(int i=(n);i>0;i--)
#define decc(i,a,n) for(int i=(a);i>(n);i--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
#define mem(a,b) memset((a),(b),sizeof(a))
#define clr(a) mem(a,0)
const double pi=acos(-1.0);
const int inf=10000000;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< string > VS;
typedef vector< ll > VLL;
#define eps 1e-9
//main code starts here
#define max 105
int x,y;
int main()
{
    freopen("B-small-attempt0(1).in","r",stdin);
    freopen("B-small-attempt0(1).out","w",stdout);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        printf("Case #%d: ",cas++);
        if(x>0)
        {
            rep(i,x)printf("WE");
        }
        else if(x<0)
        {
            x=-x;
            rep(i,x)printf("EW");
        }
        if(y>0)
        {
            rep(i,y)printf("SN");
        }
        else if(y<0)
        {
            y=-y;
            rep(i,y)printf("NS");
        }
        puts("");
    }
	return 0;
}
