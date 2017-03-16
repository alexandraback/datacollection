/*************************************************************************
    > File Name: pB.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年04月27日 (週六) 09時37分27秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T;
int e, r, n;
int v;
int stack_e[10001000];
int stack_v[10001000];
int top, now;

typedef unsigned long long ull;
ull ans;

int main()
{
	scanf("%d", &T);

	for(int t=1 ; t<=T ; t++)
	{
		scanf("%d%d%d", &e, &r, &n);
		ans = top = 0;
		now = e;

		stack_v[0] = 2147483647;

		while(n--)
		{
			scanf("%d", &v);
			while(v > stack_v[top])
			{
				if(stack_e[top]+now > e)
				{
					ans -= (ull)(e-now) * (ull)stack_v[top];
					top = 0;
					now = e;
					break;
				}
				else
				{
					ans -= (ull)stack_e[top] * (ull)stack_v[top];
					now += stack_e[top];
					top--;
				}
			}

			top++;
			stack_v[top] = v;
			stack_e[top] = now;
			ans += (ull)v * (ull)now;

			now = r;
		}

		printf("Case #%d: %llu\n", t, ans);
	}
	putchar('\n');

	return 0;
}

