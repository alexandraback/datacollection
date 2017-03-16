#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1005

using namespace std;

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char s[MAXN];
	static char b[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		scanf("\n%s",s);
		int N = strlen(s);
		int last = N;
		memset(b,0,sizeof(b));
		printf("Case #%d: ",iT+1);
		while (last)
		{
			char best = 'A' - 1;
			int pos = last;
			for (int i = last-1; i >= 0; i--)
			{
				if (s[i] > best)
				{
					best = s[i];
					pos = i;
				}
			}
			printf("%c",best);
			b[pos] = 1;
			last = pos;
		}
		for (int i = 0; i < N; i++)
		{
			if (!b[i]) printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
