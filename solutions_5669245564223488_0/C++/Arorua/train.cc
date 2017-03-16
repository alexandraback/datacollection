#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool validate(string s)
{
	bool t[256] = {0};
	char last = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != last) {
			if (t[s[i]]) return false;
			last = s[i];
			t[last] = 1;
		}
	return true;
}

int proc(int k)
{
	int m;
	cin >> m;
	vector<string> v;
	int a[20];	
	for(int i = 0; i < m; i++) {
		a[i] = i;
		string s;
		cin >> s;
		v.push_back(s);
	}
	int ans = 0;
	do {
		string s;
		for (int i = 0; i < m; ++i) s += v[a[i]];
		if (validate(s)) ans += 1; 
	} while(next_permutation(a, a + m));
	cout << "Case #" << k << ": " << ans << endl;
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i) proc(i);
}

