#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define eps (1e-9)
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>
#define equal(a,b) (ABS(a-b)<eps)
using namespace std;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }

int dx[8]={0, 0, 1,-1, 1, 1,-1,-1};
int dy[8]={1,-1, 0, 0,-1, 1,-1, 1};
int kx[8]={1, 1,-1,-1, 2, 2,-2,-2};
int ky[8]={2,-2, 2,-2, 1,-1, 1,-1};

/////////////////////////////////////////////////////////////////////////////////////////////////////

string fileName = "C-small-attempt1";

int a[500];
int seen[2000001];
void solveSingle(int testNumber) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("Case #%d:\n", testNumber);
	memset(seen, -1, sizeof(seen));
	for (int i = 0; i < 1 << n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (i & 1 << j) sum += a[j];
		if (seen[sum] != -1) {
			vector<int> v, w;
			for (int j = 0; j < n; j++) if (i & 1 << j) v.pb(a[j]);
			for (int j = 0; j < n; j++) if (seen[sum] & 1 << j) w.pb(a[j]);

			for (int j = 0; j + 1 < v.size(); j++) printf("%d ", v[j]); printf("%d\n", v.back());
			for (int j = 0; j + 1 < w.size(); j++) printf("%d ", w[j]); printf("%d\n", w.back());
			return;
		}
		seen[sum] = i;
	}
	printf("Impossible\n");
	fflush(stdout);
}

int main() {
	freopen((fileName + ".in").c_str(), "r", stdin);
	freopen((fileName + ".out").c_str(), "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		solveSingle(t);
	}
	return 0;
}
