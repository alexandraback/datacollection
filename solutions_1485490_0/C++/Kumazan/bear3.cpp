#include<stdio.h>
#include<algorithm>
long long dp[101][101];
long long input[2][101][2],sumOfSameType[2][101][101];
main(){
	int boxcnt,giftcnt;
	int i,j,ip,jp,nowType;
	long long sum;
	long long ans;
	int cases,nowcase;
	scanf("%d",&cases);
	for(nowcase=0;nowcase<cases;nowcase++){
		scanf("%d%d",&boxcnt,&giftcnt);
		dp[boxcnt][giftcnt]=0;
		for(i=0;i<boxcnt;i++)scanf("%I64d%I64d",&input[0][i][0],&input[0][i][1]);
		for(i=0;i<boxcnt;i++){
			sumOfSameType[0][i][i+1]=sum=input[0][i][0];
			nowType=input[0][i][1];
			for(j=i+1;j<boxcnt;j++){
				if(input[0][j][1]==nowType)sum+=input[0][j][0];
				sumOfSameType[0][i][j+1]=sum;		
			}
			dp[i][giftcnt]=0;
		}
		for(i=0;i<giftcnt;i++)scanf("%I64d%I64d",&input[1][i][0],&input[1][i][1]);
		for(i=0;i<giftcnt;i++){
			sumOfSameType[1][i][i+1]=sum=input[1][i][0];
			nowType=input[1][i][1];
			for(j=i+1;j<giftcnt;j++){
				if(input[1][j][1]==nowType)sum+=input[1][j][0];
				sumOfSameType[1][i][j+1]=sum;
			}
			dp[boxcnt][i]=0;
		}
		for(i=boxcnt-1;i>=0;i--){
			for(j=giftcnt-1;j>=0;j--){
				if(input[0][i][1]!=input[1][j][1]){
					dp[i][j]=std::max(dp[i+1][j],dp[i][j+1]);
				} else {
					dp[i][j]=sum=0;
					for(ip=1;i+ip<=boxcnt;ip++){
						for(jp=1;j+jp<=giftcnt;jp++){
							sum=std::max(dp[i+ip][j+jp]+std::min(sumOfSameType[0][i][i+ip],sumOfSameType[1][j][j+jp]),sum);
						}
					}
					dp[i][j]=std::max(dp[i][j],sum);
				}
			}
		}
		ans=dp[0][0];
		printf("Case #%d: %I64d\n",nowcase+1,ans);
	}
}
