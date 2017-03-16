#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

string f() 
{
	string s;
	cin >> s;
	string ans;
	for (int i = 0; i < s.length(); ++i ) 
	{
		if (s[i]+ans<ans+s[i]) ans += s[i];
		else ans = s[i] + ans;
	}
	return ans;
}

int main() 
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int n_test;
	cin >> n_test;
	for (int i_test = 0; i_test < n_test; ++i_test) 
	{
		cout << "Case #" << i_test+1 << ": " << f() << endl;
	}
}