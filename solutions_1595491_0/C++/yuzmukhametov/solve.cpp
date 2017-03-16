#define print(x) cerr << #x << " = " << toStr(x) << endl;
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
template<class T> string toStr(T x){stringstream ss;ss<< x; return ss.str(); } 
template<class T1,class T2>string toStr(pair<T1,T2>x){return toStr(x.first)+": "+toStr(x.second);}
template<class T> string containerToStr(T v) { string r = "["; foreach (it, v) { if (r != "[") r += ", "; r += toStr(*it); } return r + "]";}
template<class T> string toStr(vector<T>v){return containerToStr(v);} 
template<class T> string toStr(set<T> v) {return containerToStr(v);} 
template<class T1,class T2>string toStr(map<T1,T2>v){return containerToStr(v);}
int A[10000];
int N, S, p;
const int INF = 1 << 30;
int dp[200][200];
bool mark[200][200];

int rec(int l, int left) {
	if (l == N) {
		if (left == 0) return 0;
		return -INF;
	}
	if (mark[l][left]) return dp[l][left];
	mark[l][left] = true;
	int res = -INF;
	for (int i = 0; i <= 10; ++i) {
		for (int j = 0; j <= 10; ++j) {
			if (abs(i - j) > 2) continue;
			for (int k = 0; k <= 10; ++k) {
				if (i + j + k != A[l]) continue;
				if (abs(k - i) > 2) continue;
				if (abs(k - j) > 2) continue;
				int c = 0;
				if (abs(i - j) == 2 || abs(i - k) == 2 || abs(j - k) == 2) {
					c = 1;
				}
				if (left - c < 0) continue;
				int mx = max(max(i, j), k);
				int add = 0;
				if (mx >= p) add = 1;
				int t = rec(l + 1, left - c);
				if (t == -INF) continue;
				res = max(res, t + add);
			}
		}
	}
	return dp[l][left] = res;
}

void solve(int num) {
	cin >> N >> S >> p;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	memset(mark, 0, sizeof(mark));
	int ans = rec(0, S);
	printf("Case #%d: %d\n", num, ans);
}

int main() {
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
