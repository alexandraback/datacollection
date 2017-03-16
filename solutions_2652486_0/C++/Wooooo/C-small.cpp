#include<cstdio>
#include<vector>
using namespace std;

int n, m, k, r;
int val[7];
bool chk;
void dfs(int cur, vector<int> vec, vector<int> w) {
	if(chk) return;
	if(cur == n) {
		int tot = 0;
		for(int j = 0 ; j < k ; j++) {
			for(int l = 0 ; l < vec.size() ; l++) {
				if(vec[l] == val[j]) {
					tot++;
					break;
				}
			}
		}
		if( tot == k ) {
			for(int j = 0 ; j < w.size() ; j++) printf("%d",w[j]);
			puts("");
			chk = 1;

		}
		return;
	}
	for(int i = 2 ; i <= m ; i++) {
		vector<int> temp = vec;
		for(int j = 0 ; j < vec.size() ; j++)
			temp.push_back(temp[j]*i);
		w.push_back(i);
		dfs(cur+1, temp, w);
		if(chk) return;
		w.pop_back();
	}
}
int main() {
	int t, z = 1;
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d%d", &r, &n, &m, &k);
		printf("Case #%d:\n", z++);
		for(int q = 0 ; q < r ;q++) {
			chk = false;
			for(int i = 0 ; i < k ; i++) scanf("%d", &val[i]);

			vector<int> vec;
			vec.clear();
			vec.push_back(1);
			
			dfs(0, vec, vector<int>());
		}
	}
}