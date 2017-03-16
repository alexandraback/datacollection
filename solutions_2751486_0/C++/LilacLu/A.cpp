#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

#define SMALL
//#define LARGE

using namespace std;

string inp;
int n;
vector <string> vs;

bool is_vowel(const char& c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
		return true;
	return false;
}

bool check(const string& s) {
	int len = s.length();
	int d = 0;
	for (int i = 0; i < len; ++i) {
		if (!is_vowel(s[i]))
			d++;
		else
			d = 0;
		if (d >= n)
			return true;
	}
	return false;
}

int main()
{
#ifdef SMALL
	freopen("A_small.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("A_large.in", "r", stdin);
	freopen("A_large.out", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int Case = 1; Case <= t; ++Case) {
		cin >> inp >> n;
		int len = inp.length();
		vs.clear();
		string s;
		for (int i = 0; i < len; ++i) {
			s = "";
			for (int j = i; j < len; ++j) {
        s += inp[j];
				vs.push_back(s);
			}
		}
		len = vs.size();
		int ans = 0;
		for (int i = 0; i < len; ++i)
			if (check(vs[i]))
				ans++;
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
