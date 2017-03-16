#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int maxShyness, string & s)
{
	int ret = 0;
	int currAudience = 0;
	for(int i = 0; i <= maxShyness; i++)
	{
		if(s[i] == '0') continue;
		int diff = i - currAudience;
		if(diff < 0) diff = 0;
		ret += diff;
		currAudience += diff;
		currAudience += s[i] - '0';
	}
	return ret;
}

char temp[1024];

int main()
{
	int t;
	scanf("%d",&t);
	for(int ca = 1; ca <= t; ca++)
	{
		int x;
		string s;
		scanf("%d %s",&x,temp);
		s = temp;
		int res = solve(x,s);
		printf("Case #%d: %d\n",ca,res);
	}
	return 0;
}
