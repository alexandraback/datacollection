#include <cstdio>
#include <cmath>
#include <cstring>

bool pal(int x)
{
	static int a[10];
	int d;
	for(d=0; x; a[d++]=x%10,x/=10);
	for(int i=0;i<d;++i)
		if(a[d-i-1]!=a[i])  return false;
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		int a,b,cnt=0;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;++i)
		{
			if(pal(i))
			{
				int x=sqrt(i);
				if(x*x==i && pal(x))  ++cnt;
			}
		}
		printf("Case #%d: %d\n",t,cnt);
	}
	return 0;
}
