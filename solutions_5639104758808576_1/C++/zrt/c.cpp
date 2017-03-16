#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt;
char s[1005];
int n;
int kase;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%s",&n,s);
		int num=0,ans=0;
		for(int i=0;i<=n;i++){
			if(s[i]>'0'){
				while(num<i) num++,ans++;
				num+=s[i]-'0';
			}
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
	
	
	return 0;
}
