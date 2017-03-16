#include <stdio.h>
#include <algorithm>
int n;
double su[2][1001];
bool check[1001];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test,testt,i,print,j;
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&su[0][i]);
		for(i=0;i<n;i++)
			scanf("%lf",&su[1][i]);
		std::sort(su[0],su[0]+n);
		std::sort(su[1],su[1]+n);
		printf("Case #%d: ",test);
		memset(check,0,sizeof(check));
		print=0;
		for(i=n-1;i>=0;i--){
			for(j=n-1;j>=0;j--){
				if(su[0][i]>su[1][j] && !check[j]){
					check[j]=1;
					break;
				}
			}
			if(j!=-1)
				print++;
		}
		printf("%d ",print);
		memset(check,0,sizeof(check));
		print=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(su[0][i]<su[1][j] && !check[j]){
					check[j]=1;
					break;
				}
			}
			if(j==n)
				print++;
		}
		printf("%d\n",print);
	}
	return 0;
}
