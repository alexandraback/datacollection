#include <cstdio>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;


int main(void)
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);

	int t ;
	scanf("%d", &t);

	for (int q = 1; q <= t; q++)
	{
		int n;
		vector<string> v;
		char s[105];
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &s);
			v.push_back((string)s);
		}
		vector<int> tmp;
		for (int i = 0; i < n; i++)
			tmp.push_back(i);
		bool used[26];
		long long ans = 0;
		do 
		{
			memset(used,0 ,sizeof(used));
			int last = v[tmp[0]][0];
			used[last - 'a'] = 1;
			bool ok = 1;
			for (int i = 0; i < n; i++)
			{
				int id = tmp[i];
				if (used[v[id][0] - 'a'])
				{
					if (v[id][0] != last)
					{
						ok = 0;
						break;
					}
				}
				else
				{
					last = v[id][0];
					used[v[id][0] - 'a'] = 1;
				}
				for (int j = 1; j < v[id].length(); j++)
				{
					if (v[id][j] != last)
					{
						if (used[v[id][j] - 'a'])
						{
							ok = 0;
							break;
						}
						else
						{
							used[v[id][j] - 'a'] = 1;
							last = v[id][j];
						}
					}
				}
				if (!ok)
					break;
			}
			if (ok)
				ans++;
		} while (next_permutation(tmp.begin(), tmp.end()));
		printf("Case #%d: %d\n", q, ans);
	}

	return 0;
}