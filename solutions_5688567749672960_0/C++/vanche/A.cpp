#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> v[2];
int tc, tcn,d[1000001],n,cnt;

void solve(){
	scanf("%d", &tc);
	while (tc--){
		scanf("%d", &n);
		v[0].clear();
		v[1].clear();
		memset(d, 0, sizeof(d));

		v[0].push_back(1);
		d[1] = cnt = 1;
		
		for (int i = 0; !v[i].empty(); i ^= 1){
			v[i ^ 1].clear();
			cnt++;
			for (int j = 0; j < v[i].size(); j++){
				int cur = v[i][j];
				if (cur + 1 <= n && !d[cur + 1]){
					d[cur + 1] = cnt;
					v[i ^ 1].push_back(cur + 1);
				}
				int rev = 0;
				while (cur){
					rev *= 10;
					rev += cur % 10;
					cur /= 10;
				}
				if (rev <= n && !d[rev]){
					d[rev] = cnt;
					v[i ^ 1].push_back(rev);
				}
			}
		}

		printf("Case #%d: %d\n", ++tcn, d[n]);
	}
}

int main(void){
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}