#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <limits>
using namespace std;
vector<string> v[11];
int cnt, Max;
char key[11],target[11];
int tc, tcn;

void solve(){
	scanf("%d", &tc);
	while (tc--){
		int k, l, s;
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s %s", key, target);
		for (int i = 0; i < 11; i++)
			v[i].clear();

		for (int i = 0; i < k; i++){
			string tmp = "";
			tmp.push_back(key[i]);
			v[1].push_back(tmp);
		}
		
		for (int i = 2; i <= s; i++){
			for (int j = 0; j < v[i - 1].size(); j++){
				for (int x = 0; x < k; x++){
					v[i].push_back(v[i - 1][j] + key[x]);
				}
			}
		}

		cnt = Max = 0;
		for (int i = 0; i < v[s].size(); i++){
			int bnn = 0;
			for (int j = 0; j + l - 1 < s; j++){
				int t = 1;
				for (int x = 0; x < l; x++){
					if (target[x] != v[s][i][x + j])
						t = 0;
				}
				if (t)
					bnn++;
			}
			Max = max(Max, bnn);
			cnt += bnn;
		}

		printf("Case #%d: %.10Lf\n", ++tcn, (long double)Max - (long double)cnt / (long double)v[s].size());
	}
}

int main(void){
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}