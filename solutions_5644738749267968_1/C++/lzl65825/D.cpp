#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define Eps 1e-9
using namespace std;
int T,n;
double a[1010],b[1010];
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int i;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		scanf("%d",&n);
		for (i=1;i<=n;++i)
			scanf("%lf",&a[i]);
		for (i=1;i<=n;++i)
			scanf("%lf",&b[i]);
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		int head=1,tail=n;
		int ans1=0,ans2=0,tmp=0;
		for (i=1;i<=n;++i)
		{
			while (a[i]>b[head] && head<=tail) ++head,++tmp;
			if (tmp)
				++ans1,--tmp;
			else
				--tail;
		}
		head=1,tail=n; tmp=0;
		for (i=n;i;--i)
		{
			while (a[i]<b[tail] && tail>=head) --tail,++tmp;
			if (tmp)
				--tmp;
			else
				++head,++ans2;
		}
		printf("Case #%d: %d %d\n",ii,ans1,ans2);
				
	}
	//system("pause");
	return 0;
}
