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
    freopen("C-small-attempt1.in","r",stdin);
    freopen("output_c_small.txt","w",stdout);
    int test,cases=0;
    int n;
    in(test);
    while(test--)
    {
        in(n);
        map<string,bool>f;
        map<string,bool>s;
        int _count=0;
        string a[1001],b[1001];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            f[a[i]]=true;
            s[b[i]]=true;
        }
        for(int i=0;i<n;i++){
            if(f.find(a[i])!=f.end() && s.find(b[i])!=f.end())
                _count++;

        }
        printf("Case #%d: %d\n",++cases,_count);
    }


    return 0;
}
