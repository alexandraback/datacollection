#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 1 << 22;

int n, k;
char s[N];
int pos[N];

bool isCons(char c)
{
	switch(c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return false;

	default:
		return true;
	}
}

long long solve()
{
	long long res = 0;

	int tail = 0, border = -1;
	for(int i = 0; i < n; i++)
	{
		tail = (isCons(s[i]) ? tail + 1 : 0);
		if(tail >= k)
			border = i - k + 1;

		if(border >= 0)
			res += border + 1;
	}

	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%i\n", &t);

	for(int ti = 1; ti <= t; ti++)
	{
		scanf("%s %i\n", s, &k);
		n = (int)strlen(s);
		cout << "Case #" << ti << ": " << solve() << "\n";
	}

	return 0;
}
