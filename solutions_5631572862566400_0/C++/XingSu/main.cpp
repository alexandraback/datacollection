#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;
int n;
int bff[15];
int buff[15];


int test2(int buff[], int n)
{
	int i;
	int curr, prev, next;
	
	for (i = 0; i < n; i++)
	{
		curr = buff[i];
		prev = buff[(i-1+n)%n];
		next = buff[(i+1)%n];
		if (prev == bff[curr] || next == bff[curr])
			continue;
		else
			return 0;
	}
	return 1;
}



int test(int mask)
{
	int cnt = 0;
	int i;
	for (i = 1; i <= n; i++) if (mask & (1<<(i-1)))
	{
		buff[cnt++] = i;
	}
	do{
		if (test2(buff, cnt))
			return cnt;
	}while (next_permutation(buff, buff+cnt));
	return -1;
}


int main()
{
	int T, cas;
	int i, ans;
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		scanf ("%d", &n);
		for (i = 1; i <= n; i++)
			scanf ("%d", &bff[i]);
		ans = 0;
		for (int i = 1; i < (1<<n); i++)
			ans = max(ans, test(i));
		printf ("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

