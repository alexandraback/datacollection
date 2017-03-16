#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<string>
using namespace std;

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define PI acos(-1.0)
#define SQ(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MAX_INT 2147483647
#define inf 1<<30
#define FOR(i,a,b) for(i=(a);i<=(b);i++)
#define FORV(i,a,b) for(i=(a);i>=(b);i--)
#define REP(i,n) for(i=0;i<(n);i++)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define nl printf("\n")
#define set(A,x) memset(A,x,sizeof(A))
#define in(x) scanf("%d",&x)
#define inll(x) scanf("%lld",&x)
#define LL long long
//#define LL __int64
#define MX 10000

template<class T>inline T _abs(T n){return n<0?-n:n;}
template<class T>inline T _gcd(T a, T b){return b==0?a:_gcd(b,a%b);}
template<class T>inline T _lcm(T a, T b){return a/_gcd(a,b)*b;}

int setb(int N,int pos){return N= N | (1<<pos);}
int resetb(int N,int pos){return N= N & ~(1<<pos);}
bool checkb(int N,int pos){return (bool)(N & (1<<pos));}



int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output_b_large.txt","w",stdout);
    int test,cases=0;
    int n;
    int i,j;
    in(test);
    while(test--)
    {
        in(n);
        int _count[2502]={0};
        for(i=1;i<=2*n-1;i++)
            for(j=1;j<=n;j++)
            {
                int temp;
                cin>>temp;
                _count[temp]++;
            }
        vector<int>V;
        for(i=1;i<=2500;i++)
            if(_count[i]%2==1)
                V.pb(i);
        printf("Case #%d:",++cases);
        for(i=0;i<n;i++)
            printf(" %d",V[i]);
        nl;
    }


    return 0;
}
