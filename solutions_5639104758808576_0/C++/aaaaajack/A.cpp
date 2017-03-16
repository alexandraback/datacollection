#include<cstdio>
#define N 1010
using namespace std;
char s[N];
int main(){
	int T,i,cs,n,ans,pre;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		scanf("%d",&n);
		scanf("%s",s);
		ans=0;
		pre=0;
		for(i=0;s[i];i++){
			if(i-pre>ans) ans=i-pre;
			pre+=s[i]-'0';
		}
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}