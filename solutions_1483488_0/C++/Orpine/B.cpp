#include <cstdio>
#include <cstdlib>
using namespace std;
int tim, n, m, d[15], a[15], cnt, x, y;
int tmp[2000005], p;
void Work()
{
	cnt=0;
	for (int i=n;i<=m;i++)
	{
		++p;
		x=i;
		d[0]=0;
		while(x)
		{
			d[++d[0]]=x%10;
			x =(int)x/10;
		}
		for(int j=1;j<d[0];j++)
		{
			y=0;
			for(int k=d[0];k;k--)
				y=y*10+d[(k-j-1+d[0])%d[0]+1];
			if(y>i&&y<=m&&tmp[y]!=p)
			{
				++cnt;
				tmp[y]=p;
			}
		}
	}
	printf("%d\n", cnt);	
}
int main()
{
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	scanf("%d",&tim);
	for(int i=1;i<=tim;i++)
	{
		printf("Case #%d: ",i);
		scanf("%d%d",&n,&m);
		Work();
	}
	return 0;
}