#include<stdio.h>
#include<vector>

using namespace std;

vector<int>list[1005];
bool used[1005], flag;

void go(int x){
	
	for(int i = 0; i < list[x].size(); i++){
		if(used[list[x][i]] == 1){
			flag = true;
			return;
		}
		if(!flag){
			used[list[x][i]] = 1;
			go(list[x][i]);
		}
	}
}


int main(){
	int T, cnt;
	cnt = 0;
	scanf("%d", &T);
	while(T--){
		int N;	
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) list[i].clear();
		for(int i = 1; i <= N; i++){
			int M, t;
			scanf("%d", &M);
			for(int j = 0; j < M; j++){
				scanf("%d", &t);
				list[i].push_back(t);
			}	
		}

		flag = false;
		for(int i = 1; i <= N && flag == false; i++){
			memset(used, 0, sizeof(used));
			//flag = false;
			used[i] = 1;
			go(i);
		}
		
		printf("Case #%d: ", ++cnt);
		if(flag == true) printf("Yes\n");
		else printf("No\n");
	
	}

	return 0;
}
