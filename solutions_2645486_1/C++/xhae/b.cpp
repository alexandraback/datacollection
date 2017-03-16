#include <cstdio>

long long v[10000];
int next[10000];
int e, r, n;

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		scanf("%d %d %d", &e, &r, &n);
		for(int i=0;i<n;i++) scanf("%lld", v + i);
		for(int i=0;i<n;i++)
		{
			next[i] = n;
			for(int j=i+1;j<n;j++) if(v[j] >= v[i]) { next[i] = j; break; }
		}

		long long cur = e, ans = 0;
		for(int i=0;i<n;i++)
		{
			if(next[i] == n)
			{
				ans += cur * v[i];
				cur = 0;
			}
			else
			{
				long long req = (next[i] - i) * r;
				long long useLim = e - req;
				if(useLim < 0)
				{
					ans += cur * v[i];
					cur = 0;
				}
				else if (useLim < cur)
				{
					ans += (cur - useLim) * v[i];
					cur = useLim;
				}
			}

			cur += r;
			if(cur > e) cur = e;
		}

		printf("Case #%d: %lld\n", caseN, ans);
	}

	return 0;
}
