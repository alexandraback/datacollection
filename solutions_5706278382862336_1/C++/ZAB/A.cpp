#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

long long P, Q;

long long gcd(long long a, long long b)
{
	return ( b == 0 ? a : gcd(b, a % b) );
}

inline void assert(bool v)
{
	if(!v) throw "ERROR";
}

void readCase()
{
	char c;
	cin >> P >> c >> Q;
	assert(c == '/');
}

int cnt(long long P, long long Q)
{
	if(P >= Q / 2) return 1;

	return cnt(P, Q / 2) + 1;
}

void solve()
{
	const string impossible = "impossible";

	long long Max = 1LL << 40;

	long long G = gcd(P, Q);
	P /= G;
	Q /= G;

	if(Q > Max || Max % Q != 0) {
		cout << impossible;
		return;
	}

	cout << cnt(P, Q);
}

int main()
{
	//string fname = "./test/A-example.in";
	//string fname = "./test/A-small-attempt0.in";
	string fname = "./test/A-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

