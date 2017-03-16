#include <stdio.h>

char str[1005];

int main()
{
	int cas;
	int n;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("pa0.out","w",stdout);
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%d",&n);
		scanf("%s",str);
		int num=0,ans=0;
		for(int i=0; i<=n; i++){
			if(num>=i){
				num+=str[i]-'0';
			}else{
				ans++;
				num+=str[i]-'0'+1;
			}
		}
		printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}

