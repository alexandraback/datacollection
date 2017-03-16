#include <cstdio>

const int N=1005;

int n;
char s[N];

int main(){
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen(".out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%d",&n);
		scanf("%s",s);
		int sum=0,ans=0;
		for(int i=0;i<=n;i++){
			if(sum<i) ans+=i-sum,sum=i;
			sum+=s[i]-'0';
		}
		printf("Case #%d: %d\n",Case,ans);
	}
}
