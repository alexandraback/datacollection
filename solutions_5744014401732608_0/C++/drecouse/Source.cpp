#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


void ctb(long long n, stringstream& ss)
{
	if (n / 2 != 0) {
		ctb(n / 2, ss);
	}
	ss << n % 2;
}

int main()
{
	ifstream f("B-small-attempt1.in", std::ios::in);
	int t;
	f >> t;
	string s;
	getline(f, s);
	for (int i = 0; i < t; i++)
	{
		long long b, m;
		f >> b >> m; getline(f, s);
		cout << "Case #" << i + 1 << ": ";
		if (m > powl(2, b-2)) cout << "IMPOSSIBLE\n";
		else
		{
			cout << "POSSIBLE\n";
			stringstream ss;
			if (m == powl(2, b - 2)) ctb(m-1, ss);
			else ctb(m, ss);
			s = ss.str();
			//s.push_back('0');
			reverse(s.begin(), s.end());
			for (int i = 0; i < b; i++)
			{
				for (int j = 0; j < b; j++)
				{
					if (j == b - 1 && i == 0)
					{
						if (m == powl(2, b - 2)) cout << '1';
						else cout << '0';
					}
					else if (i == j) cout << '0';
					else if (j == b - 1)
					{
						if (i <= s.size()) cout << s[i-1];
						else cout << '0';
					}
					else if (i >= j) cout << '0';
					else if (i < j) cout << '1';
				}
				cout << endl;
			}
		}
	}
	return 0;
}

