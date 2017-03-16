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

int n, m, k;
int64 s[100], t[100];

int main(){
	freopen("C-Hiking Deer.in", "r", stdin);
	freopen("C-Hiking Deer.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		n = 0;
		cout << "Case #" << ++test << ": ";
		cin >> k;
		for(int i = 0; i < k; i++){
			int a, b, c;
			cin >> a >> b >> c;
			for(int j = 0; j < b; j++){
				s[n] = a;
				t[n++] = c + j;
			}
		}

		int res = 0;
		if(n > 1 && (360 - s[0]) * t[0] >= (720 - s[1]) * t[1])
			res = 1;
		if(n > 1 && (360 - s[1]) * t[1] >= (720 - s[0]) * t[0])
			res = 1;
		cout << res << endl;
	}
	return 0;
}
