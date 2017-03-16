#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solve()
{
	int n; string s;
	cin >> n >> s;
	n = min(n, 10);

	while (n && s[n] == '0') --n;
	if (!n && (s[0] == '0'))
	{
		cout << 1 << endl;
		return;
	}

	int invite = 0;
	int stoodUp = s[0] - '0';

	for (int i = 1; i <= n; ++i)
	{
		if (stoodUp < i)
		{
			invite += (i - stoodUp);
			stoodUp = i;
		}
		stoodUp += (s[i] - '0');
	}
	cout << invite << endl;
}

int main() 
{
	std::ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("d:/input.txt", "rt", stdin);
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}


