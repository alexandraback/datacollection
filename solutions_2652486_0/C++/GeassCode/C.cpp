#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 100010
#define LL long long
int a[110][10],res[110][10];
int N,R,M,K;
int cnt,len[110],chos[10];
int flag,idd;
int check(int ii)
{
	int i,j,k;
	int nm=1<<N;
	for(i=0;i<nm;i++){
		k=1;
	//	len[id]=0;
		for(j=0;j<N;j++){
			if(i&(1<<j)){
				k*=chos[j];
				//res[id][++len[id]]=chos[j];
			}
		}
		if(k==a[idd][ii])return 1;
	}
	return 0;
}
void dfs(int now)
{
	//if(cnt>=50)return;
	if(flag)return;
	int i;
	if(now==N){
		cnt=0;
		for(i=1;i<=K;i++){
			if(check(i)){
				cnt++;
			}
		}
		if(cnt==K){
			flag=1;
			for(i=0;i<N;i++){
				printf("%d",chos[i]);
			}
			printf("\n");
		}
		return;
	}
	for(i=2;i<=M;i++){
		chos[now]=i;
		dfs(now+1);
	}
}
int main()
{
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);
	int i,j,k;
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		scanf("%d%d%d%d",&R,&N,&M,&K);
	//	dfs(0);
		printf("Case #%d:\n",cas);
		for(j=1;j<=R;j++){
			for(i=1;i<=K;i++){
				scanf("%d",&a[j][i]);
			}
			idd=j;
			flag=0;
			dfs(0);
		}
	}
	return 0;
}
