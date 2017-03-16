#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int not_v(char x)
{
	switch(x)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': return 0;
		default: return 1;
	}
}

long long compute(int i, int last, int l)
{
	return last + 1;
}

int main()
{
	int T, t = 0;
	scanf("%d", &T);
	while (t ++ < T)
	{
		char name[1000010];
		scanf("%s", name);
		int n; 
		scanf("%d", &n);
		long long ret = 0;

		int l = strlen(name);
		int last = -1;
		int flag = 0;
		int llast = -1;
		for (int i = 0; i < l; i ++)
		{
			if (not_v(name[i]))
			{
				if (last == -1)
				{
					last = i;
				}

				if (i - last >= n - 1)
				{
					ret += compute(i, last, l);
					llast = last;
					flag = 1;
					if (i != last)
					last ++;
					else
					last = -1;
				}
				else
				{
					if (flag)
					ret += compute(i, llast, l);
				}
			}
			else
			{
				if (flag)
				{
					ret += llast + 1;
				}
				last = -1;
			}
		}
		printf("Case #%d: %lld\n", t, ret);
	}
	
}
