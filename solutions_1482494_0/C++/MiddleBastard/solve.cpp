#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;


vector < pair < int, int > > a, b;
vector < int > w;
int q, n, x, y;
const int INF = 1000000000;
int ans;
vector < int > st;
int tr, t;
int ind;
bool ok;


bool cmp(pair < int, int > a, pair < int, int > b)
{
	return (a.second < b.second || a.second == b.second && a.first < b.first);
}


int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out","w",stdout);
	
	cin >> q;
	
	for (int z = 0; z < q; z++)
	{
		cin >> n;
		
		ans = INF;
		
		a.clear();
		w.clear();
		
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			a.push_back(make_pair(x, y));
			w.push_back(i);
		}
		
		sort(a.begin(), a.end(), cmp);
		ans = INF;
		
		do
		{
			t = 0;
			tr = 0;
			ok = 0;
			
			st.assign(n, 0);
			
			for (int i = 0; i < n; i++)
			{
				x = a[i].second;
				
				if (x <= t)
				{
					tr++;
					t += 2 - st[i];
					st[i] = 2;
					
					if (i == n - 1)
						ok = 1;
				}
				else
				{
					for (int l = 0; l < n; l++)
						for (int j = 0; j < n; j++)
						{
							if (x <= t)
								break;
							if (x > t && a[w[j]].first <= t && st[w[j]] == 0)
							{
								tr++;
								t++;
								st[w[j]] = 1;
							}
						}
										
					
					if (x > t)
						break;
					
					tr++;
					t += 2 - st[i];
					st[i] = 2;
					
					if (i == n - 1)
						ok = 1;
				}
			}
			
			if (ok)
				ans = min(ans, tr);
		}
		while (next_permutation(w.begin(), w.end()));
		
		cout << "Case #" << z + 1 << ": ";
		
		if (ans == INF)
			cout << "Too Bad\n";
		else
			cout << ans << endl;
			
	}

	return 0;
}
