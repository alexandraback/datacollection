#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;
typedef long long ll;



int main()
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d: ",cs);

		bool ans;
		int x, r, c;
		cin >> x >> r >> c;
		if (  (r*c) % x) { ans = 0; goto pass; }
		if (x >= 7){ ans = 0; goto pass; }
		if (x <= 2){ ans = 1; goto pass; }

		if (r > c) swap(r, c);
		if (c<x) { ans = 0; goto pass; }
		if (r> (x + 1) / 2) { ans = 1; goto pass; }
		if (r< (x + 1) / 2) { ans = 0; goto pass; }

		switch (x)
		{
			case 3: { ans = 1; goto pass; }
			case 4: { ans = 0; goto pass; }
			case 5: {
				ans = 0;
				for (int i = 0; i <= (c - 3); i++)
				{
					if ((r*i + 2) % c == 0) ans = 1;
				}
				goto pass;
			}
			case 6: {
				ans = 0;
				goto pass;
			}
		}

	pass:
		puts(ans ? "GABRIEL" : "RICHARD");
	}
	

	return 0;
}