#include <stdio.h>

bool judge(int x,int y){
	int t = 1;
	while (t*10 < x)t *= 10;
	int k = 10;
	while (k--)
	{
		x = (x%t)*10+x/t;
		if(x >= t && x == y) return true;
	}
	return false;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas = 1;
	int a,b,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		int ans = 0;
		for(i = a;i <= b;i++)
			for(j = i+1;j <= b;j++)
				if(judge(i,j))
					ans++;
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}