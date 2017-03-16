#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

inline string GetDigits(int n, int sz)
{
	string s;
	while (n)
	{
		s.push_back('0' + n % 10);
		n /= 10;
	}

	while (s.size() < sz)
		s.push_back('0');

	reverse(s.begin(), s.end());

	return s;
}

inline bool Good(string a, string b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] != '?' && a[i] != b[i])
			return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string C, J;
		cin >> C >> J;

		int diff = 1000;
		string bestC;
		string bestJ;

		for (int c = 0; c < 1000; c++)
		{
			string cs = GetDigits(c, C.size());
			if (cs.size() > C.size())
				break;
			if (!Good(C, cs))
				continue;

			for (int j = 0; j < 1000; j++)
			{
				string js = GetDigits(j, J.size());
				if (js.size() > J.size())
					break;
				if (!Good(J, js))
					continue;

				if (abs(c - j) < diff)
				{
					bestC = cs;
					bestJ = js;

					diff = abs(c - j);
				}
			}
		}
			

		cout << "Case " << "#" << t << ": ";
		cout << bestC << " " << bestJ << "\n";
	}
}