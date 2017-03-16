#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MP make_pair
#define PB push_back
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 1000000 + 10;
const int MAX_M = 5000;
int N, x, y;
int sum[MAX_N];
int a[MAX_N];
double comb[MAX_M][MAX_M];

void prepare()
{
	for(int i = 1; i <= 1000000; ++ i) {
		a[i] = 4 * i - 3;
		sum[i] = sum[i - 1] + a[i];
	}
	
	comb[0][0] = 1;
	for(int i = 1; i < MAX_M; ++ i) {
		comb[i][i] = 1;
		comb[i][0] = comb[i - 1][0] * 0.5;
		for(int j = 1; j < i; ++ j) {
			comb[i][j] = comb[i - 1][j - 1] + 0.5 * (comb[i - 1][j] - comb[i - 1][j - 1]);
		}
	}
}

void solve(int test)
{
	printf("Case #%d: ", test);
	cin >> N >> x >> y;
	
	int t = (abs(x) + y) / 2 + 1; // 
	if (sum[t] <= N) { // great
		printf("%.10f\n", 1.0);
		return;
	}
	if (sum[t - 1] >= N) { // cant be 
		printf("%.10f\n", 0.0);
		return;
	}
	
	int c = N - sum[t - 1]; // number of xx to put
	int cn = y + 1; // height
	int cnt = t * 2 - 1; // max height
	
	if (cn == cnt) { // in top?
		if (c == a[t]) {
			printf("%.10f\n", 1.0);
			return;
		} else {
			printf("%.10f\n", 0.0);
			return;
		}
	}
	
	if (cnt - 1 + cn <= c) {
		printf("%.10f\n", 1.0);
		return;
	}
	if (c < cn) {
		printf("%.10f\n", 0.0);
		return;
	}
	
	printf("%.10f\n", 1 - comb[c][cn - 1]);
	
	if (c >= cnt) { // two side
		int z = c - cnt + 1;
		c -= 2 * z;
		cn -= z;
	}
	//cout << c + 1 << ' ' << cn - 1 << endl;
	//printf("%.10f\n", 1 - comb[c][cn - 1]);
}

int main()
{
	//freopen("B.in", "r", stdin); freopen("B.out", "w", stdout);
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out2", "w", stdout);
	freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-attempt2.out", "w", stdout);
	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	prepare();
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}
