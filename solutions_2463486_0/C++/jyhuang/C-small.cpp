#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

bool check(const char *s)
{
	int n = strlen(s);
	for (int i = 0, j = n - 1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b, count = 0;
		cin >> a >> b;
		char s[64];
		int r = sqrt(a);
		for (int r = (int) sqrt(a); (r * r) <= b; r++) {
			int x = r * r;
			if (x < a) continue;
			sprintf(s, "%d", r);
			if (!check(s)) continue;
			sprintf(s, "%d", x);
			if (!check(s)) continue;
			count++;
		}

		cout << "Case #" << (t + 1) << ": " << count << endl;
	}

	return 0;
}
