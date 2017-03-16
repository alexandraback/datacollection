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
		int A = nextInt();
		int B = nextInt();
		vector<double> p(A);
		for (int i = 0; i < p.size(); ++i) {
			p[i] = nextDouble();
		}
		vector<double> prob(A + 1, 0);
		prob[0] = 1;
		for (int i = 1; i <= A; ++i) {
			prob[i] = prob[i - 1] * p[i - 1];
			if (prob[i] < 1e-20) {
				prob[i] = 0;
			}
		}
		double keystrokes = 1 + B + 1;
		for (int backspaces = 0; backspaces <= A; ++backspaces) {
			double curKeystrokes = prob[A - backspaces] * (backspaces + backspaces + (B - A) + 1)
				+ (1 - prob[A - backspaces]) * (backspaces + backspaces + (B - A) + 1 + B + 1);
			if (keystrokes > curKeystrokes) {
				keystrokes = curKeystrokes;
			}
		}
		printf("Case #%d: %.10lf\n", cas, keystrokes);
	}
	return 0;
}