#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1000010],kase=0;
int rev(int num){
	char s[10];
	int ret=0;
	sprintf(s,"%d",num);
	int len=strlen(s);
	int p=len-1;
	while(s[p]=='0') p--;
	for(int i=p;i>=0;i--){
		ret=10*ret;
		ret+=s[i]-'0';
	}
	return ret;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("b.txt","w",stdout);
	int T,n;
	scanf("%d",&T);
	for(int i=1;i<=1000000;i++) 
		dp[i]=i;
	for(int i=1;i<=1000000;i++){
		dp[i+1]=min(dp[i]+1,dp[i+1]);
		int temp=rev(i);
		dp[temp]=min(dp[i]+1,dp[temp]);
	}
	while(T--){
		scanf("%d",&n);
		printf("Case #%d: %d\n",++kase,dp[n]);
	}
	return 0;
}