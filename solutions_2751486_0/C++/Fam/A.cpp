#include <iostream>
#include <string>

using namespace std;

#define v(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a =='u')


int calc(string s, int n)
{
	int r = 0;
	int l = s.length();
	int rsubs = 0;
	int nr = 0;
	for (int i = 0; i < l; i++) {
		char a = s[i];
		if (!v(a)) {
			if (i < n - 1) goto next;
			for (int j = 0; j < n; j++) {
				if (v(s[i - j])) {
					goto next;
				}
			}
			rsubs = i - n + 2;
		}
next:
		//cout << "for " << a << " nr " << nr << " rsubs " << rsubs << endl;
		r += rsubs;
		continue;
	}
	return r;
}

int main (int argc, char const* argv[])
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string name;
		int n;
		int r;
		cin >> name;
		cin >> n;
		r = calc(name, n);
		cout << "Case #" << i << ": " << r << endl;
	}
	return 0;
}
