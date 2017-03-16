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

bool cmp(char a, char b)
{
    return a>b;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output_a_small.txt","w",stdout);
    int test,cases=0;
    string str;
    in(test);
    while(test--)
    {
        cin>>str;
        list<char>L;
        list<char>::iterator it;
        L.pb(str[0]);
        int len =str.length();
        for(int i=1;i<len;i++)
        {
            if(str[i]>=L.front())
                L.pf(str[i]);
            else
                L.pb(str[i]);
        }
        cout<<"Case #"<<++cases<<": ";
        for(it=L.begin();it!=L.end();it++)
            cout<<*it;
        cout<<endl;
    }


    return 0;
}
