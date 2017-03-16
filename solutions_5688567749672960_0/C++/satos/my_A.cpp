#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=(b);i>=(a);i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX



int dp[1000005]={};


int main(void){
	int qn;
	scanf("%d",&qn);
	reg(qq,1,qn){
		int n;
		scanf("%d",&n);
		int ans=1;
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		reg(i,1,n){
			dp[i]=dp[i-1]+1;
			char s[100]={};
			sprintf(s,"%d",i);
			char t[100]={};
			int ls=strlen(s);
			rep(j,ls){
				t[ls-j-1]=s[j];
			}
			int p;
			sscanf(t,"%d",&p);
			//printf("%d %d\n",i,p);
			if(p>i || t[0]=='0')continue;
			dp[i]=min(dp[i],dp[p]+1);
		}
		ans=dp[n];
		
		printf("Case #%d: %d\n",qq,ans);
	}
	return 0;
}




