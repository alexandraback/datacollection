#include <cstdio>
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ++ca){
		int a,b,k,ans = 0;
		scanf("%d%d%d",&a,&b,&k);
		for(int i = 0; i < a; ++i)
			for(int j = 0; j < b; ++j)
				if((i & j) < k) ++ans;
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}

