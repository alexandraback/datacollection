#include <cstdio>
#include <cstring>

int main()
{
	int tn;
	scanf("%d", &tn);
	for(int ti = 1; ti <= tn; ++ti)
	{
		char p[1024];
		char ans[1024];
		scanf("%s", p);
		int n = strlen(p);
		int t = 0;
		for(int i = 0; i < n; ++i)
		{
			int maxx = 0, maxj = 0;
			for(int j = 0; j < n; ++j)
			{
				if(p[j] == '.') break;
				if(maxx <= p[j]) {maxx = p[j]; maxj = j;}
			}
			if(maxx == 0) break;
			ans[t++] = maxx;
			p[maxj] = '.';
		}
		for(int i = 0; i < n; ++i)
			if(p[i] != '.') ans[t++] = p[i];
		ans[n] = 0;
		printf("Case #%d: %s\n", ti, ans);
	}
	return 0;
}

