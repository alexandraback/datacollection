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

const int maxn = (int)2e5 + 10;

pair<char, bool> mat[256][256];
pair<char, bool> pref[maxn],suff[maxn];

pair<char, bool> mul(pair<char, bool> a, char b) {
	return mp(mat[a.first][b].first,a.second ^ mat[a.first][b].second);
}

pair<char, bool> mul(char b, pair<char, bool> a) {
	return mp(mat[b][a.first].first,a.second ^ mat[b][a.first].second);
}

bool solve() {
	int n; cin >> n;
	ll x; cin >> x;
	string s; cin >> s;
	string t = "#";
	if (x >= 11) {
		x -= (x - 11) / 4 * 4;
	}
	while(x--) {
		t += s;
	}
	n = sz(t) - 1;
	pref[0] = mp('1',false);
	for (int i = 1; i <= n; i++) {
		pref[i] = mul(pref[i - 1],t[i]);		
	}
	suff[n + 1] = mp('1',false);
	for (int i = n; i >= 1; i--) {
		suff[i] = mul(t[i],suff[i + 1]);
	}
	bool was = false;
	for (int i = 1; i < n; i++) {
		if (suff[i + 1] == mp('k',false) && pref[i] == mp('k',false) && was) {
			return true;
		}
		was |= pref[i] == mp('i',false);
	}
	return false;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	mat['1']['1'] = mp('1',false);
	mat['1']['i'] = mp('i',false);
	mat['1']['j'] = mp('j',false);
	mat['1']['k'] = mp('k',false);
	mat['i']['1'] = mp('i',false);
	mat['i']['i'] = mp('1',true);
	mat['i']['j'] = mp('k',false);
	mat['i']['k'] = mp('j',true);
	mat['j']['1'] = mp('j',false);
	mat['j']['i'] = mp('k',true);
	mat['j']['j'] = mp('1',true);
	mat['j']['k'] = mp('i',false);
	mat['k']['1'] = mp('k',false);
	mat['k']['i'] = mp('j',false);
	mat['k']['j'] = mp('i',true);
	mat['k']['k'] = mp('1',true);

	int Cases; cin >> Cases;

	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		puts(solve() ? "YES" : "NO");
	}

	return 0;
}
