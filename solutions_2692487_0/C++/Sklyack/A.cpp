#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100;
int B[MAXN+1];

int f(int k, int n)
{
	int s, i, tw;
	tw=B[0];
	s=i=0;
	while(i<k)
		if(tw<=B[i+1])
		{
			tw+=tw-1;
			++s;
		}
		else
		{
			tw+=B[i+1];
			++i;
		}
	return s;
}

int main()
{
	int T, t;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		int n, k, ans, tmp;
		scanf("%d%d", B, &n);
		for(k=1; k<=n; ++k)
			scanf("%d", B+k);
		sort(B+1, B+1+n);
		ans=n;
		if(B[0]>1)
			for(k=1; k<=n; ++k)
			{
				tmp=n-k+f(k, n);
				if(tmp<ans)
					ans=tmp;
			}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
