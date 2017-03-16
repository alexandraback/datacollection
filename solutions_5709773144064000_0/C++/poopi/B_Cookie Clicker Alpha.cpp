										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T, test = 0;
	double c, f, x;
	for(cin >> T; T--; ){
		cin >> c >> f >> x;
		double mn = x / 2;
		double elp = 0, cur = 2;
		double most = (x - c) * f / c;
		while(most >= cur){
			elp += c / cur;
			cur += f;
			mn = min(mn, elp + x / cur);
		}
		cout << setprecision(7) << fixed << "Case #" << ++test << ": " << mn << endl;
	}
	return 0;
}
