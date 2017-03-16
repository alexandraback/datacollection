//#pragma comment(linker, "/STACK:100000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <locale>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define rep(x, a, b) for(int (x) = (a); (x) < int(b); ++(x))
#define sci(x) scanf("%d", &(x))
#define scii(x, y) scanf("%d %d", &(x), &(y))
#define pri(x) printf("%d ", (x))
#define prii(x, y) printf("%d %d", (x), (y))
#define pril(x) printf("%d\n", (x));
#define priil(x, y) printf("%d %d\n", (x), (y));
#define Wait cin.sync(); cin.get();
#define INF 0x3F3F3F3F
#define y1 qwerty 
#define EPS 1e-6
using namespace std;
typedef long long                  ll;
typedef pair<long long, long long> pll;
typedef pair<int, int>             pii;
typedef pair<double, int>          pdi;
typedef pair<double, double>       pdd;
typedef pair<string, string>       pss;

int t, r, c, w;

int main(){
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	rep(_t, 0, t){
		scanf("%d %d %d", &r, &c, &w);
		int ans = 0;
		ans = c / w + (c % w != 0 ? 1 : 0);
		ans += w - 1;
		printf("Case #%d: %d\n", _t + 1, ans);
	}


	//printf("TIME: %.3lf\n", (long double)(clock()) / CLOCKS_PER_SEC);
	Wait 
	return 0;
}