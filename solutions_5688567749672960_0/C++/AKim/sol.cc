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

int dp[maxn];
int reverse(int u) {
	int ret = 0;
	while(u > 0) {
		ret *= 10;
		ret += u % 10;
		u /= 10;
	}
	return(ret);
}

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

	dp[1] = 1;
	for(int i = 1; i < maxn - 1; i++) {
		int nx = reverse(i);
		dp[i + 1] = min(dp[i] + 1, dp[i + 1] == 0 ? mod : dp[i + 1]);
		if(nx >= maxn) {continue;}
		dp[reverse(i)] = min(dp[i] + 1, dp[reverse(i)] == 0 ? mod : dp[reverse(i)]);
	}

	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		int u;
		scanf("%d", &u);
		printf("Case #%d: %d\n", i + 1, dp[u]);
	}

	return(0);
}

// by Kim Andrey
