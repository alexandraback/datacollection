#include <cstdio>
#include <cstring>
#include <algorithm>

#define MOD  1000000007
int N, ans, use[101], path[101];
char str[101][105];
void dfs(int dep, int path[]){
	int i;
	if(dep==N){
		//check
		/*
		for(i=1;i<N;i++){
			if(str[path[i-1]][strlen (str[path[i-1]])-1]!=str[path[i]][0]){
				break;
			}
		}
		if(i==N){
			ans++;ans%=MOD;return ;
		}
		*/
		int j, len;
		char pre=str[path[0]][0];
		char alp[26]={0};
		alp[pre-'a']=1;
		for(i=0;i<N;i++){
			len=strlen(str[path[i]]);
			for(j=0;j<len;j++){
				if(!i&&!j)continue;
				if(str[path[i]][j]!=pre){
					if(alp[str[path[i]][j]-'a'])return;
					else alp[str[path[i]][j]-'a']=1;
				}
				pre=str[path[i]][j];
			}
		}
		//for(i=0;i<N;i++){printf("%s ", str[path[i]]);}puts("");
		ans++;
		ans%=MOD;
		return ;
	}
	for(i=0;i<N;i++){
		if(!use[i]){
			path[dep]=i;
			use[i]=1;
			dfs(dep+1, path);
			use[i]=0;
		}
	}

}
int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("PB.out", "w", stdout);
	
	//freopen("PB.txt", "r", stdin);
	int i, TN, j, ca=1;
	scanf("%d", &TN);
	while(TN--){
		scanf("%d", &N);
		for(i=0;i<N;i++){
			scanf("%s", str[i]);
		}
		//sort(
		ans=0;
		memset(use, 0, sizeof(use));
		dfs(0, path);
		printf("Case #%d: %d\n", ca++, ans);
	}
	return 0;
}