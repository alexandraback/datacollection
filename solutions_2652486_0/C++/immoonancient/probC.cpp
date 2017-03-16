#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool verify(vector<int>& guess, vector<int>& prod)
{
	int n = guess.size();
	set<int> prods;
	for (int s = 0; s < (1 << n); s++)
	{
		int cur = 1;
		for (int i = 0; i < n; i++)
			if (s & (1 << i))
				cur *= guess[i];
		prods.insert(cur);
	}
	for (int i = 0; i < prod.size(); i++)
		if (!prods.count(prod[i]))
			return false;
	return true;
}

vector<int> guess(int n, int m, vector<int>& prod)
{
	vector<int> ans(n, 2);
	while (ans[0] <= m)
	{
		if (verify(ans, prod))
			return ans;
		
		ans.back()++;
		if (ans.back() > m)
		{
			for (int i = n - 1; i && ans[i] > m ; i--)
			{
				ans[i] = 2;
				ans[i-1]++;
			}
		}
	}
}

int main()
{
	int caseN;
	cin >> caseN;
	for (int caseI = 1; caseI <= caseN; caseI++)
	{
		int r, n, m, k;
		cin >> r >> n >> m >> k;
		cout << "Case #" << caseI << ":" << endl;
		while (r--)
		{
			vector<int> prod(k);
			for (int i = 0; i < k; i++)
				cin >> prod[i];
				
			vector<int> ans = guess(n, m, prod);
			
			for (int i = 0; i < n; i++)
				cout << ans[i];
			cout << endl;
		}
	}
	
}
