#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

#define LL long long

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0 ? -x : x; }

using namespace std;



int main()
{
//*
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
//*/
	int T;
	cin>> T;
	for (int test = 1; test <= T; test++)
	{
		LL ans = 0, r, t;
		cin>> r>> t;
		for (LL i = 1;; i += 2)
		{
			LL x = 2 * (r + i) - 1;
			if (t < x)
				break;
			t -= x, ++ans;
		}
		cout<< "Case #"<< test<< ": "<< ans<< endl;
	}
	return 0;
}
