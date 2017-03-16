#include <iterator>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#endif
using namespace std;

#define SZ(v)                   (int)v.size()
#define FOR(i,a,b)				for(int i=(a);i<(b);++i)
#define rev(i,a,b)				for(int i=(b);i>=(a);--i)
#define sz(v)                   (int)v.size()
#define all(v)					v.begin(), v.end()
#define rall(v)					v.rbegin(), v.rend()
#define pb						push_back
#define mp						make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
const int OO = 1 << 28;

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
#define Nd 0
#define Ed 1
#define Sd 2
#define Wd 3

int E,R,N;
int v[11];

int dp[11][11];
int calc(int idx, int curE){
	if(idx == N)
		return 0;
	curE = (curE > E)?E:curE;
	int &ret = dp[idx][curE];
	if(ret != -1)
		return ret;
	ret = 0;
	FOR(i,0,curE+1)
		ret = max(ret, i*v[idx] + calc(idx+1,curE-i+R));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);
#endif
	int cas;
	cin >> cas;
	FOR(cs,1,cas+1){
		cin >> E >> R >> N;
		FOR(i,0,N)
			cin >> v[i];
		memset(dp,-1,sizeof dp);
		cout << "Case #" << cs <<": " << calc(0,E) << "\n";
	}
	return 0;
}




