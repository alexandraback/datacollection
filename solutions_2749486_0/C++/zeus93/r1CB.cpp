#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 500
int val[N];
char s[4] = {'N','S','E','W'};
int main()
{
	int xn, yn, x, y;
	int n;
	int i;
	int tcase, icase = 1;
	scanf("%d", &tcase);
	int st;
	while(tcase--)
	{
		scanf("%d%d", &x, &y);
		xn = yn = 0;
		st = 0;
		int num = 1;
		while(xn != x)
		{
			xn += num;
			if(num > 0)
			{
				val[st++] = 2;
				num += 1;
				num *= -1;
			}
			else
			{
				val[st++] = 3;
				num -= 1;
				num *= -1;
			}
		}
		if(y * num >0)
			num *= -1;
		while(yn != y)
		{
			yn += num;
			if(num > 0)
			{
				val[st++] = 0;
				num += 1;
				num *= -1;
			}
			else
			{
				val[st++] = 1;
				num -= 1;
				num *= -1;
			}
		}
		printf("Case #%d: ", icase++);
		for(i = 0; i < st; i++)
		{
			printf("%c", s[val[i]]);
		}
		printf("\n");
	}
	return 0;
}
