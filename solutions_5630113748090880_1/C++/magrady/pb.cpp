#include<stdio.h>
#include<algorithm>
#include<string>
int a[50001][101];
int count[2501];
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		int n;
		scanf("%d",&n);
		int m=n+n;
		int i,j,k;
		for(i=0;i<=2500;i++){
			count[i]=0;
		}
		for(i=0;i<m-1;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				count[a[i][j]]++;
			}
		}
		printf("Case #%d:",T);
		for(i=0;i<=2500;i++){
			for(j=0;j<count[i]%2;j++){
				printf(" %d",i);
			}
		}
		puts("");
		
	}
}
