/*************************************************************************
    > File Name: pC.cpp
    > Author: rockwyc992
    > Mail: rockwyc992@gmail.com 
    > Created Time: 2013年04月13日 (週六) 08時45分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

int T, top,ans;
long long stack[50];
long long tmp, a, b;
char str[20];

void check1(int x)
{
	sprintf(str, "%d", x);
	for(int i=0 ; ; i++)
		if(str[i] == '\0')
		{
			for(int j=0 ; j<i ; j++)
				str[i+j] = str[i-j-1];
			str[i*2] = '\0';
			break;
		}

	sscanf(str, "%lld", &tmp);
	tmp *= tmp;
	if(tmp > 100000000000000LL)
		return;
	sprintf(str, "%lld", tmp);
	
	for(int i=0 ; ;i++)
		if(str[i] == '\0')
		{
			for(int j=0 ; j<i ; j++)
				if(str[j] != str[i-j-1])
					return;
			break;
		}
	stack[top++] = tmp;
}

void check2(int x)
{
	sprintf(str, "%d", x);
	for(int i=0 ; ; i++)
		if(str[i] == '\0')
		{
			for(int j=0 ; j<i-1 ; j++)
				str[i+j] = str[i-j-2];
			str[i*2-1] = '\0';
			break;
		}

	sscanf(str, "%lld", &tmp);
	tmp *= tmp;
	if(tmp > 100000000000000LL)
		return;
	sprintf(str, "%lld", tmp);
	
	for(int i=0 ; ;i++)
		if(str[i] == '\0')
		{
			for(int j=0 ; j<i ; j++)
				if(str[j] != str[i-j-1])
					return;
			break;
		}
	stack[top++] = tmp;
}

int main()
{
	for(int i=1 ; i<3200 ; i++)
		check1(i), check2(i);
	stack[top++] = 100000000010000LL;

	std::sort(stack, stack+top);

	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++)
	{
		ans = -1;

		scanf("%lld%lld", &a, &b);
		
		for(int i=0 ; i<top ; i++)
			if(stack[i] < a && a <= stack[i+1])
				ans = i;
		for(int i=0 ; i<top ; i++)
			if(stack[i] <= b && b < stack[i+1])
				ans = i-ans;

		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

