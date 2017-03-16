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

int a,n;
int arr[11];

int dp[1<<11][1004][11];

int calc(int msk, int sum, int curN){
	if(__builtin_popcount(msk) == curN)
		return 0;
	int &ret = dp[msk][sum][curN];
	if(ret != -1)
		return ret;
	ret= OO;
	int cur = sum + a;
	FOR(i,0,curN)
		if((msk>>i) & 1)
			cur += arr[i];
	FOR(i,0,curN){
		if((msk>>i)&1)
			continue;
		if(arr[i] >= cur)
			break;
		cur += arr[i];
		msk |= (1<<i);
	}
	if(__builtin_popcount(msk) == curN)
		return 0;
	return ret = min(calc(msk,sum + cur-1, curN), calc(msk,sum,curN-1)) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);
#endif
	int tt;
	cin >> tt;
	FOR(cs,1,tt+1){
		cin >> a >> n;
		FOR(i,0,n)
			cin >> arr[i];
		sort(arr,arr+n);
		memset(dp,-1,sizeof dp);
		cout << "Case #" << cs << ": " << calc(0,0,n) << endl;
	}
	return 0;
}




