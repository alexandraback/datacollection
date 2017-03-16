#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

char str[2000000+10];
char str1[2000000+10];

int x = 0;

void f(char *s, int len)
{
	char t = s[0];
	for (int i = 0; i < len-1; i++)
	{
		s[i] = s[i+1];
	}
	s[len-1] = t;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T, A, B;
	int i;
	int re = 0;
	cin >> T;
	while (T--)
	{
		memset(str, 0, sizeof(str));
		memset(str1, 0, sizeof(str1));
		re = 0;
		cin >> A >> B;
		if (B <= 10)
		{
			re = 0;
		}
		else
		{
			for (i = A; i <= B; i++)
			{
				itoa(i, str, 10);
				strcpy(str1, str);
				int l = strlen(str);
				int tmp;
				for (int j = 0; j < l-1; j++)
				{
					f(str, l);
					if (!strcmp(str, str1))
					{
						break;
					}
					// cout << str << endl;
					tmp = atoi(str);
					if (tmp <= B && tmp >= A)
					{
						// cout << tmp << endl;
						re++;
					}
				}
			}
		}
		re /= 2;
		cout << "Case #" << ++x << ": ";
		cout << re << endl;
	}
	return 0;
}

