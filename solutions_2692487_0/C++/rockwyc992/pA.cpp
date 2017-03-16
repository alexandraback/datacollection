/*************************************************************************
    > File Name: pA.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年05月05日 (週日) 01時00分57秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T, now, n;
int num[110];
int ans, used;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++)
	{
		scanf("%d%d", &now, &n);

		for(int i=0 ; i<n ; i++)
			scanf("%d", num+i);
		
		ans = n;
		used = 0;

		std::sort(num, num+n);
		
		if(now == 1)
		{
			printf("Case #%d: %d\n", t, n);
			continue;
		}

		for(int i=0 ; i<n ;)
		{
			if(now > num[i])
			{
				now += num[i];
				i++;
			}
			else
			{
				used++;
				now = now*2- 1;
			}
			ans = min(used+n-i ,ans);
		}

		printf("Case #%d: %d\n", t, ans);
	}
	putchar('\n');
	return 0;
}

