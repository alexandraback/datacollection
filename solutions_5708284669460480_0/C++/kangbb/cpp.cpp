#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <deque>
using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------

#define MAXN 110

int K, L, S;
int totalcnt, maxcnt, permutation;

char key[MAXN];
char target[MAXN];
char sol[MAXN];
string sTarget;

int countNumOfSubstringInString(char *str, char *substr) {
	int count = 0;
	const char *tmp = str;
	while((tmp = strstr(tmp, substr)))
	{
	   count++;
	   tmp++;
	}
	return count;
}

void search(int n) {
	if (n == S) {
		// check answer
		sol[S] = '\0';

		int ans = countNumOfSubstringInString(sol, target);
		//printf("%s = %d\n", sol, ans);
		maxcnt = max(maxcnt, ans);
		totalcnt += ans;
		permutation++;
		return;
	}
	for (int i = 0; i < K; i++) {
		sol[n] = key[i];
		search(n + 1);
	}
}

void solve() {
	permutation = 0;
	totalcnt = 0;
	maxcnt = 0;
	search(0);


	//printf("%d %d %d  ", permutation, totalcnt, maxcnt);
	printf("%lf\n", (double) maxcnt - ((double) totalcnt / (double) permutation));
	fflush(stdout);
}

int main() {
	int cases;
	int caseid = 1;

	double tmpm, tmpd, tmph;

	freopen("input", "r", stdin);
//freopen("output", "w", stdout);
	scanf("%d", &cases);
	while (cases--) {
		printf("Case #%d: ", caseid++);
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", key);
		scanf("%s", target);

		sTarget = string(target);

		solve();
		//printf("%llu\n", DP(N));
	}
	return 0;
}

