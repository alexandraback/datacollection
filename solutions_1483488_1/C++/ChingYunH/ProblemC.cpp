#include <cstdio>
int pow[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
int a,b,ans;
bool chk[2000001];
void gen(int x)
{
	chk[x] = true;
	int count = 1,m = 1;
	while(pow[m] <= x)
		m++;
	for(int i=1;i<=m;i++)
	{
		if(x%pow[i] < pow[i-1]) continue;
		int y = (x%pow[i])*(pow[m-i]) + (x/pow[i]);
		if(y >= a && y <= b && !chk[y])
		{
			count++;
			chk[y] = true;	
		}	
	}	
	ans += count*(count-1)/2;
}
int main()
{
	freopen("inputC.in","r",stdin);
	freopen("outputC.out","w",stdout);
	int t,i,cn;
	scanf("%d",&t);
	for(cn=1;cn<=t;cn++)
	{
		scanf("%d%d",&a,&b);
		ans = 0;
		for(i=a;i<=b;i++)
			chk[i] = false;
		for(i=a;i<=b;i++)
			if(!chk[i])
				gen(i);
		printf("Case #%d: %d\n",cn,ans);
	}	
}
