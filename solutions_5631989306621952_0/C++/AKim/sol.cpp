#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;



int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int t;
	scanf("%d\n", &t);
	for(int q = 1; q <= t; q++) {
		printf("Case #%d: ", q);
		string s;
		vector<int> t;
		getline(cin, s);
		int n = s.length();
		char b = s[0];
		for(int i = 0; i < (int)s.length(); i++) {
			if(s[i] >= b) {
				t.pb(1);
				b = s[i];
			} else {
				t.pb(0);
			}
		}
		string r;
		for(int i = n - 1; i >= 0; i--) {
			if(t[i]) {
				r.pb(s[i]);
			}
		}
		for(int i = 0; i < n; i++) {
			if(!t[i]) {
				r.pb(s[i]);
			}
		}
		printf("%s\n", r.c_str());
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim
