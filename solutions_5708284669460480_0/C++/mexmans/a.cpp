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

int cnt[256];

void solve() {
	int k,l,s; cin >> k >> l >> s;
	string a,b; cin >> a >> b;
	memset(cnt,0,sizeof(cnt));
	for (int i = 0; i < k; i++) {
		cnt[a[i]]++;
	}
	int mi = l;
	for (int i = 1; i < l; i++) {
		if (b.substr(i) == b.substr(0,l - i)) {
			mi = i;
			break;
		}
	}
	int cc = 1 + (s - l) / mi;
	for (int i = 0; i < l; i++) {
		if (cnt[b[i]] == 0) cc = 0;
	}
	double p = 1.0;
	for (int i = 0; i < l; i++) {
		p *= 1.0 * cnt[b[i]] / k;
	}
	printf("%.12f\n",cc - p * (s - l + 1));
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int Cases; cin >> Cases;
	
	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		solve();
	}
	
	return 0;
}
