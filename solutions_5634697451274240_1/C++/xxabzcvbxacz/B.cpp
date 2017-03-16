#include <cstdio>
#include <queue>

const int N = 14;
int dist[1<<N];

int flip(int mask, int len)
{
	int val = (mask & ((1<<len)-1));
	int v = 0;
	for (int i=1, j = (1<<(len-1)); i<(1<<len); i<<=1, j>>=1)
		if (!(val & i))
			v |= j;
	return mask - val + v;
}

void print(int mask)
{
	for (int i=1; i<(1<<N); i<<=1)
		printf("%c", (mask & i ? '-': '+'));
}

char buff[1000];

int main()
{
	/*// test
	int v = 0;
	print(v);
	printf("\n");
	v = flip(v,5);
	print(v);
	printf("\n");
	v = flip(v,3);
	print(v);
	printf("\n");
	v = flip(v,7);
	print(v);
	printf("\n");
	v = flip(v,1);
	print(v);
	printf("\n");
	v = flip(v,N);
	print(v);
	printf("\n");*/
	/*
	for (int i=0; i<(1<<N); ++i)
		dist[i] = -1;
	dist[0] = 0;
	std::queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i=1; i<=N; ++i)
		{
			int x = flip(v, i);
			if (dist[x] == -1)
			{
				dist[x] = dist[v] + 1;
				q.push(x);
			}
		}
	}
	for (int i=0; i<(1<<N); ++i)
	{
		bool was = (1&i);
		int c = 0;
		for (int j=2; j<(1<<N); j<<=1)
		{
			bool w2 = (j&i);
			if (was != w2)
				++c;
			was = w2;
		}
		if (i & (1<<(N-1)))
			++c;
		if (c != dist[i])
		{
			print(i);
			printf(" %d!=%d\n", c, dist[i]);
		}
	}*/
	int T;
	scanf("%d\n", &T);
	for (int i=0; i<T; ++i)
	{
		gets(buff);
		int c = 0;
		char was = buff[0];
		for (int j=1; buff[j] >= '+'; ++j)
		{
			if (was != buff[j])
				++c;
			was = buff[j];
		}
		printf("Case #%d: %d\n", i+1, c + (was == '-' ? 1 : 0));
	}
	return 0;
}
