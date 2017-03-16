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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 10 * 100100;


int main() {

	#ifdef SOL
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif


	int t;
	scanf("%d", &t);
	for(int q = 0; q < t; q++) {

		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		if(r > c) swap(r, c);
		bool win = 1;
		if(((r < (x + 1) / 2 || c < (x + 1) / 2 + (x + 1) % 2) && (c < (x + 1) / 2 || r < (x + 1) / 2 + (x + 1) % 2)) || (r < x && c < x) || r * c % x != 0) {
			win = 0;
		}
		if(r == 2 && x >= 4) {
			win = 0;
		}
		if(r > 2 && x >= r * 2 - 1) {
			win = 0;
		}

		printf("Case #%d: %s\n", q + 1, win ? "GABRIEL 1" : "RICHARD 0");
	}

	return(0);
}

// by Kim Andrey
