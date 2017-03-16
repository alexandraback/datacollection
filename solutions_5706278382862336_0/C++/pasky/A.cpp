#define _HAS_CPP0X 0
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)

LL gcd(LL a, LL b) {
	while (b != 0) {
		LL r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool is_power_of_2(LL x) {
	while (x != 1) {
		if (x % 2 != 0) {
			return false;
		}
		x /= 2;
	}
	return true;
}

void Go() {
	LL P, Q;
	char t;
	cin >> P >> t >> Q;
	LL pq_gcd = gcd(P, Q);
	P /= pq_gcd;
	Q /= pq_gcd;
	if (!is_power_of_2(Q)) {
		cout << "impossible";
		return;
	}
	LL res = 0;	
	LL p = 1;
	while (Q > P * p) {
		p *= 2;
		res++;
	}
	if (res > 40) {
		cout << "impossible";
		return;
	}
	cout << res;
}

int main() {
	const string task = "A";
	const string folder = "gcj/2014/1c";
	const int attempt = 0;
	const bool dbg = false;


	if (dbg) {
		freopen("inp.txt", "r", stdin);
	}
	else {
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t) {
		printf("Case #%d: ", i + 1);
		Go();
		printf("\n");
	}
	return 0;
}