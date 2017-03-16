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
#define EPS 1e-9
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

#define SF(a)  scanf("%d",&a)
#define PF printf
#define NL puts("")

typedef long long int LL;

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
int item[50];
int e,r,n;
LL dp[100][100];
LL cal(int i,int prev){
    if(i>=n) return 0;
   // if(dp[i][prev] != -1) return dp[i][prev];
    LL res=0;
    for(int en=0;en<=prev;en++){
        LL temp=item[i]*en;
        int give=prev-en+r;
        if(give>e)give=e;
        LL ret=cal(i+1,give);
        //cout<<"item "<<i<<" energy "<<en<<" prev "<<prev<<" value "<<temp<<endl;
        res=max(res,ret+temp);
    }
    dp[i][prev]=res;
    return res;
}

int main()
{
  //   READ("B-small-attempt3.in");
   //  WRITE("bout9.out");
   int t; SF(t);
   int kase=1;
   while(t--){
        SF(e);SF(r);SF(n);
        for(int i=0;i<n;i++) SF(item[i]);
        SET(dp);
        LL res=cal(0,e);
        printf("Case #%d: %lld\n",kase++,res);
   }


    return 0;
}
