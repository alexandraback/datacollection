#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>



using namespace std;


int getLen(int n)
{
	int ans = 0;
	while(n)
	{
		ans++;
		n /= 10;
	}
	return ans;	
}


set<int> s;


void solve(int t)
{
	int a, b;
	scanf("%d%d", &a, &b);
	int len = getLen(a);
	int power = 1;
	for(int i = 0; i < len - 1; i++)
		power *= 10;
	int ans = 0;
	for(int i = a; i <= b; i++)
	{
		int x = i;
		while(!s.empty())
			s.erase(s.begin());
		for(int j = 0; j < len; j++)
		{
//			printf("%d\n", x);
			if(s.count(x) == 0 && i < x && x <= b)
				s.insert(x);
			x = (x % 10) * power + x / 10;
		}
		ans += s.size();
	}
	printf("Case #%d: %d\n", t + 1, ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);  
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i);
}