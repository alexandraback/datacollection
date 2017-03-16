#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[51];
int cnt[51];

void func(int s){
	queue<int> Q;
	Q.push(s);
	
	while(!Q.empty()){
		int now = Q.front(); Q.pop();
		cnt[now]++;
		for(int i = 0; i < G[now].size(); i++){
			Q.push(G[now][i]);
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	
	for(int t = 0; t < T; t++){
		for(int i = 0; i < 51; i++){
			G[i].erase(G[i].begin(), G[i].end());
		}
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int k;
			scanf("%d", &k);
			for(int j = 0; j < k; j++){
				int a;
				scanf("%d", &a);
				G[i].push_back(a-1);
			}
		}
		bool flag = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cnt[j] = 0;
			}
			func(i);
			for(int j = 0; j < n; j++){
				if(cnt[j] >= 2){
					flag = true;
					break;
				}
			}
		}
		printf("Case #%d: ", t + 1);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}