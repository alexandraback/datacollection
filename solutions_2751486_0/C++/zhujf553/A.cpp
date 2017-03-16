#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long ll;

char s[1000002];
int n;

bool isC(char c)
{
	if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
		return true;
	return false;
}

ll calc()
{
	ll sum = 0;
	int len = strlen(s);
	int i, j, k;
	for(i = 0 ; i < len ; i++)
		for(j = i ; j < len ; j++)
		{
			int a = 0, b = 0;
			for(k = i ; k <= j ; k++)
			{
				if(isC(s[k])) a++;
				else a = 0;
				if(a > b) b = a;
			}
			if(b >= n) sum++;
		}
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
