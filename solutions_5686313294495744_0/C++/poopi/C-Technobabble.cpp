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

int n;
set <string> st[2];
string p[20][2];

int main(){
	freopen("C-Technobabble.in", "r", stdin);
	freopen("C-Technobabble.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> p[i][0] >> p[i][1];
		int mx = 0;
		for(int i = 0; i < (1 << n); i++){
			st[0].clear();
			st[1].clear();
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					st[0].insert(p[j][0]);
					st[1].insert(p[j][1]);
				}
			}
			int cnt = 0;
			bool ok = true;
			for(int j = 0; j < n; j++){
				if((i & (1 << j)) == 0){
					cnt++;
					if(!st[0].count(p[j][0]) || !st[1].count(p[j][1]))
						ok = false;
				}
			}
			if(ok && cnt > mx)
				mx = cnt;
		}
		cout << "Case #" << ++test << ": " << mx << endl;
	}
	return 0;
}
