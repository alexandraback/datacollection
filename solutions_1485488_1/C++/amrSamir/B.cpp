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
const int nSize = 110*110;
int c[nSize], f[nSize];
int w, h, H;


int neighbor(int a, int k) {
	int i = a/h;
	int j = a%h;
	i += di[k];
	j += dj[k];
	if( i >= 0 && i < w && j >= 0 && j < h)
		return i*h+j;
	return -1;
}



vector<vector<pair<int, int> > > adjList; // first is cost & second is to

bool V[nSize];
double inf = 1e9;
double d[nSize];
double dijkstraHeap(int start, int goal, int n) {
	for (int i = 0; i < n; i++)
		d[i] = inf;
	memset(V, 0, sizeof(V));
	d[start] = 0;
	priority_queue<pair<double, int> , vector<pair<double, int> > , greater<pair<double,
			int> > > Q;
	Q.push(make_pair(0.0, start));
	while (!Q.empty()) {
		pair<double, int> S = Q.top();
//		cout << "S " <<  S.first << " " << S.second << endl;
		Q.pop();
		if (V[S.second])
			continue;
		if (S.second == goal)
			return d[S.second];
		V[S.second] = 1;
		for (int i = 0; i < 4; i++) {
			int ns = neighbor(S.second,i);
//			cout << "ns " << ns << endl;
			if(ns == -1)
				continue;
			// check if possible without water
			if(V[ns])
				continue;
			if(c[ns]-f[ns] < 50)
				continue;
			if( c[ns] - f[S.second] < 50)
				continue;
			if( c[S.second] - f[ns] < 50)
				continue;
			if( c[ns] - (H-S.first*10) < 50) {
				double nh = c[ns]-50;
				pair<double, int> NS = make_pair((H-nh)/10.0,ns);
				if(nh-f[S.second] < 20)
					NS.first += 10;
				else
					NS.first += 1;
				if(d[ns] < NS.first)
					continue;
				d[ns] = NS.first;
				Q.push(NS);
				continue;
			}
			if(fabs(S.first)<1e-9) {
				pair<double, int> NS = make_pair(0,ns);
				d[ns] = NS.first;
				Q.push(NS);
				continue;
			} else {
				pair<double, int> NS = make_pair(S.first,ns);
				if((H-S.first*10)-f[S.second] < 20)
					NS.first += 10;
				else
					NS.first += 1;
				if(d[ns] < NS.first)
					continue;
				d[ns] = NS.first;
				Q.push(NS);
				continue;
			}
		}
	}
	return -1;
}

//#define SMALL
#define LARGE

int main() {
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
#endif

	cin >> N;
	for (int nn = 1; nn <= N; ++nn) {
		printf("Case #%d: ", nn);
		cin >> H >> w >> h;
		for (int i = 0; i < w; ++i) {
			for (int j = 0; j < h; ++j) {
				cin >> c[i*h+j];
			}
		}
		for (int i = 0; i < w; ++i) {
					for (int j = 0; j < h; ++j) {
						cin >> f[i*h+j];
					}
				}
		printf("%.7lf\n",dijkstraHeap(0,(h-1)+(w-1)*h,h*w));
#ifdef SMALL
		cerr << nn << " of " << N << " is done." << endl;
#endif
#ifdef LARGE
		cerr << nn << " of " << N << " is done." << endl;
#endif
	}
	return 0;
}
