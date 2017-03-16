#include <stdio.h>

int main(){
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	int T,cas = 1;
	int a,b,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		int ans = 0;
		for(i = a;i <= b;i++){
			int x = i;
			int t = 1;
			while (t*10 <= x)t *= 10;
			while (1)
			{
				x = (x%t)*10+x/t;
				if(x == i) break;
				if(x >= t && x > i && x <= b) ans++;
			}
		}
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}