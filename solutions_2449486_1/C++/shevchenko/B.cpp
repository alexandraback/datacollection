#include<stdio.h>

int n,m,map[100][100],rc[100],cc[100];

void process(){
	int i,j;
	for(i=0;i<n;i++){
		rc[i]=map[i][0];
		for(j=1;j<m;j++){
			if(map[i][j]>rc[i]) rc[i]=map[i][j];
		}
	}
	for(j=0;j<m;j++){
		cc[j]=map[0][j];
		for(i=1;i<n;i++){
			if(map[i][j]>cc[j]) cc[j]=map[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int x=rc[i];
			if(cc[j]<x) x=cc[j];
			if(x!=map[i][j]){
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,t;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&map[i][j]);
		printf("Case #%d: ",k);
		process();
	}
	return 0;
}