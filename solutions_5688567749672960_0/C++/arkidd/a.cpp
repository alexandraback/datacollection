#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define aetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

/////////////////////////////////////////////////////////////

int ntc;
ll n;

ll rev(ll x){
	ll temp = 0LL;
	while (x > 0LL){
		temp = (temp *10LL) + (x%10LL);
		x /=10LL;
	}
	return temp;
}

int solve(){
	if (n == 1) return 1LL;

	queue<ll> q[3];
	set<ll> vis;
	vis.clear();
	q[1].push(1LL);	

	vis.insert(1LL);

	int now = 1;
	for (int i = 1; SZ(q[now]); i++){
		//printf("i = %d, now = %d\n", i, now);
		while (SZ(q[now])){
			ll x = q[now].front();
			q[now].pop();

			//printf("i = %d, x = %lld\n", i, x);
			ll temp = x+1LL;
			if (temp == n) return i+1;
			if (vis.count(temp) == 0){
				vis.insert(temp);
				q[1-now].push(temp);
			}

			temp = rev(x);
			if (temp == n) return i+1;
			if (vis.count(temp) == 0){
				vis.insert(temp);
				q[1-now].push(temp);
			}
			//printf("SZ = %d?\n", SZ(q[now]));
		}
		now = 1-now;
	}

	return 1000000;
}

int main()
{
	scanf("%d", &ntc);
	FOR(itc, 1, ntc){
		scanf("%lld", &n);
		printf("Case #%d: %d\n", itc, solve());
	}
	return 0;
}