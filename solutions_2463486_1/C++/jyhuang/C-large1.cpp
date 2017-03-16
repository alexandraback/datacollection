#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>

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
	char s[128];
	vector<long long> v;
	for (long long r = 1LL; ; r++) {
		long long x = r * r;
		if (x > 100000000000000LL) break;
		sprintf(s, "%lld", r);
		if (!check(s)) continue;
		sprintf(s, "%lld", x);
		if (!check(s)) continue;
		v.push_back(x);
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		long long a, b, count = 0;
		cin >> a >> b;
		for (int i = 0; i < v.size(); i++)
			if (v[i] >= a && v[i] <= b) count++;
		cout << "Case #" << (t + 1) << ": " << count << endl;
	}

	return 0;
}
