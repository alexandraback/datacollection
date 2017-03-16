#include <stdio.h>

int n;
char a[1000][1000], root[1000], visited[1000];

int dfs(int now){
	for(int i=0; i<n; i++)
		if(a[now][i])
			if(visited[i])
				return 1;
			else{
				visited[i] = 1;
				if(dfs(i))
					return 1;
			}
	return 0;
}

int diamond(int root){
	for(int i=0; i<n; i++)
		visited[i] = 0;
	return dfs(root);
}

int main(){
	int t;
	scanf("%d", &t);
	for(int tt=0; tt<t; tt++){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			root[i] = 1;
			for(int j=0; j<n; j++){
				a[i][j] = 0;
			}
		}
		for(int nn=0; nn<n; nn++){
			int m;
			scanf("%d", &m);
			for(int mm=0; mm<m; mm++){
				int tmp;
				scanf("%d", &tmp);
				a[tmp-1][nn] = 1;
				root[nn] = 0;
			}
		}
		int yes = 0;
		for(int i=0; i<n; i++){
			if(root[i]){
				if(diamond(i)){
					yes = 1;
					printf("Case #%d: Yes\n", tt+1);
					break;
				}
			}
		}
		if(!yes){
			printf("Case #%d: No\n", tt+1);
		}
	}
	return 0;
}
