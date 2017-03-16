using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>

typedef long long L;
typedef unsigned long long U;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

main()
{
	int tc;
	cin>>tc;
	for(int t = 1;t<=tc;t++)
	{
		L a,b;
		scanf("%lld/%lld",&a,&b);
		L c = b;
		while(c % 2 == 0)
			c /= 2;
		if(c != 1)
		{
			if(a%c != 0)
			{
				printf("Case #%d: impossible\n",t);
				continue;
			}
			else
			{
				a /= c;
				b /= c;
			}
		}
		while(a%2 == 0 && b%2 == 0)
		{
			a /= 2;
			b /= 2;
		}
		for(int i = 0;a > 0;i++)
		{
			if(a >= b)
			{
				printf("Case #%d: %d\n",t,i);
				break;
			}
			a *= 2;
		}
	}
}
