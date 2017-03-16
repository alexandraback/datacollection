#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
#define fordn(i,a,b) for(int i=a;i>=b;i--)
#define drep(i,n) for(i=0;i<n;i++)
#define dforup(i,a,b) for(i=a;i<=b;i++)
#define dfordn(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define pb push_back
#define mp make_pair
#define fi first
#define sc second

vi val;
vector<ll> dp;
ll e,r,n;

int main() {
	int T;
	scanf("%d",&T);
	rep(t,T) {
		printf("Case #%d: ",t+1);
		scanf("%lld%lld%lld",&e,&r,&n);
		val.resize(n+1);
		dp.resize(n+1);
		rep(i,n) scanf("%d",&val[i+1]);
		dp[0]=0;
		dp[1]=e;
		forup(i,1,n-1) {
			fordn(j,i-1,1) {
				dp[i]=max(dp[i],dp[j-1]+ll(val[i])*min(e,(i-j)*r));
			}
		}
		printf("%lld\n",dp[n-1]);
	}
	return 0;
}
