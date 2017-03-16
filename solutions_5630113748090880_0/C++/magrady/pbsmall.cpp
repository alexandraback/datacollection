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
		for(i=0;i<m-1;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int mask=1<<(m-1);
		for(k=0;k<mask;k++){
			if(__builtin_popcount(k)!=n) continue;
			for(i=0;i<=2500;i++){
				count[i]=0;
			}
			for(i=0;i<m-1;i++){
				if(k&(1<<i)){
					for(j=0;j<n;j++){
						count[a[i][j]]++;
					}
				} else {
					for(j=0;j<n;j++){
						count[a[i][j]]--;
					}
				}
			}
			for(i=0;i<=2500;i++){
				if(count[i]<0) break;
			}
			if(i>2500){
				break;
			}
		}
		
		printf("Case #%d:",T);
		for(i=0;i<=2500;i++){
			for(j=0;j<count[i];j++){
				printf(" %d",i);
			}
		}
		puts("");
		
	}
}
