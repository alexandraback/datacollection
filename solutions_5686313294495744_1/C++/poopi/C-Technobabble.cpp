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

int n, m, q;
map <string, int> mp[2];
bool mark[1010];
bool mat[1010][1010];
int lf[1010], rt[1010];

bool match(int idx){
	for(int i = 0; i < m; i++){
		if(mat[idx][i] && !mark[i]){
			mark[i] = true;
			if(lf[i] == -1 || match(lf[i])){
				rt[idx] = i;
				lf[i] = idx;
				return true;
			}
		}
	}
	return false;
}

int main(){
	freopen("C-Technobabble.in", "r", stdin);
	freopen("C-Technobabble.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cerr << T << endl;
		mp[0].clear();
		mp[1].clear();
		n = m = 0;
		memset(mat, false, sizeof mat);
		cin >> q;
		string a, b;
		for(int i = 0; i < q; i++){
			cin >> a >> b;
			if(!mp[0].count(a)) mp[0][a] = n++;
			if(!mp[1].count(b)) mp[1][b] = m++;
			mat[mp[0][a]][mp[1][b]] = true;
		}

		int cnt = 0;
		memset(lf, -1, sizeof lf);
		memset(rt, -1, sizeof rt);
		for(int i = 0; i < n; i++){
			memset(mark, false, sizeof mark);
			if(match(i)) cnt++;
		}
		cerr << n << ' ' << m << endl;
		cout << "Case #" << ++test << ": " << q - n - m + cnt << endl;
	}
	return 0;
}
