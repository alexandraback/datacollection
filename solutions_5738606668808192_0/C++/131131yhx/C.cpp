#include <bits/stdc++.h>

using namespace std;

int Now[64];

const int n = 16;

const int J = 50;

int Count = 0;

void Search(int x)
{
	if(x == n)
	{
		Now[x] = 1;
		int Ans[11];
		for(int i = 2; i <= 10; i++)
		{
			int s2 = 0, s3 = 0, s5 = 0, s7 = 0;
			for(int j = 1; j <= n; j++) s2 = (s2 * i + Now[j]) % 2, s3 = (s3 * i + Now[j]) % 3, s5 = (s5 * i + Now[j]) % 5, s7 = (s7 * i + Now[j]) % 7;
			if(s2 && s3 && s5 && s7) return;
			if(!s2) Ans[i] = 2;
			if(!s3) Ans[i] = 3;
			if(!s5) Ans[i] = 5;
			if(!s7) Ans[i] = 7;
		}
		for(int i = 1; i <= n; i++) printf("%d", Now[i]);
		for(int i = 2; i <= 10; i++) printf(" %d", Ans[i]);
		putchar('\n');
		Count++;
		if(Count == J) exit(0);
		return;
	}
	Now[x] = 0, Search(x + 1), Now[x] = 1, Search(x + 1);
}

int main()
{
	freopen("C-small.out", "w", stdout);
	Now[1] = 1;
	Search(2);
}
