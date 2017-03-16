#include <stdio.h>
#include <deque>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
deque<int> bbs, bcs;
bool chk[1011];
int F[1011];
vector<int> re[1011];
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int i1 = 1; i1 <= T; i1++){
		printf("Case #%d: ", i1);
		int n, ans = -1; scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &F[i]);
			re[F[i]].push_back(i);
		}
		for (int i = 1; i <= n; i++){
			
				int ma = -1, mb = -1;
				int bef = -1, x = i;
				int result = 0;
				bool flag = false;
				while (!chk[x]){
					result++;
					chk[x] = true;
					if (F[x] == bef){
						flag = true;
						break;
					}
					bef = x;
					x = F[x];	
				}
				if (x == i){
					ans = ans < result ? result : ans;
				}
				if (flag){
					bbs.clear();
					bcs.clear();
					bbs.push_back(x);
					bcs.push_back(0);
					while (bbs.size() != 0){
						int k = bbs.front(), c = bcs.front();
						bbs.pop_front(); bcs.pop_front();
						ma = ma < c ? c : ma;
						for (int j = 0; j < re[k].size(); j++){
							if (!chk[re[k][j]]){
								chk[re[k][j]] = true;
								bbs.push_back(re[k][j]);
								bcs.push_back(c + 1);
							}
						}
					}

					bbs.clear();
					bcs.clear();
					bbs.push_back(i);
					bcs.push_back(0);
					while (bbs.size() != 0){
						int k = bbs.front(), c = bcs.front();
						mb = mb < c ? c : mb;
						bbs.pop_front(); bcs.pop_front();
						for (int j = 0; j < re[k].size(); j++){
							if (!chk[re[k][j]]){
								chk[re[k][j]] = true;
								bbs.push_back(re[k][j]);
								bcs.push_back(c + 1);
							}
						}
					}
					result = result + ma + mb;
					ans = ans < result ? result : ans;
				}
				
				for (int l = 1; l <= n; l++) chk[l] = false;
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++){
			chk[i] = false;
			re[i].clear();
		}
	}
	return 0;
}

