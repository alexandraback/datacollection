#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;

#define X first
#define Y second

string s;
deque<char> d;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int x =0; x<t; x++)
	{
		cout << "Case #" << x+1 << ": ";
		cin >> s;
		d.clear();
		for (int i=0; i<s.size(); i++)
			if (d.size() && d.front() <= s[i])
				d.push_front(s[i]);
			else
				d.push_back(s[i]);
		for (int i=0; i<d.size(); i++)
			cout << d[i];
		cout << "\n";
	}

	return 0;
}
