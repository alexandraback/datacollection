#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

//freopen( "input.txt", "r", stdin );
//freopen( "output.txt", "w", stdout );
//fflush( stdin );
//__builtin_popcount()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000 //1 Billon
#define EPS 1e-9
#define MOD 1000000007
#define WHITE -1
#define BLACK 1
#define GRAY 2
#define PI acos(-1.0)

//int num_length( int n ) { return int( log10( n ) ) + 1; }
int gcd( int a, int b ){ return b == 0 ? a : gcd( b, a % b ); }
int lcm( int a, int b ){ return a * ( b / gcd( a, b ) ); }
//int toi( string a ){ int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
//string tos( int a ){ ostringstream st; st<<a; string ans = st.str(); return ans; }

#define FOR(i,a,b) for(int i=(a), _b=(b);i<=_b;i++)
#define DOW(i,b,a) for(int i=(b), _a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define mem(A,x) memset(A, x, sizeof A)
#define pb push_back
#define all(A) A.begin(),A.end()
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define scs(x) gets(x);
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)

long fmod( long a, long b ){
    return ( a % b + b ) % b;
}

		//U, D, L, R
int cx[] = { -1, 1,  0, 0,     1, 1, -1, -1 };
int cy[] = {  0, 0, -1, 1,     -1, 1, -1,  1 };

//ios::sync_with_stdio(0);

#define F first
#define S second
vector<vi > v;

vector<int> tsort;

int n,h;
bool vis[1004];
int ans=0,dpi=0;
void dfs(int i,int dpth){
    if(vis[i])return;
    vis[i]=1;
    for(int j=0; j<v[i].size(); j++){
        if(!vis[v[i][j]]){
            if((dpth+1)>ans){ ans=dpth+1;dpi=i;}
            dfs(v[i][j],dpth+1);
        }
    }
}

int main()
{

    int t;
    si( t );
    REP( icase, t ){
    //for(int i=1; i<=t; i++){
     v=   vector<vi > (1004);
            ans=0;dpi=0;
       int d,mx=0;
       cin>>n;
       for(int j=1; j<=n; j++){
            cin>>d;
         v[j].push_back(d);
        v[d].push_back(j);
       }
      memset(vis,0,sizeof vis);
      for(int j=1; j<=n; j++){
        if(!vis[j])
            dfs(j,1);
      }

      memset(vis,0,sizeof vis);

      dfs(dpi,1);

      cout << "Case #" << icase+1 << ": " << ans << endl;
    }
    return 0;
}

