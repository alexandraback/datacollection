#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i,n) for((int)(i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define inf int(2e9)
#define sz(x) int((x).size())
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()

const double eps = 1e-9;
const double pi = acos(-1.0);
typedef long long ll;

int n, m, k, p[201], a[26], dp2[101][101];
string s, t;
double dp[101][101];
bool calced[101][101];
int cnt;

double calc(int pos, int len) {
	if(pos == n) return 0.0;
	if(calced[pos][len]) return dp[pos][len];
	calced[pos][len] = true;
	double res = 0.0;
	for(int i = 0; i < 26; ++i){
		if(!a[i]) continue;
		int j = len;
		char c = char(i + 'A');
		while (j > 0 && c != t[j])
			j = p[j - 1];
		if (c == t[j])  ++j;
		int delta = (j == m);
		res = res + (calc(pos + 1, j) + delta) * a[i] / k;
	}
	return dp[pos][len] = res;
}


int calc2(int pos, int len) {
	if(pos == n) return 0;
	if(calced[pos][len]) return dp2[pos][len];
	calced[pos][len] = true;
	int res = 0;
	for(int i = 0; i < 26; ++i){
		if(!a[i]) continue;
		int j = len;
		char c = char(i + 'A');
		while (j > 0 && c != t[j])
			j = p[j - 1];
		if (c == t[j])  ++j;
		int delta = (j == m);
		res = max(res, (calc2(pos + 1, j) + delta));
	}
	return dp2[pos][len] = res;
}



int main() {
	#ifdef LOCAL
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int T;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
	 	cin >> k >> m >> n;
	 	cin >> s >> t;
	 	for(int i = 0; i < k; ++i)
	 		a[s[i] - 'A']++;

	 	for(int i = 1; i < m; ++i){
	 	 	int j = p[i - 1];
	 	 	while(j && t[j] != t[i]) j = p[j - 1];
	 	 	if(t[j] == t[i]) j++;
	 	 	p[i] = j;
	 	}
	 	int q = calc2(0, 0);
	 	memset(calced, 0, sizeof calced);
	 	printf("Case #%d: %.10f\n", cs, q - calc(0, 0));
	 	memset(calced, 0, sizeof calced);
	 	for(int i = 0; i < m; ++i) p[i] = 0;
	 	memset(a, 0, sizeof a);
	}
	
	return 0; 
}