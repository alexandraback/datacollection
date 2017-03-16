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

#define endl '\n'

const int MAXN = 1005;

int n, a[MAXN];

void solve() {
	int L = 1, R = MAXN;
	while(L < R) {
		int M = (L+R)/2;
		bool good = false;
		for(int special = 0; special < M && !good; special++) {
            int rest = M-special;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
				cnt += (a[i]-1)/rest;
            }
            if(cnt <= special) {
                good = true;
            }
		}
		if(good) {
            R = M;
		} else {
			L = M+1;
		}
	}
	printf("%d\n", L);
}

int main() {
	freopen("B-input.in", "r", stdin);
	freopen("B-output.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++) {
        printf("Case #%d: ", c);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
			scanf("%d", a+i);
        }
		solve();
	}
}
