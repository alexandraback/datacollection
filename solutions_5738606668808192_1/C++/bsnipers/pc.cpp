#include <stdio.h>

#define witness 100

int dp[15][witness][40];

int main()
{
	for(int i=2; i<=10; i++){
		for(int j=2; j<witness; j++){
			dp[i][j][0]=1;
			for(int k=1; k<35; k++)
				dp[i][j][k]=dp[i][j][k-1]*i%j;
		}
	}
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int n,j;
		scanf("%d %d",&n,&j);
		printf("Case #%d:\n",T);
		int arr[40];
		for(int i=0; i<n; i++)
			arr[i]=0;
		arr[0]=1;
		arr[n-1]=1;
		int wit[15];
		while(j--){
			bool pass=true;
			for(int i=2; i<=10; i++){
				bool fail=true;
				for(int k=2; k<witness; k++){
					int sum=0;
					for(int l=0; l<n; l++){
						sum+=(arr[l]==1?dp[i][k][l]:0);
					}
					if(sum%k==0){
						fail=false;
						wit[i]=k;
						break;
					}
				}
				if(fail){
					pass=false;
					break;
				}
			}
			if(pass){
				for(int i=n-1; i>=0; i--)
					printf("%d",arr[i]);
				for(int i=2; i<=10; i++)
					printf(" %d",wit[i]);
				puts("");
			}else{
				j++;
			}
			for(int i=1; i<n-1; i++){
				if(arr[i]==0){
					arr[i]=1;
					break;
				}else{
					arr[i]=0;
				}
			}
		}
	}
	return 0;
}
