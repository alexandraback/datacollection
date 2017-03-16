#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;
#define dprintf debug && printf
#define F(x,y) for(typeof((y).begin()) x = (y).begin(); x != (y).end(); ++x) 
#define CHECKREAD(x, ...) if(scanf(__VA_ARGS__) != x) { fprintf(stderr, "Failed to read on %s, %d\n", __FILE__, __LINE__); exit(1); }


const enum {SIMPLE, FOR, WHILE} mode = FOR;
bool debug = false;

void init() {
}

double bestdiff = 1e20;
string mina, minb;

void recurse(string &a, string &b, int pos) {
	if(pos == a.size()) {
		const double diff = abs(stod(a) - stod(b));
		if(diff < bestdiff) {
			bestdiff = diff;
			mina = a; minb = b;
		} else if(abs(bestdiff - diff) < 1e-5) {
			if( a < mina || (a == mina && b < minb)) {
				bestdiff = diff;
				mina = a;
				minb = b;
			}
		}
		return;
	}
	const double fac = pow(10, a.size() - pos - 1);
	if(pos > 0) {
		const double curdiff = abs(stod(a.substr(0, pos)) * fac - stod(b.substr(0, pos)) * fac) - fac;
		if(curdiff > bestdiff) return;
	}
	if(a[pos] == '?') {
		for(int i = 0; i < 10; ++i) {
			a[pos] = '0' + i;
			recurse(a, b, pos);
		}
		a[pos] = '?';
		return;
	}
	if(b[pos] == '?') {
		for(int i = 0; i < 10; ++i) {
			b[pos] = '0' + i;
			recurse(a, b, pos);
		}
		b[pos] = '?';
		return;
	}
	recurse(a,b,pos+1);
}

bool solve(int P) {
	printf("Case #%d: ", P+1);
	string a, b;
	cin >> a >> b;
	bestdiff = 1e20;
	mina = "9999999999999999999999999999999999";
	minb = "9999999999999999999999999999999999";
	recurse(a, b, 0);
	cout << mina << " " << minb << endl;
	return true;
}

int main() {
  init();
  int n = mode == SIMPLE ? 1 : 1<<30;
  if (mode == FOR) scanf("%d", &n);
  for (int i = 0; i < n && solve(i); ++i);
  return 0;
}
