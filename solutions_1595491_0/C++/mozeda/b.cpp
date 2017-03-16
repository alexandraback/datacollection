#include <cstdio>

int main()
{
	int N, I;
	scanf("%d", &N);
	for (int I=1;I<=N;++I)
	{
		int n,s,p, t;
		int ans=0;
		scanf("%d%d%d", &n, &s, &p);
		for (int i=0;i<n;++i)
		{
			scanf("%d", &t);
			if ((t+2)/3>=p) ++ans;
			else if (t>=2 && s>0 && t<=28)
				if ((t+4)/3>=p) {--s;++ans;}
		}
		printf("Case #%d: %d\n", I, ans);
	}
}
