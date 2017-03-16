using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

vector<int> ar[1010];
vector<int> rar[1010];
int n;
bool cov[1010];
int num[1010];
void dfs(int i) {
	for (int j=0;j<ar[i].size();j++) {
		if (!cov[ar[i][j]]) {
			cov[ar[i][j]] = true;
			dfs(ar[i][j]);
		}
	}
}
int X;
int get(int j) {
	if (num[j] != -1) return num[j];
	int sum = 0;
	for (int i=0;i<rar[j].size();i++) {
		sum = (sum + get(rar[j][i]))%2;
	}
	return num[j] = sum;
}
int main() {
	int tc;
	int caseno = 1;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		for (int i=0;i<n;i++) {
			rar[i].clear();
			ar[i].clear();
		}
		for (int i=0;i<n;i++) {
			int m;
			scanf("%d", &m);
			for (int j=0;j<m;j++) {
				int t;
				scanf("%d", &t);
				t--;
				ar[i].push_back(t);
				rar[t].push_back(i);
			}
		}
		bool isit = false;
		for (int i=0;i<n;i++) {
			// reachability.
			memset(cov, 0, sizeof(cov));
			cov[i] = true;
			dfs(i);
			// now the number of paths.
			memset(num, -1, sizeof(num));
			X = i;
			num[X] = 1;
			for (int j=0;j<n;j++) {
			    if (j==i) continue;
			    if (cov[j] && get(j) == 0) {
					//cout << i<<" sdf "<<j<<endl;
					isit = true;
					break;
				}
			}
			if (isit) break;
		}
		if (isit) {
			printf("Case #%d: Yes\n", caseno++);
		}
		else {
			printf("Case #%d: No\n", caseno++);
		}
	}
	return 0;
}