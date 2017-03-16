#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;
typedef long long int64;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define SIZE(a) ((a).size())

template<typename T> T gcd(T a, T b) { if (!b) return a; else return gcd(b, a%b);}
template<typename T> void ext_euclid(T a, T b, T& x, T& y) { if (!b) {x=1; y=0;} else {int xx, yy; ext_euclid(b, a%b, xx, yy); x=yy; y=-yy*(a/b)+xx;}}

int main()
{
	const char* inFile = "C-large.in";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	int p10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		int A, B;
		int64 res = 0ll;
		cin >> A >> B;
		for (int n=A; n<=B; n++)
		{
			int numDigits = 0;
			int nn= n;
			while (nn)
			{
				nn /= 10;
				numDigits++;
			}

			int m = n;
			do 
			{
				m = (m / 10) + (m % 10) * p10[numDigits-1];
				if (m != n && m >= A && m <= B && n < m)
					res++;
			} while (m != n);
		}

		printf("Case #%d: %lld\n", t, res);
	}
	
	return 0;
}