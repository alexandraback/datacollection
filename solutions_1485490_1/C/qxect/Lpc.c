#include<stdio.h>
#include<string.h>

int n,m;

long long numA[200],numB[200];
long long labA[200],labB[200];
long long dp[110][110],prob[110][110];

long long max(long long a,long long b){
	if(a>b)return a;
	return b;
}
long long min(long long a,long long b){
	if(a<b)return a;
	return b;
}

long long ans(int a,int b){
	if(a==0||b==0)return dp[a][b] = 0;
	if(dp[a][b]!=-1)return dp[a][b];
	
	int i,j;
	
	long long MAX_AA,total,tem,MM;
	
	dp[a][b] = ans(a-1,b-1);
	prob[a][b] = 0;
	
	for(i=1;i<=b;i++){
		MAX_AA = ans(a-1,i);
		total = 0;
		for(j=i;j<=b;j++){
			if(labA[a]==labB[j]){
				if(j==i)total += prob[a-1][j];
				else total += numB[j];
			}
		}
		MM = min(total, numA[a]);
		tem = min(total-MM, numA[a]);
		/*if(a==2&&b==1)printf("i %d: total %lld MM %lld tem %lld\n",i,total,MM,tem);
		if(a==3&&b==2){
			printf("a-1,b (%d,%d)\n",a-1,b);
			printf("i %d: total %lld MM %lld tem %lld\n",i,total,MM,tem);
		}*/
		if(dp[a][b]<MAX_AA+MM){
			dp[a][b] = MAX_AA + MM;
			prob[a][b] = tem;
		}else if(dp[a][b]==MAX_AA + MM && tem > prob[a][b])prob[a][b] = tem;
		
	}
	/*
	printf("%d %d: %lld\n",a,b,dp[a][b]);
	*/
	return dp[a][b];
}

int main()
{
	int tn;
	
	int i,j,l;
	
	long long ANS;
	
	scanf("%d",&tn);
	for(l=1;l<=tn;l++){
		
		memset(dp,-1,sizeof(dp));
		
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&numA[i],&labA[i]);
		}
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&numB[i],&labB[i]);
		}
		ANS = -1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				ANS = max(ANS,ans(i,j));
			}
		}
		
		printf("Case #%d: %lld\n",l,ANS);
		
	}
	return 0;
}
