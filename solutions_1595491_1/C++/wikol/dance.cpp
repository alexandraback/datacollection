#include <cstdio>
#include <algorithm>

using namespace std;

int T[105];
int N,S,p;

void solve(int ca)
{
	int a = 0, b = 0;
	if(p == 0)
	{
		printf("Case #%d: %d\n", ca,N);
		return;
	}
	if(p == 1)
	{
		for(int i = 0;i<N;i++)
			if(T[i])
				a++;
		printf("Case #%d: %d\n", ca,a);
		return;
	}
	for(int i = 0;i<N;i++)
	{
		if(T[i] - p >= 2*(p-1))
		{
			a++;
			continue;
		}
		if(T[i] - p >= 2*(p-2))
		{
			b++;
			continue;
		}
	}
	printf("Case #%d: %d\n", ca, a+min(b,S));
}


int main()
{
	int Z;
	scanf("%d", &Z);
	for(int i = 1;i<=Z;i++)
	{
		scanf("%d%d%d", &N, &S, &p);
		for(int j = 0;j<N;j++)
			scanf("%d", &T[j]);
		solve(i);
	}
	return 0;
}
