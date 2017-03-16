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

const int MAXN = 10005;

int l, x;
char s[12*MAXN];

char p[128][128];
int q[128][128];

void solve() {
	x = min(x,8+x%4);
	for(int i = 1; i < x; i++) {
        for(int j = 0; j < l; j++) {
            s[i*l+j] = s[j];
        }
	}
	int n = l*x;
	s[n] = 0;

	bool I = false;
	bool J = false;
	bool K = false;
    int pp = '1';
    int qq = +1;
    for(int i = 0; i < n; i++) {
        qq = qq*q[pp][(int)s[i]];
        pp = p[pp][(int)s[i]];
        if(pp=='i' && qq==+1) {
            I = true;
        }
        if(I && pp=='k' && qq==+1) {
			J = true;
        }
    }
    if(I && J && pp=='1' && qq==-1) {
		K = true;
    }
    printf((I && J && K) ? "YES\n" : "NO\n");
}

int main() {
	p['1']['1'] = '1';
	p['1']['i'] = 'i';
	p['1']['j'] = 'j';
	p['1']['k'] = 'k';
	p['i']['1'] = 'i';
	p['i']['i'] = '1';
	p['i']['j'] = 'k';
	p['i']['k'] = 'j';
	p['j']['1'] = 'j';
	p['j']['i'] = 'k';
	p['j']['j'] = '1';
	p['j']['k'] = 'i';
	p['k']['1'] = 'k';
	p['k']['i'] = 'j';
	p['k']['j'] = 'i';
	p['k']['k'] = '1';

	q['1']['1'] = +1;
	q['1']['i'] = +1;
	q['1']['j'] = +1;
	q['1']['k'] = +1;
	q['i']['1'] = +1;
	q['i']['i'] = -1;
	q['i']['j'] = +1;
	q['i']['k'] = -1;
	q['j']['1'] = +1;
	q['j']['i'] = -1;
	q['j']['j'] = -1;
	q['j']['k'] = +1;
	q['k']['1'] = +1;
	q['k']['i'] = +1;
	q['k']['j'] = -1;
	q['k']['k'] = -1;

	freopen("C-input.in", "r", stdin);
	freopen("C-output.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++) {
        printf("Case #%d: ", c);
        scanf("%d %d", &l, &x);
        scanf("%s", s);
		solve();
	}
}
