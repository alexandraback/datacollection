#include <string>
#include <iostream>
using namespace std;

static void process(int tc)
{
	int ans = 0;
	string s;
	cin >> s;
	while (s.size()) {
		while (s.size() && s.back() == '+')
			s.pop_back();
		if (s.empty())
			break;
		++ans;
		for (auto it = s.begin() ; it != s.end() ; ++it)
			*it = *it == '+' ? '-' : '+';
	}
	cout << "Case #" << tc << ": " << ans << endl;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; ++i)
		process(i);
	return 0;
}
