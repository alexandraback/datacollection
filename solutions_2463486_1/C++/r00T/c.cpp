#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
#include<map>
using namespace std;

typedef long long int L;
typedef unsigned long long int U;

vector <L>v;
bool pal(L n)
{
	L r = 0,c = n;
	while(c)
	{
		r = r*10 + c%10;
		c /= 10;
	}
	if(r == n)
		return 1;
	else
		return 0;
}
main()
{
	int c = 0;
	for(L i = 1;i<10000000;i++)
	{
		if(pal(i))
		{
			if(pal(i*i))
			{
				v.push_back(i*i);
				//cout<<i<<" "<<(i*i)<<endl;
				c++;
			}
		}
	}
	//cout<<c<<endl;
	int tc;
	scanf("%d", &tc);
	for(int t =1;t<=tc;t++)
	{
	    L a,b;
	    int x = -1, y = -1;
		scanf("%lld %lld", &a, &b);
		for(int i = 0;i<=c && (x == -1 || y == -1);i++)
		{
			//cout<<v[i]<<" ";
			if(x == -1)
			{
				if(i == c)
					y = c;
				if(v[i]>=a)
					x = i;
			}
			if(y == -1)
			{
				if(i == c)
					y = c;
				if(v[i]> b)
					y = i;
			}
		}
		//cout<<endl<<x<<" "<<y<<endl;
		printf("Case #%d: %d\n",t,max(0,y-x));
	}
}
