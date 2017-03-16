#include <iostream>
using namespace std;

bool con(char a)
{
	return (a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u');
}

long long f(string& s, int n)
{
	int l = s.size();
	long long ans = 0;
	int longest(0), end(0);
	for (int i = 0; i < l; ++i) {
		while (longest < n) {
			if (end >= l) return ans;
			if (con(s[end])) ++longest;
			else longest = 0;
			++end;
		}
		ans += l-end+1;
		if (end-i == n) --longest;
	}
	return ans;
}

int main()
{
	int t, n;
	string s;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> s >> n;
		cout << "Case #" << i << ": " << f(s,n) << '\n';
	}
	return 0;
}
