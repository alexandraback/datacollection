#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

char mp[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main() {
	int tc;
	cin >> tc;
	cin.ignore();
	string s;
	for (int t = 0; t < tc; t++) {
		getline(cin, s);
		int n = s.length();
		cout << "Case #" << t + 1 << ": ";
		for (int i = 0; i < n; i++)
			if (s[i] == ' ')
				cout << ' ';
			else
				cout << mp[s[i] - 'a'];
		cout << endl;
	}
/*
	string s1, s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		int n = s1.length();
		for (int i = 0; i < n; i++)
			if (s1[i] != ' ')
				mp[s1[i] - 'a'] = s2[i];
	}

	for (int i = 0; i < 26; i++)
		cout << mp[i] << ",";
	cout << endl;
*/
}
