#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

int a[1111];

int solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = 1111;
	for (int ma = 1; ma <= 1111; ma++) {
		int cur = 0;
		for (int i = 0; i < n; i++) {
			cur += (a[i] - 1) / ma;
		}
		res = min(res,ma + cur);
	}
	return res;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	         	
	int Cases; cin >> Cases;
	
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: %d\n",Case,solve());
	}

	return 0;
}
