#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool check(int first, int second, const vector<int>& rel)
{
	return rel[first] == second || rel[second] == first;
}

bool check2(int id, int left, int right, const vector<int>& rel)
{
	return rel[id] == left || rel[id] == right;
}


int main()
{
	freopen( "..\\input.txt", "r", stdin );
	freopen( "..\\output.txt", "w", stdout );

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		int n;
		cin >> n;
		vector<int> rel(n);
		for (int i = 0; i < n; i++)
		{
			cin >> rel[i];
			rel[i]--;
		}

		vector<int> perm(n);
		for (int i = 0; i < n; i++)
		{
			perm[i] = i;
		}

		int ans = 1;
		do
		{
			for (int i = 1; i < n; i++)
			{
				int iprev = i - 1;
				int inext = 0;
				
				
				if (check2(perm[i], perm[iprev], perm[inext], rel)
					&& check2(perm[0], perm[1], perm[i], rel))
				{
					ans = max(ans, i + 1);
				}

				if (i + 1 == n || !check2(perm[i], perm[iprev], perm[i + 1], rel))
				{
					break;
				}
			}
		} while (next_permutation(perm.begin(), perm.end()));

		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}