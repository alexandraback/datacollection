#include <cstdio>
#include <cstring>

int a[64][64];
int b[5001];
int c[64];

int main()
{
	int tn;
	scanf("%d",&tn);
	for(int ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		int nn = 2 * n - 1;
		for(int i = 0; i < nn; ++i) c[i] = 0;
		memset(b, 0, sizeof(b));
		for(int i = 0; i < nn; ++i)
			for(int j = 0; j < n; ++j)
			{
				int t;
				scanf("%d", &t);
				b[t]++;
			}
		int k = 0;
		for(int i = 1; i <= 5000; ++i)
			if(b[i]&1) c[k++] = i;
		
		printf("Case #%d: ", ti);
		for(int i = 0; i < k; ++i)
			printf("%d ", c[i]);
		printf("\n");
	}
}
