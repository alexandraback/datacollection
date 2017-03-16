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

int d[1111],h[1111],m[1111];

int stupid() {
	int n; cin >> n;
	int e = 0;
	for (int i = 0; i < n; i++) {
		int dd,hh,mm; cin >> dd >> hh >> mm;
		for (int j = 0; j < hh; j++) {
			d[e] = dd;
			h[e] = 1;
			m[e] = mm + j;
			e++;
		}
	}
	n = e;
	if (n == 1) return 0;
	assert(n == 2);
	assert(h[0] == h[1] && h[1] == 1);
	for (int i = 0; i < 2; i++) {
		if (1LL * m[i] * (360 - d[i]) >= 1LL * m[i ^ 1] * (720 - d[i ^ 1])) return 1;
	}
	return 0;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int Cases; cin >> Cases;
	
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: %d\n",Case,stupid());
	}
	
	return 0;
}
