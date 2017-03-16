#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

const int MAXN = 500005;

int n, d[MAXN], h[MAXN], m[MAXN];

ll N, D[MAXN], M[MAXN];

int small1() {
	N = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < h[i]; j++) {
			D[N] = d[i];
			M[N] = m[i]+j;
			N++;
		}
	}
	
	if(N <= 1) {
		return 0;
	} else {
		ll time0 = (360-D[0])*M[0];
		ll time1 = (360-D[1])*M[1];
		if(time0 == time1) {
			return 0;
		} else {
			if(time0 > time1) {
				swap(D[0],D[1]);
				swap(M[0],M[1]);
				swap(time0,time1);
			}
			return (720-D[0])*M[0] <= time1;
		}
	}
}

int main() {
	freopen("C-input.in", "r", stdin);
	freopen("C-output.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", d+i, h+i, m+i);
		}
		printf("Case #%d: %d\n", c, small1());
	}
}
