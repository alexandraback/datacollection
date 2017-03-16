#include<iostream>
#include<vector>

using namespace std;

vector<pair<string, string> > V, V1, V2;

bool check()
{
	for (int i = 0; i < V2.size(); i++)
	{
		bool ok1 = false, ok2 = false;
		for (int j = 0; j < V1.size(); j++)
		{
			if (V1[j].first == V2[i].first)
				ok1 = true;
			if (V1[j].second == V2[i].second)
				ok2 = true;
		}
		if (!ok1 or !ok2)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		int n;
		cin >> n;
		V.clear();
		for (int i = 0; i < n; i++)
		{
			string A, B;
			cin >> A >> B;
			V.push_back(make_pair(A, B));
		}
		int ans = 0;
		for (int i = (1 << n) - 1; i >= 0; i--)
		{
			V1.clear();
			V2.clear();
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j))
					V2.push_back(V[j]);
				else V1.push_back(V[j]);
			}
			if (check())
				ans = max(ans, __builtin_popcount(i));
		}
		cout << "Case #" << t << ": " << ans << "\n";
		
	}
	
	
	
	return 0;
}
