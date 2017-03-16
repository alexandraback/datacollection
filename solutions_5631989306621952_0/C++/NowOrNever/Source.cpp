#include <iostream>
#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

char str[1005];
char res[2005];
int tmp = 1000;

int main()
{
	freopen("d:\\A-small-attempt0.in", "r", stdin);
	freopen("d:\\out.out", "w", stdout);
	int n;
	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++)
	{
		cin >> str;
		int len = strlen(str);
		res[tmp] = str[0];
		int left = tmp;
		int right = tmp;
		printf("Case #%d: ", ti);
		for (int i = 1; i < len; i++)
		{
			if (str[i] >= res[left])
			{
				left--;
				res[left] = str[i];
			}
			else
			{
				right++;
				res[right] = str[i];
			}
		}
		for (int i = left; i <= right; i++)
			printf("%c", res[i]);
		printf("\n");
	}
	return 0;
}