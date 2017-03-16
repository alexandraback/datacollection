#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<cmath>
#include<cassert>

using namespace std;

typedef long long LL;

const int N = 100005;

int caseNo = 1;

int x , y;

void input()
{
	cin >> x >> y;
}

void solve()
{
	string ans = "";
	if (x > 0)
	{
		for (int i = 0; i < x; i ++)
			ans += "WE";
	}
	else 
	{
		for (int i = 0; i < -x; i ++)
			ans += "EW";
	}
	
	if (y > 0)
	{
		for(int i = 0; i < y ; i++)
			ans += "SN";
	}
	else 
	{
		for(int i = 0; i < -y; i++)
			ans += "NS";
	}
		

	printf("Case #%d: %s\n", caseNo ++, ans.c_str());
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		input();
		solve();
	}					
	return 0;
}

