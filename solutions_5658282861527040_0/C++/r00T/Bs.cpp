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
		int a,b,k,c = 0;
		cin>>a>>b>>k;
		for(int i = 0;i<a;i++)
		{
			for(int j = 0;j<b;j++)
			{
				if((i & j) < k)
				{
					c++;
				}
			}
		}
		printf("Case #%d: %d\n",t,c);
	}
}
