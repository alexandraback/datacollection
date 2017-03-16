#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define for0(i, N) for(int i = 0; i < (N); i++)
#define pb push_back
#define vec1(type) vector<type>
#define vec2(type) vector< vec1(type) >

typedef unsigned long long ull;

using namespace std;



int main()
{
	int kases;
	cin >> kases;	
	for0(kase, kases)
	{
		int N;
		cin >> N;
		vector< vector < int > > map(N, vector<int>(0, 0));
		for0(n, N)
		{
			int M;			
			cin >> M;
			for0(m, M)
			{
				int t;
				cin >> t;
				map[n].pb(t-1);
			}
		}
		vector<int> lis;
		bool mul = false;
		for0(n, N)
		{
			vector<bool> vis(N, false);
			lis.pb(n);
			mul = false;
			while(!lis.empty())
			{
				int cur = lis.back();
				lis.pop_back();
				if (vis[cur])
				{
					mul = true;
					break;
				}
				vis[cur] = true;
				for0(i, map[cur].size())
				{
					lis.pb(map[cur][i]);
				}
			}
			if(mul)
				break;
		}
		cout << "Case #" << kase + 1 << ": ";
		if (mul)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

