#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=1<<29;

char str[1000010];
int cnt[1000010],dp[1000010];
int vis[26];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	vis[0]=1;vis[4]=1;vis[8]=1;
	vis[14]=1;vis[20]=1;
	int T,n,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s%d",str+1,&n);
		//int len=strlen(str+1);
		int t=0,k=n-1;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;str[i];i++){
			if(vis[str[i]-'a']){
				t=0;
			}else{
				t++;
			}
			if(t==n){
				cnt[i]=i-k;
				k=i;
			}
			else if(t>n){
				cnt[i]=1;
				k=i;
			}
		}
		dp[0]=0;
		ll ans=0;
		for(int i=1;str[i];i++){
			dp[i]=dp[i-1]+cnt[i];
			ans+=dp[i];
		}
		printf("Case #%d: %lld\n",ri++,ans);

	}
}
