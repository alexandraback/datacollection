#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int T;
vector<int> vec[1008];
int N;
int rd[1008];
int main() {
	freopen("input.in", "r", stdin);
	freopen("ans.txt", "w", stdout);

	scanf("%d", &T);
	int ca = 1, tmp, nt;
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i) {
			scanf("%d", &tmp);
			vec[i].clear();
			for(int j = 0; j < tmp; ++j) {
				scanf("%d", &nt);
				vec[i].push_back(nt);
			}
		}
		
		bool yes = false;
		for(int i = 1; i <= N; ++i) {
			memset(rd, 0, sizeof(rd));
			//rd[i] = 1;
			queue<int> que;
			que.push(i);
			//rd[i]  = 1;
			while(!que.empty()) {
				int now = que.front();
				rd[now]++;
				que.pop();
				for(int j = 0; j < vec[now].size(); ++j) {
					que.push(vec[now][j]);
				}

			}
			for(int j = 0; j <= N; ++j) {
				if(rd[j] > 1) {
					yes = true;
					break;
				}
			}
		}
		printf("Case #%d: %s\n", ca, (yes ? "Yes" : "No"));

		++ca;
	}
}


