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

const int MAX_N = 100 + 10;
int A, N;
int a[MAX_N];

int calc(int x)
{
	int ret = 0;
	int tmp = A;
	for(int i = 0; i <= x; ++ i) {
		if (tmp > a[i]) {
			tmp += a[i];
		} else {
			if (tmp == 1) return 10000;
			for( ; tmp <= a[i]; ++ ret)
				tmp += tmp - 1;
			tmp += a[i];
		}
	}
	return ret;
}

void solve(int test)
{
	printf("Case #%d: ", test);
	cin >> A >> N;
	for(int i = 0; i < N; ++ i) {
		cin >> a[i];
	}
	sort(a, a + N);
	int ret = N;
	for(int i = 0; i < N; ++ i)
		ret = min(ret, calc(i) + N - 1 - i);
	cout << ret << endl;
}

int main()
{
	//freopen("A.in", "r", stdin); freopen("A.out", "w", stdout);
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}
