/*
Author:wuhuajun
*/
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef double dd;
const int maxn=210;

int h,sum,T,n,t;
dd a[maxn],b[maxn],x[maxn],y[maxn];

void close()
{
exit(0);
}

int work(int cnt)
{
	sum = 0;
	h = 1;
	t = 1;
	while (h <= cnt && t <= cnt)
	{
		while (h <= cnt && t <= cnt && x[h] > y[t])
			t++;
		if (h > cnt || t > cnt) return sum;
		sum++;//找到了一对，
		h++;
		t++;
	}
	return sum;
}

void init()
{
//freopen("war.in","r",stdin);
//freopen("war.out","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case #%d: ",cas);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		for (int i=1;i<=n;i++)
			scanf("%lf",&b[i]);
		sort(a + 1,a + n + 1);
		sort(b + 1,b + n + 1);
		/*
		for (int i=1;i<=n;i++)
			printf("%.3lf ",a[i]);
		puts("");
		for (int i=1;i<=n;i++)
			printf("%.3lf ",b[i]);
		puts("");
		*/
		for (int i=1;i<=n;i++)
		{
			x[i] = b[i];
			y[i] = a[i];
		}
		printf("%d ",work(n));

		for (int i=1;i<=n;i++)
		{
			x[i] = a[i];
			y[i] = b[i];
		}
		printf("%d\n",n - work(n));
		/*
		for (int i=0;i<=n;i++)
		{
			for (int j=1;j<=n-i;j++)
				y[j] = b[j];
			int cnt = 0;
			for (int j=i + 1;j<=n;j++)
			{
				cnt++;
				x[cnt] = a[j];
			}
			printf("%d\n", n - i - work(n - i));//剩余的个数-b能获得的最大值
		}
		*/
		//puts("");
		//close();
	}
}

int main ()
{
	init();
	close();
	return 0;
}

