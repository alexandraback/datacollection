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

int a,n,mx;
int arr[103];

int dp[103][1000005];

int calc(int idx, int cur){
	if(idx == n || cur > mx)
		return 0;

	int &ret = dp[idx][cur];
	if(ret != -1)
		return ret;

	ret = OO;

	if(cur > arr[idx])
		ret = calc(idx+1, cur + arr[idx]);
	else
		ret = min(calc(idx,cur + cur-1) + 1, calc(idx+1,cur)+1);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
	freopen("out2.out", "wt", stdout);
#endif
	int tt;
	cin >> tt;
	FOR(cs,1,tt+1){
		cin >> a >> n;
		mx = 0;
		FOR(i,0,n)
			cin >> arr[i],mx=max(mx,arr[i]);
		mx++;
		sort(arr,arr+n);
		memset(dp,-1,sizeof dp);
		cout << "Case #" << cs << ": " << calc(0,a) << endl;
	}
	return 0;
}




