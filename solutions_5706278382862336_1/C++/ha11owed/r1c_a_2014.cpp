// -------------------------------------
// STATUS: 
// <<Problem Name>>
// -------------------------------------
#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#define _USE_MATH_DEFINES
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 1 << 30;

FILE *fin, *fout;

inline char my_readChar() { char c;	do { fscanf(fin, "%c", &c); } while(c == '\r' || c == '\n'); return c; }

// Add extra defines
//#define N 51

ll p, q;
ll sol;

ll euclid(ll a, ll b) {
	ll c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void solve(int problemIdx) {
	ll cmmdc = euclid(p, q);
	p /= cmmdc;
	q /= cmmdc;

	while(p > 1ll && q % 2ll == 0) {
		p /= 2ll;
		q /= 2ll;
	}

	printf("problem: %d   p/q=%lld/%lld\n", problemIdx, p, q);

	sol = -1ll;
	if(p == 1ll) {
		ll cnt = 0ll;
		while(q % 2ll == 0 && q != 1ll) {
			q /= 2ll;
			cnt ++;
		}

		if(q == 1ll && cnt <= 40ll) {
			sol = cnt;
		}
	}
}
	
void read(int problemIdx) {
	fscanf(fin, "%lld/%lld", &p, &q);
}

void write(int problemIdx) {
	if(sol != -1ll) {
		fprintf(fout, "%lld\n", sol);
	}
	else {
		fprintf(fout, "impossible\n", sol);
	}
}

int main(int argc, char** argv) {

	fin = fopen("input.txt", "rt");
	fout = fopen("output.txt", "wt");
	//FILE *fout = stdout;

	int problemCount;
	fscanf(fin,"%d", &problemCount);
	for(int problemIdx = 1; problemIdx <= problemCount; problemIdx++) {
		read(problemIdx);
		solve(problemIdx);
		fprintf(fout, "Case #%d: ", problemIdx);
		write(problemIdx);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
