#include <cstdio>
#include <string.h>
using namespace std;
const int NMax=20;
int N,K;
int Key[NMax][NMax];
int Start[NMax];
int Open[NMax];
int used[NMax],way[NMax];
int memo[1<<NMax];
bool dfs(int a,int ok){
	if (a==N)
		return true;
	if (memo[ok])
		return false;
	for (int i=0;i<N;i++){
		if (!used[i] && Start[Open[i]]>0){
			way[a]=i;
			Start[Open[i]]--;
			used[i]=1;
			for (int j=0;j<NMax;j++)
				Start[j]+=Key[i][j];
			if (dfs(a+1,ok|(1<<i)))
				return true;
			Start[Open[i]]++;
			for (int j=0;j<NMax;j++)
				Start[j]-=Key[i][j];
			used[i]=0;
		}
	}
	memo[ok]=1;
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int Case=0;Case<T;Case++){
		scanf("%d%d",&K,&N);
		for (int i=0;i<NMax;i++)
			Start[i]=0;
		for (int i=0;i<K;i++){
			int x;
			scanf("%d",&x);x--;
			Start[x]++;
		}
		for (int i=0;i<N;i++){
			int t,k;
			scanf("%d%d",&t,&k);t--;
			Open[i]=t;
			for (int j=0;j<NMax;j++)
				Key[i][j]=0;
			for (int j=0;j<k;j++){
				int u;
				scanf("%d",&u);u--;
				Key[i][u]++;
			}
		}
		printf("Case #%d:",Case+1);
		for (int i=0;i<N;i++)
			used[i]=0;
		for (int i=0;i<(1<<N);i++)
			memo[i]=0;
		if (dfs(0,0)){
			for (int i=0;i<N;i++)
				printf(" %d",way[i]+1);
			puts("");
		}else{
			puts(" IMPOSSIBLE");
		}
	}
	return 0;
}

