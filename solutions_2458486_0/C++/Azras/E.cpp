#include <cstdio>
#include <vector>
using namespace std;
bool visited[1<<20];
int keys[201];
vector<int> box[20];
int type[20];
bool finished;
int n, k;
vector<int> ans;
void DFS(int mask){
	visited[mask] = true;
	if(mask == (1 << n) - 1){
		if(!finished){
			finished = true;
			for(int i = 0; i < ans.size(); i++){
				printf("%d ", ans[i] + 1);
			}
			printf("\n");
		}
	}else{
		for(int i = 0; i < n; i++){
			if((mask & (1 << i)) == 0 && !visited[mask | (1 << i)]){
				if(keys[type[i]] > 0){
					keys[type[i]]--;
					for(int k = 0; k < box[i].size(); k++){
						keys[box[i][k]]++;
					}
					ans.push_back(i);
					DFS(mask | (1 << i));
					ans.pop_back();
					keys[type[i]]++;
					for(int k = 0; k < box[i].size(); k++){
						keys[box[i][k]]--;
					}
				}
			}
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		finished = false;
		ans.clear();
		for(int i = 0; i <= 200; i++){
			keys[i] = 0;
		}
		scanf("%d %d", &k, &n);
		for(int i = 0; i < k; i++){
			int num;
			scanf("%d", &num);
			keys[num]++;
		}
		for(int i = 0; i < n; i++){
			box[i].clear();
		}
		for(int i = 0; i < (1 << n); i++){
			visited[i] = false;
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &type[i]);
			int k;
			scanf("%d", &k);
			for(int j = 0; j < k; j++){
				int num;
				scanf("%d", &num);
				box[i].push_back(num);
			}
		}
		printf("Case #%d: ", test);
		DFS(0);
		if(!finished) printf("IMPOSSIBLE\n");
	}
	return 0;
}
