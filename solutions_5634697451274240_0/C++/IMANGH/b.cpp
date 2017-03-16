#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 7;
string s;
int main()
{
	int _;
	cin >> _;
	for (int __ = 0; __ < _; __++)
	{
		cout << "Case #" << __+1 << ": ";
		cin >> s;
		int cnt = 0;
		for (int i=0; i<s.size(); i++)
			if (i == 0 || s[i] != s[i-1])
				cnt++;
		if (s.back() == '+')
			cout << cnt-1 << "\n";
		else
			cout << cnt << "\n";
	}
}
