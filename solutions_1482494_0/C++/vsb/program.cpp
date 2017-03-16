#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>
using namespace std;

int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}

long long nextLong() {
	long long x;
	scanf("%I64d", &x);
	return x;
}

double nextDouble() {
	double x;
	scanf("%lf", &x);
	return x;
}

const int BUFSIZE = 1000000;
char buf[BUFSIZE + 1];
string nextString() {
	scanf("%s", buf);
	return buf;
}
string nextLine() {
	gets(buf);
	return buf;
}

int stringToInt(string s) {
	stringstream in(s);
	int x;
	in >> x;
	return x;
}

struct Point {
	typedef double T;
	T x, y;
	Point () : x(0), y(0) {}
	Point (T x, T y) : x(x), y(y) {}
	Point operator - (Point op) const { return Point(x - op.x, y - op.y); }
	Point operator + (Point op) const { return Point(x + op.x, y + op.y); }
	Point operator * (T op) const { return Point(x * op, y * op); }
	T operator * (Point op) const { return x * op.x + y * op.y; }
	T operator % (Point op) const { return x * op.y - y * op.x; }
	T length2() { return x * x + y * y; }
	double length() { return sqrt(length2()); }
};

Point nextPoint() {
	double x = nextDouble();
	double y = nextDouble();
	return Point(x, y);
}

typedef vector<vector<int> > Adj;

int main() {
	int T = nextInt();
	for (int cas = 1; cas <= T; ++cas) {
		int n = nextInt();
		vector<int> a(n);
		vector<int> b(n);
		vector<pair<int, int> > ab(n);
		vector<pair<int, int> > ba(n);
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
			b[i] = nextInt();
			ab[i] = make_pair(a[i], b[i]);
			ba[i] = make_pair(b[i], a[i]);
		}
		sort(ab.begin(), ab.end());
		sort(ba.begin(), ba.end());
		vector<pair<int, int> > v;
		for (int i = 0; i < ba.size(); ++i) {
			v.push_back(make_pair(ba[i].first, ba[i].second));
			v.push_back(make_pair(ba[i].first, ba[i].first));
		}
		int res = n;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].first > i) {
				int idx = -1;
				for (int j = v.size() - 1; j >= i; --j) {
					if (v[j].second <= i) {
						idx = j;
						break;
					}
				}
				if (idx == -1) {
					res = 2 * n + 1;
					break;
				}
				++res;
				pair<int, int> p(v[idx].second, v[idx].second);
				v.erase(v.begin() + idx);
				v.insert(v.begin() + i, p);
			}
		}
		cerr << "case = " << cas << endl;
		if (res > 2 * n) {
			printf("Case #%d: Too Bad\n", cas);
		} else {
			printf("Case #%d: %d\n", cas, res);
		}
	}
	return 0;
}