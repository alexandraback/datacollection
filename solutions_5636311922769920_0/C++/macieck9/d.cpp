#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int k, c;

long long pos(vector<int> V)
{
	if (V.empty()) return -1;
	long long res = 0;
	for (int i = 0; i < V.size(); i++)
		res = 1ll * k * res + V[i];
	return res;	
}

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		int s;
		cin >> k >> c >> s;
		cout << "Case #" << t << ": ";
		if (s < ceil(1.0 * k/c))
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<int> V;
		for (int i = 0; i < k; i++)
		{
			V.push_back(i);
			if (V.size() == c)
			{
				cout << pos(V) + 1 << " ";
				V.clear();
			}
		}
		long long x = pos(V);
		if (x != -1) cout << x+1;
		cout << "\n";
	}
	
	
	return 0;
}

