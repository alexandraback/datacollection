/*
 E-Mail : amr.9102@gmail.com
 */

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>

using namespace std;

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-10;

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int R, C;

inline bool val(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= R || j >= C)
		return false;
	return true;
}

int N;
int n;

int arr[22];

map<int, vector<int> > sums;

#define SMALL
//#define LARGE

int main() {
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);
#endif

	cin >> N;
	for (int nn = 1; nn <= N; ++nn) {
		printf("Case #%d:\n", nn);
		sums.clear();
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int n1 = -1, n2 = -1;
		for (int i = 1; i < (1 << n); ++i) {
			int s = 0;
			for (int j = 0; j < n; ++j) {
				if ((i >> j) & 1)
					s += arr[j];
			}
			if (sums.count(s)) {
				for (int k = 0; k < sums[s].size(); ++k) {
					if ((sums[s][k] & i) == 0) {
						n1 = i, n2 = sums[s][k];
						goto done;
					}
				}
			}
			sums[s].push_back(i);
		}
		printf("Impossible\n");
		continue;
		done: bool f = 1;
		for (int j = 0; j < n; ++j) {
			if ((n1 >> j) & 1) {
				if (!f)
					printf(" ");
				f = 0;
				printf("%d", arr[j]);
			}
		}
		printf("\n");
		f = 1;
		for (int j = 0; j < n; ++j) {
			if ((n2 >> j) & 1) {
				if (!f)
					printf(" ");
				f = 0;
				printf("%d", arr[j]);
			}
		}
		printf("\n");
#ifdef SMALL
		cerr << nn << " of " << N << " is done." << endl;
#endif
#ifdef LARGE
		cerr << nn << " of " << N << " is done." << endl;
#endif
	}
	return 0;
}
