#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream> 
#include <stack>

#pragma comment(linker, "/STACK:256000000")
using namespace std;
typedef long long ll;
template<typename T> int size(T &a) {return (int)a.size();}
template<typename T> T sqr(T a)  { return a * a; }

#define fi first
#define se second
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,a,b) for(int i=(a);i<(b); ++i)
#define REPD(i,a,b)for(int i=(b)-1;i>=a;--i)
#define _(a,b) memset((a), (b), sizeof(a))
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
#define ve vector

#define ndbg(x) 
//cout << #x << " = " << x << " ";
#define nldbg(x) 
//cout << #x << " = " << x << endl;


int solve() {
	int A, N;
	cin >> A >> N;
	ve<int> v(N);
	REP(i, 0, N) cin >> v[i];
	sort(all(v));

	int ans = N;

	REP(del, 0, N) {
		int add = 0, i = 0, cur = A;
		while(add + del < ans && i + del < N) {
			if(v[i] < cur) {
				cur += v[i];
				i++;
			} else {
				add++;
				cur += cur - 1;
			}
		}
		ans = min(ans, add + del);
	}

	return ans;
}

int main() {
#ifdef shindo
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tests;
	cin >> tests;
	REP(t, 0, tests) {
		int ans = solve();
		printf("Case #%d: %d\n", t + 1, ans);
	}
		
#ifdef shindo
//	printf("---------------\n\n%lf\n", clock() * 1e-3);
#endif

	return 0;
}           