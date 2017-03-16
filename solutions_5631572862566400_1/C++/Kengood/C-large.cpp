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


char ok( vector<int>&a, vector<int>&b)
{
	for (int i = 0 ; i < a.size()-2; ++i)
	{
		for (int j = 0; j < b.size()-2; ++j)
		{
			if (a[i] == b[j])
				return 0;
		}

	}
	return 1;
}

int main(int aN, char **aG)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{
		int n;
		cin >> n;

		vector<int> to(n);
		vector<int> from(n);

		for (int i = 0 ; i < n; ++i)
		{
			cin >> to[i];
			to[i]--;
			from[ to[i] ]  = i;
		}

		vector<bool> loopPoint(n,false);
		for (int i = 0 ; i < n; ++i)
		{
			if ( to[ to[i] ] == i)
				loopPoint[i] = true;
		}

		printf("Case #%d: " , ++cases );

        int ans = 1;
		//try all?
		vector< vector<int> > allPath;
		vector<int> endWith;
		vector<bool> ssss(n,false);
		for (int start = 0; start < n; ++start)
		{
			//if (ssss[start]) continue;

			vector<int> path;

			int cur = start;
			set<int> vis;
			while (1)
			{
				vis.insert(cur);
				path.push_back(cur);
				ssss[cur] = true;
				int next = to[cur];
				char aas = 0;
				if (vis.find(next) != vis.end())
				{
					if ( next == start )
					{
					
						ans = max(ans, (int)path.size());
						aas = 1;
					}
					if (loopPoint[next])
					{
						endWith.push_back(cur);
						allPath.push_back(path);
						ans = max(ans, (int)path.size());
						break;
					}
					else // wrong
					{
						for (int i = 0; i < path.size(); ++i)
							ssss[i] = false;
						break;
					}
					if (aas) break;
				}

				cur = next;

			}

		}

		for (int i = 0; i < allPath.size(); ++i)
		{
			for (int j = i+1; j < allPath.size(); ++j)
			{
				if (!ok(allPath[i], allPath[j])) continue;

				if (to[ endWith[i] ] == endWith[j] )
				{					
					int nnn = allPath[i].size() +  allPath[j].size() -2;
					ans = max(nnn,ans);
				}
				else if (endWith[i] != endWith[j])
				{
					int nnn = allPath[i].size() +  allPath[j].size() ;
					ans = max(nnn,ans);
				}
			}
		}


	
		cout << ans << endl;
	}

	return 0;
}

