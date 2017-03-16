#include <bits/stdc++.h>

using namespace std;

int T;

int ind;

bool cmp(const vector<int> &lhs, const vector<int> &rhs)
{
	return lhs[ind] < rhs[ind];
}

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		int n;
		cin >> n;
		vector<int> l[150];
		vector<int> l2[150];
		for (int i = 0; i < 2*n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				l[i].push_back(x);
			}
		}
		int found = 0;
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			ind = i;
			int st = 2*i - found;
			sort(l + st, l + 2*n - 1, cmp);
			if (st + 1 < 2*n-1 && l[st][i] == l[st+1][i])
			{
				l2[2*i] = l[st];
				l2[2*i+1] = l[st+1];
			}
			else
			{
				found = 1;
				pos = 2*i+1;
				l2[2*i] = l[st];
				l2[2*i+1] = vector<int>(n, 0);
			}
			for (int j = 1; j < 2*i; j += 2)
			{
				if (l2[j][i] != 0 && l2[2*i][j/2] != l2[j][i])
				{
					if (pos == 2*i+1) pos = 2*i;
					swap(l2[2*i], l2[2*i+1]);
					break;
				}
			}
		}
//		for (int i = 0; i < 2*n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cout << l2[i][j] << ' ';
//			}
//			cout << '\n';
//		}
		cout << "Case #" << C << ":";
		for (int i = !(pos % 2); i < 2*n; i += 2)
		{
			cout << ' ' << l2[i][pos/2];
		}
		cout << '\n';
	}
	return 0;
}

