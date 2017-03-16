#include<stdio.h>

#define MAX 15

int a[MAX][MAX],n,m;


int check(int x,int y){
	
	int i,j,fou=1;
	
	for(i=0;i<n;i++) if(a[i][y]>a[x][y]){fou=0;break;}
	if(fou) return 1;
	fou=1;
	for(j=0;j<m;j++) if(a[x][j]>a[x][y]){fou=0;break;}
	if(fou) return 1;
	
	return 0;
}

int solve(){
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(!check(i,j)) return 0;
		}
	}
	
	return 1;
}
int main(){
	int i,t,k,j;
	
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	
	for(k=1;k<=t;k++){
		scanf("%d%d",&n,&m);
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		printf("Case #%d: ",k);
		if(solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}
