#include <stdio.h>
int a[10];
int chk()
{
	for(int i = 0; i < 10; i++)
		if(!a[i])
			return 0;
	return 1;
}
void add(long long x)
{
	//printf("add %lld\n", x);
	while(x)
	{
		a[x % 10] = 1;
		x /= 10;
	}
}
long long found(long long x)
{
	//printf("found %lld\n",x);
	for(int i = 0; i < 10; i++)
		a[i] = 0;
	long long ans = 0;
	while(!chk())
	{
		ans++;
		add(x * ans);
	}
	return x * ans;
}
int main()
{
	//for(int i = 1; i <= 1000000; i++)
	//	printf("%d %lld\n", i, found(i));
	//printf("%d\n",found(0));
	//printf("%d\n",found(1));
	//printf("%d\n",found(2));
	//printf("%d\n",found(11));
	//printf("%d\n",found(1692));
	int _T;
	scanf("%d",&_T);
	int x;
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%d",&x);
		printf("Case #%d: ", CAS);
		if(x == 0) puts("INSOMNIA");
		else printf("%lld\n", found(x));
	}
}