#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


int main(int argc, char **argv)
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	int t;
	int x,y;
	int i,j,k;
	int ans;
	cin >> t;
	for(int cns = 1; cns <= t; cns++)
	{
		cin >> x >> y;
		ans = 0;
		printf("Case #%d: ", cns);
		if(x > 0)
		{
			for(i = 1; ans < x; i++)
			{
				ans += i;
				cout << "E";
			}
			for(j = 0; j < (ans-x)*2; j++)
				if(j&1) cout << "W";
				else cout << "E";
			i += j;
		}
		else
		{
			for(i = 1; ans < -x; i++)
			{
				ans += i;
				cout << "W";
			}
			for(j = 0; j < (ans+x)*2; j++)
				if(j&1) cout << "E";
				else cout << "W";
			i += j;
		}
		ans = 0;
		if(y > 0)
		{
			for(; ans < y; i++)
			{
				ans += i;
				cout << "N";
			}
			for(j = 0; j < (ans-y)*2; j++)
				if(j&1) cout << "S";
				else cout << "N";
		}
		else
		{
			for(; ans < -y; i++)
			{
				ans += i;
				cout << "S";
			}
			for(j = 0; j < (ans+y)*2; j++)
				if(j&1) cout << "N";
				else cout << "S";
		}
		cout << endl;
	} 
	return 0;
}