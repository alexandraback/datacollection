#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define maxn 1100
int d[maxn][maxn];
int N;

void floyd(){
	int n,m;
	memset(d,0,sizeof(d));
	scanf("%d",&N);
	int i,j,k;
	for(i=1;i<=N;i++){
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&n);
		    d[n][i]=1;
		}
	}
	for(k=1;k<=N;k++)
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				if(i!=j && j!=k) d[i][j]+=d[i][k]*d[k][j];
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int cs;
	int i,j,k;
	scanf("%d",&cs);
	for(i=1;i<=cs;i++){
		floyd();
		printf("Case #%d: ",i);
		int flag=0;
		for(j=1;j<=N;j++)
			for(k=1;k<=N;k++)
				if(j!=k && d[j][k]>1)   flag=1;
		if(flag)   printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

