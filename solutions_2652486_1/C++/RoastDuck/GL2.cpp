#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int T, R, N, M, K, f2, f3, f5, f7, ans[15];

int main()
{
	srand(time(0));
	freopen("GL2.in","r",stdin);
	freopen("GL2.out","w",stdout);
	scanf("%d%d%d%d%d",&T,&R,&N,&M,&K);
	printf("Case #1:\n");
	for (int t=1;t<=R;t++)
	{
		f2=f3=f5=f7=0;
		for (int i=1;i<=K;i++)
		{
			int x;
			scanf("%d",&x);
			int t2, t3, t5, t7;
			t2=t3=t5=t7=0;
			while (x%2==0) x/=2, t2++;
			while (x%3==0) x/=3, t3++;
			while (x%5==0) x/=5, t5++;
			while (x%7==0) x/=7, t7++;
			f2=max(f2,t2);
			f3=max(f3,t3);
			f5=max(f5,t5);
			f7=max(f7,t7);
		}
		for (int i=1;i<=12;i++) ans[i]=1;
		int top(12);
		while (f7) f7--, ans[top--]=7;
		while (f5) f5--, ans[top--]=5;
		int down(top);
		while (f3) f3--, ans[down--]=3;
		int now(1);
		if (down*2>=f2)
		{
			for (int i=1;f2;i++)
			{
				ans[i]*=2, f2--;
				if (f2) ans[i]*=2, f2--;
			}
		} else
		{
			f2--;
			for (;f2 && now<=top;now++) while (f2 && ans[now]*2<=8) ans[now]*=2, f2--;
			ans[now]*=2;
		}
		for (int i=1;i<=12;i++) if (ans[i]==1) ans[i]=rand()%7+2;
		for (int i=1;i<=12;i++) printf("%d",ans[i]);
		putchar('\n');
	}
	return 0;
}

