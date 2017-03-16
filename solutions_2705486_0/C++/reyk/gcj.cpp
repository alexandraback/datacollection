#include<stdio.h>
#include<string.h>
#define D 521196
char dic[D][20];
char s[51];
int dp[51][6];
int n;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void solve(int p,int d,int pr){
	int m=strlen(dic[d]);
	if(p+m>n)return;
	int i;
	int res=0;
	int spr=pr;
	pr-=5;
	for(i=0;i<m;i++){
		if(s[p+i]!=dic[d][i]){
			if(i<pr+5)return;
			res++;
			pr=i;
		}
	}
	dp[p+m][max(0,pr+5-m)]=min(dp[p+m][max(0,pr+5-m)],dp[p][spr]+res);
}
int main(){
	for(int i=0;i<D;i++)scanf(" %s",dic[i]);
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		scanf(" %s",s);
		int i,j,k;
		n=strlen(s);
		for(i=0;i<=n;i++)for(j=0;j<6;j++)dp[i][j]=n;
		dp[0][0]=0;
		for(i=0;i<n;i++){
			for(j=0;j<D;j++){
				for(k=0;k<6;k++)solve(i,j,k);
			}
		}
		int ans=n;
		for(i=0;i<6;i++)ans=min(ans,dp[n][i]);
		printf("Case #%d: %d\n",di+1,ans);
	}
	return 0;
}