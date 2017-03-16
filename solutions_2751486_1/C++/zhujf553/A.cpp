#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long ll;

char s[1000002];
int a[1000002], b[1000002];
int n, m;

bool isC(char c)
{
	if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c)
		return true;
	return false;
}

ll calc()
{
	int i, j, k;
	ll sum = 0;
	int len = strlen(s);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	m = 0;
	int x = 0, y = 0;
	for(i = 0 ; i <= len ; i++)
	{

		if(isC(s[i])) 
		{
			if(x == 0)
				m++, y = i;
			x++;
		}
		else 
		{
			if(x >= n)
			{
				a[m] = y;
				b[m] = i-1;
			}
			else if(x > 0)
				m--;
			x = 0;
		} 
	}
	if(m == 0) return 0;
	for(i = 1 ; i <= m ; i++)
	{
		for(j = a[i] + n - 1 ; j <= b[i] ; j++)
		{
			sum += j - n + 2;
			//if(i != 1 && j - a[i] + 1 < n) sum += b[i - 1] - n + 2;
		}
		if(i != m)
		for(j = b[i] + 1 ; j < a[i + 1] + n - 1 ; j++)
			sum += b[i] - n + 2;
		//cout << a[i] << ' ' << b[i] << endl;
	}
	for( ; j < len ; j++)
		sum += b[m] - n + 2;
	return sum;
}

int main()
{
	int T;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d\n", &T);
	for(int tt = 1 ; tt <= T ; tt++)
	{
		scanf("%s%d\n", s, &n);
		//cout << s << endl;
		printf("Case #%d: %lld\n", tt, calc());
	}
	return 0;
}
