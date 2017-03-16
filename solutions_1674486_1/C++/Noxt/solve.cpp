#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <sstream>
#include <math.h>
#include <queue>

#define MAXN 1001

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	
	long t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		long n;
		cin >> n;
		
		long a[MAXN][MAXN] = {{0}};
		
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][0];
			for (int j = 1; j <= a[i][0]; j++)
			{
				cin >> a[i][j];
			}
		}
		
		bool was_answer = false;
		
		for (int i = 1; i <= n && !was_answer; i++)
		{
			bool mark[MAXN] = {false};
			queue<int> q;
			mark[i] = true;
			q.push(i);
			int x;
			while(!q.empty())
			{
				x = q.front();
				q.pop();
				for (int j = 1; j <= a[x][0] && !was_answer; j++)
				{
					if (mark[a[x][j]])
					{
						was_answer = true;
					}
					else
					{
						q.push(a[x][j]);
						mark[a[x][j]] = true;
					}
				}
			}
		}
		
		
		cout << "Case #" << test << ": ";
		if (was_answer)
			cout << "Yes";
		else
			cout << "No";
		if (test != t)
			cout << endl;
	}
	
	
	return 0;
}