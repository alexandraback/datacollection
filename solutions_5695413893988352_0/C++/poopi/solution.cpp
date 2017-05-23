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
#define Inf 1000000LL * 1000000 * 1000000
#define Mod 1000000007LL

int n;
string a, b;
bool mark[20][5];
int64 dp[20][5];
int64 p[20];
int way[20][5][3];

int64 ABS(int64 val){
	return val > 0 ? val : -val;
}

int mem(int idx, int st){
	if(idx == n)
		return 0;
	if(mark[idx][st])
		return dp[idx][st];
	mark[idx][st] = true;
	int64 &ref = dp[idx][st];
	if(st == 0){
		ref = Inf;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(a[idx] != '?' && a[idx] != i + '0') continue;
				if(b[idx] != '?' && b[idx] != j + '0') continue;
				int nst = i == j ? 0 : i > j ? 1 : 2;
				int64 tmp = mem(idx + 1, nst) + (i - j) * p[n - idx - 1];
				if(ABS(tmp) < ABS(ref)){
					ref = tmp;
					way[idx][st][0] = i;
					way[idx][st][1] = j;
					way[idx][st][2] = nst;
				}
			}
		}

	}
	if(st == 1){
		int t1 = a[idx] == '?' ? 0 : a[idx] - '0';
		int t2 = b[idx] == '?' ? 9 : b[idx] - '0';
		ref = mem(idx + 1, st) + (t1 - t2) * p[n - idx - 1];
		way[idx][st][0] = t1;
		way[idx][st][1] = t2;
		way[idx][st][2] = st;
	}
	if(st == 2){
		int t1 = a[idx] == '?' ? 9 : a[idx] - '0';
		int t2 = b[idx] == '?' ? 0 : b[idx] - '0';
		ref = mem(idx + 1, st) + (t1 - t2) * p[n - idx - 1];
		way[idx][st][0] = t1;
		way[idx][st][1] = t2;
		way[idx][st][2] = st;
	}
	return ref;
}

int main(){
	freopen("B-Close Match.in", "r", stdin);
	freopen("B-Close Match.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> a >> b;
		n = a.length();
		p[0] = 1;
		for(int i = 1; i < n; i++)
			p[i] = p[i - 1] * 10;
		memset(mark, false, sizeof mark);
		mem(0, 0);
		int st = 0;
		for(int idx = 0; idx < n; idx++){
			a[idx] = way[idx][st][0] + '0';
			b[idx] = way[idx][st][1] + '0';
			st = way[idx][st][2];
		}
		cout << "Case #" << ++test << ": " << a << ' ' << b << endl;
	}
	return 0;
}
