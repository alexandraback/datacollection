#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()

using namespace std; 

typedef long long int64;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;

int n, m;



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n >> m;
		vvi f(n, vi(m));
		vector< pair<int, pii> > vs;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> f[i][j];
				vs.push_back( make_pair(f[i][j], pii(i, j)) );
			}
		sort(all(vs), greater<pair<int, pii>>() );		
		vvi ef(n, vi(m, 100));
		bool answer = false;
		for (int i = 0; i < sz(vs); i++)
		{
			int curV = vs[i].first;
			int x = vs[i].second.first;
			int y = vs[i].second.second;
			if (ef[x][y] == curV)
				continue;
			// Horizontal
			bool ok_h = true;
			for (int j = 0; j < m; j++)
			{
				if (f[x][j] > curV)
				{
					ok_h = false;
					break;
				}
			}
			if (ok_h)
			{
				for (int j = 0; j < m; j++)
					ef[x][j] = curV;
			}

			// Vertical
			bool ok_v = true;
			for (int i = 0; i < n; i++)
			{
				if (f[i][y] > curV)
				{
					ok_v = false;
					break;
				}
			}
			if (ok_v)
			{
				for (int i = 0; i < n; i++)
					ef[i][y] = curV;
			}
			if (!ok_v && !ok_h)
				break;
		}
		if (ef == f)
			answer = true;
		cout << "Case #" << t + 1 << ": ";
		if (answer) 
			cout << "YES";
		else 
			cout << "NO";
		cout << endl;
	}

    return 0;
}