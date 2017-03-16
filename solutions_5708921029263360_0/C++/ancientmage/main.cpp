#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <time.h>
#include <vector>
#include <queue>
#include <set>
#include <random>
#include <string>
#include <fstream>

using namespace std;

#define ll long long

#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");
/**/
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	for(int _ = 1; _ <= test; ++_)
	{
		int j,p,s,K;
		cin >> j >> p >> s >> K;
		if(j == p && j == s && j == 3)
		{
			cout << "Case #" << _ << ": ";
			if(K == 1)
			{
				cout << "9\n";
				cout << "2 1 1\n";
				cout << "1 2 1\n";
				cout << "3 3 1\n";
				cout << "1 1 2\n";
				cout << "3 2 2\n";
				cout << "2 3 2\n";
				cout << "3 1 3\n";
				cout << "2 2 3\n";
				cout << "1 3 3\n";

			} else if(K == 2)
			{
				cout << "18\n";
				cout << "1 1 1\n";
				cout << "3 1 1\n";
				cout << "1 2 1\n";
				cout << "2 2 1\n";
				cout << "2 3 1\n";
				cout << "3 3 1\n";
				cout << "1 1 2\n";
				cout << "2 1 2\n";
				cout << "2 2 2\n";
				cout << "3 2 2\n";
				cout << "1 3 2\n";
				cout << "3 3 2\n";
				cout << "2 1 3\n";
				cout << "3 1 3\n";
				cout << "1 2 3\n";
				cout << "3 2 3\n";
				cout << "1 3 3\n";
				cout << "2 3 3\n";
			} else
			{
				cout << "27\n";
				for(int i = 1; i <= 3; ++i)
					for(int j = 1; j <= 3; ++j)
						for(int k = 1; k <= 3; ++k)
							cout << i << " " << j << " " << k << endl;
			}
			continue;
		}
		cout << "Case #" << _ << ": ";
		vector<vector<int> > v;
		for(int ss = 1; ss <= s; ++ss)
		{
			for(int pp = 1; pp <= p; ++pp)
			{
				for(int jj = 1; jj <= j; ++jj)
				{
					vector<int> a;
					a.push_back(jj);
					a.push_back(pp);
					a.push_back(ss);
					v.push_back(a);
				}
			}
		}
		int ans = 0;
		int curmask = 0;
		for(int mask = 1; mask < (1<<v.size()); ++mask)
		{
			int mc = 0;
			vector<vector<int> > jp(j, vector<int> (p,0));
			vector<vector<int> > js(j, vector<int> (s,0));
			vector<vector<int> > ps(p, vector<int> (s,0));
			bool ok = 1;
			for(int k = 0; k < v.size(); ++k)
			{
				if(mask & (1<<k))
				{
					++mc;
					jp[v[k][0]-1][v[k][1]-1]++;
					js[v[k][0]-1][v[k][2]-1]++;
					ps[v[k][1]-1][v[k][2]-1]++;
					if(jp[v[k][0]-1][v[k][1]-1] > K)
					{
						ok = 0;
						break;
					}
					if(js[v[k][0]-1][v[k][2]-1] > K)
					{
						ok = 0;
						break;
					}
					if(ps[v[k][1]-1][v[k][2]-1] > K)
					{
						ok = 0;
						break;
					}
				}
			}
			if(ok && ans < mc)
				ans = mc, curmask = mask;
		}
		cout << ans << "\n";
		for(int i = 0; i < v.size(); ++i)
		{
			if((1<<i) & curmask)
			{
				for(int l = 0; l < 3; ++l)
					cout << v[i][l] << " ";
				cout << endl;
			}
		}
	}

	return 0;
}
 