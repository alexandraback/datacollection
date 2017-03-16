#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;


int b;
set<vector<int>> vis;
void dfs(vector<int> in, int cur)
{
	if (vis.find(in) != vis.end())
		return;
	vis.insert(in);
	sort(in.begin(), in.end());

	b = min(b, cur + in.back());
	if (in.back() <= 3 )
	{		
		return;
	}

	for (int i = 1; i <= in.back()/2; ++i)
	{
		auto n = in;
		n.pop_back();
		n.push_back(i);
		n.push_back(in.back()-i);
		dfs(n,cur+1);
	}

}

int main()
{	

	
	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)
	{
		int n;
		
		cin >> n;
		vector<int> in(n);
		priority_queue<int> q;

		
		for (int i = 0; i < n; ++i)
		{
			cin >> in[i];
			q.push(in[i]);
		}
		int maxEat = q.top();
		int ans = 0;
		while (ans < maxEat)
		{
			int t = q.top();
			maxEat = min(maxEat, ans+t);
			if (t <= 3)
			{
				ans += t;				
				break;
			}
			q.pop();

			q.push(t/2);
			q.push(t/2 + (t&1));
			++ans;
		}
		ans = min(ans,maxEat);
		b = 999999;
		vis.clear();
		dfs(in,0);

		if (b < ans)
		{
			ans = b;
		//	for (int i = 0; i < n; ++i)		
		//		cout << in[i] << " ";			
			//printf("%d %d" , b , ans);puts("...");
		}

		printf("Case #%d: %d\n" , ++cases, ans);
	}

	return 0;
}
