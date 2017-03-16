/*
 * Amit Mandal
 * Computer Science & Engineering
 * University of Dhaka
 */


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<set>
#include<bitset>

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define INF (1<<29)
#define EPS 1e-3
#define PI acos(-1.0)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?(-(a)):(a))
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define BIG(a) memset(a,63,sizeof(a))
#define SZ(a) ((int)a.size())
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define ff first
#define ss second
#define MP make_pair

#define SF(a)  scanf("%llu",&a)
#define PF printf
#define NL puts("")

typedef  long long int LLU;

int dr [] = {1,1,0,-1,-1,-1, 0, 1};
int dc [] = {0,1,1, 1, 0,-1,-1,-1};

template< class T > T sq(T n) { return n*n; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T power(T N,T P){  return (P==0)?  1: N*power(N,P-1); }

using namespace std;
#define es(n) ((n*(n+1)*(2*n+1))/3)
#define os(n) ((n*(n+1)*(2*n+1)/6) - ((n-1)*n*(2*(n-1)+1)/3))
int main()
{
   //  READ("A-small-attempt0.in");
   //  WRITE("aout.out");
   int line,kase=1;; cin>>line;
    LLU r,t;
    while(line--){
        cin>>r>>t;
        LLU ans=r+1;
        if(r&1){
            while(es(ans)-es(r-1)<=t){
                    ans++;
            }
        }
        else{
             while(os(ans)-os(r-1)<=t){
                 ans++;
             }
        }
        printf("Case #%d: %lld\n",kase++,ans-1);
        //cout<<(ans-1)<<endl;
    }

    return 0;
}
