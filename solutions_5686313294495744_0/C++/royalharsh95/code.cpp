#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
 
using namespace std;

#define MAX 1000008
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define pb push_back
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define itr(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> lli;
typedef pair<int,pii> i3;
 
int main(){
	read; write;
	int T; cin >> T;
 
	for(int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		string x[25],y[25];
		int a[25],b[25];
		int n; cin >> n;
		map<string,int> M, N;
		for(int i=0;i<n;i++){
			cin >> x[i] >> y[i];
			M[x[i]] = 0;
			N[y[i]] = 0;
		}
		int nx = 1;
		for(map<string,int>::iterator it=M.begin();it!=M.end();it++){
			it->S = nx++;
		}
		nx = 1;
		for(map<string,int>::iterator it=N.begin();it!=N.end();it++){
			it->S = nx++;
		}
		for(int i=0;i<n;i++){
 
			a[i] = M[x[i]];
			b[i] = N[y[i]];
		}
		int dp[(1<<16)+5]={}; fill(dp,dp+(1<<n),-100000);
		dp[0] = 0;
		for(int i=0;i<(1<<n);i++){
			int L=0,R=0;
			for(int j=0;j<n;j++){
				if(((i>>j)&1)){
					L |= (1<<a[j]);
					R |= (1<<b[j]);
				}
			}
			for(int j=0;j<n;j++){
				if(!((i>>j)&1)){
					int ad = ( (L|(1<<a[j]))==L && (R|(1<<b[j]))==R );
					dp[i+(1<<j)] = max(dp[i+(1<<j)],dp[i]+ad);
				}
			}
		}
 
		cout << dp[(1<<n)-1] << endl;
	}
}