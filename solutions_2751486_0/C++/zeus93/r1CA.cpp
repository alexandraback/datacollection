#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000005
char s[N];
bool add[N];
bool is[256];
int main()
{
	int tcase, icase = 1;
	int n, i, j ,sum;
	int num, len;
	memset(is, 0, sizeof(is));
	is['a'] = is['i'] = is['e'] = is['o'] = is['u'] = true;
	scanf("%d", &tcase);
	while(tcase--)
	{
		scanf("%s", s);
		scanf("%d", &n);
		memset(add, 0, sizeof(add));
		len = strlen(s);
		sum = 0;
		i = j = 0;
		num = 0;
		int i1, j1;
		while(s[j])
		{
			if(is[s[j]])
			{
				num = 0;
				j++;
				continue;
			}
			if(!add[j])
			{
				num++;
				add[j] = true;
			}
			if(num == n) 
			{
				sum += len - j;
				if(!is[s[i]] && i == j - n + 1)
				{
					num--;
				}
				i++;
			}
			else
				j++;
		}
		printf("Case #%d: %d\n",icase++, sum);
	}
	return 0;
}
