#define maxl 1000001

#include <stdio.h>

char a[maxl];
int l, n;
bool b[maxl + 1];
int next[maxl];

inline bool isc(int k)
{
	switch (a[k])
	{
		case 'a':
			return false;
		case 'e':
			return false;
		case 'i':
			return false;
		case 'o':
			return false;
		case 'u':
			return false;
		default:
			return true;
	}
}

long long calc()
{
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		b[i] = false;
		cur += isc(i) ? 1 : 0;
	}
	for (int i = n; i <= l; i++)
	{
		b[i] = (cur == n);
		if (i < l)
		{
			cur -= isc(i - n) ? 1 : 0;
			cur += isc(i) ? 1 : 0;
		}
	}
	int last = l + 1;
	for (int i = l - 1; i >= 0; i--)
	{
		if (b[i + 1])
			last = i + 1;
		next[i] = last;
	}
	long long ans = 0;

	for (int i = 0; i <= l - n; i++)	
		ans += (l + 1) - next[i + n - 1];	

	return ans;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++)
	{		
		l = 0;
		while (true)
		{
			char c;
			scanf("%c", &c);
			if (c == ' ')
				break;
			a[l] = c;
			l++;
		}
		scanf("%d\n", &n);
		printf("Case #%d: %llu\n", i + 1, calc());
	}

	return 0;
}