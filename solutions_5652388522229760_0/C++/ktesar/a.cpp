#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

ll n;
int num[10];
int cnt = 0;

void fill_num(ll x) {
	while (x>0) {
		int c = x%10;
		if (num[c]==0) {
			num[c] = 1;
			cnt++;
		}
		x /= 10;
	}
}

void solve() {
	cin >> n;
	if (n==0) {
		cout << "INSOMNIA" << endl;
		return ;
	}
	cnt = 0;
	REP(i, 10) num[i] = 0;
	int i=0;
	while (cnt<10) {
		i++;
		fill_num(i*n);
	}
	cout << i*n << endl;
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
