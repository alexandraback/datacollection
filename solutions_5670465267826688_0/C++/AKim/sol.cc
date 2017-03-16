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

int z[maxn], ms[5][5];

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

	ms[1][1] = 1;
	ms[1][2] = 2;
	ms[1][3] = 3;
	ms[1][4] = 4;
	ms[2][1] = 2;
	ms[2][2] = -1;
	ms[2][3] = 4;
	ms[2][4] = -3;
	ms[3][1] = 3;
	ms[3][2] = -4;
	ms[3][3] = -1;
	ms[3][4] = 2;
	ms[4][1] = 4;
	ms[4][2] = 3;
	ms[4][3] = -2;
	ms[4][4] = -1;

	int t;
	scanf("%d", &t);
	for(int q = 0; q < t; q++) {
		int l, x;
		ll xx;
		scanf("%d%I64d\n", &l, &xx);
		if(xx >= 12) {
			x = 12 + xx % 4;
		} else {
			x = xx;
		}
		for(int i = 0; i < l; i++) {
			char c = getchar();
			int val;
			if(c == 'i') val = 2;
			if(c == 'j') val = 3;
			if(c == 'k') val = 4;
			for(int f = 0; f < x; f++) {
				z[f * l + i] = val;
			}
		}
		l *= x;
		bool oki = 0, okj = 0;
		int val = 1;
		for(int i = 0; i < l; i++) {
			val = (val < 0 ? -1 : 1) * ms[abs(val)][z[i]];
			if(oki == 0 && val == 2) {
				oki = 1;
				val = 1;
			}
			if(oki && okj == 0 && val == 3) {
				okj = 1;
				val = 1;
			}
		}
		printf("Case #%d: %s\n", q + 1, ((oki && okj && val == 4) ? "YES" : "NO"));
	}

	return(0);
}

// by Kim Andrey
