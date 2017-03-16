// Problem A. The Last Word
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		static char s[1024];
		vector<char> a;
		scanf("%s", s);
		for (int i = 0; s[i]; i++)
			if (a.size() == 0) a.push_back(s[i]);
			else if (a[0] > s[i]) a.push_back(s[i]);
			else a.insert(a.begin(), s[i]);
		for (int i = 0; i < a.size(); i++)
			s[i] = a[i];

		printf("Case #%d: %s\n", ti, s);
	}

	return 0;
}
