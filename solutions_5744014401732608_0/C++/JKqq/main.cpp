#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define endl "\n"
#define mp make_pair
#define pll pair<ll,ll>

#include <fstream>
ifstream in("task.in");
ofstream out("task.out");

#define cin in
#define cout out
/**/

vector<int> getOnes(ll m)
{
	vector<int> ones;
	int cur = 1;
	while (m)
	{
		if (m & 1)
			ones.push_back(cur);
		m >>= 1;
		++cur;
	}
	return ones;
}


int main()
{
	ios_base::sync_with_stdio(0);

	int numTests;
	cin >> numTests;
	int ttt = 0;
	while (numTests--)
	{
		++ttt;
		ll b, m;
		cin >> b >> m;
		
		if ((1 << (b - 2)) < m){
			cout << "Case #"<<ttt<<": "<< "IMPOSSIBLE" << endl;
			continue;
		}
		else
			cout << "Case #"<<ttt<<": "<< "POSSIBLE" << endl;
		
		vector<int> ones = getOnes(m);
		int mxOne = *max_element(ones.begin(), ones.end());
		++mxOne;

		vector< vector<int> > g(b+1, vector<int>(b + 1, 0));
		for (int i = 1; i <= mxOne; ++i)
			for (int j = i+1; j <= mxOne; ++j)
				g[i][j] = 1;

		for (int i = 0; i < ones.size(); ++i)
			g[ones[i]+1][b] = 1;
		g[b][b] = 0;

		for (int i = 1; i <= b; ++i)
		{
			for (int j = 1; j <= b; ++j)
				cout << g[i][j];
			cout << endl;
		}
	}


	return 0;
}