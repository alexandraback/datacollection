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

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a = i, b, cnt = 0;
		bool pm[10] = {0}, ok = 0;
		scanf("%d", &a);
		for(int j = 1; j < 1000; j++) {
			b = a * j;
			if(b == 0) {
				cnt += (pm[0] == 0);
				pm[0] = 1;
			}
			while(b) {
				cnt += (pm[b % 10] == 0);
				pm[b % 10] = 1;
				b /= 10;
			}
			if(cnt == 10) {
				ok = 1;
				printf("Case #%d: %d\n", i + 1, a * j);
				break;
			}
		}
		if(!ok) {
			printf("Case #%d: INSOMNIA\n", i + 1);
		}
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
