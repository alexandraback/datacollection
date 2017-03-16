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
	const char* inFile = "B-large.in";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	int T, S, p, N;
	vector<int> total;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		total.clear();
		cin >> N >> S >> p;

		int score;
		for (int j=0; j<N; j++)
		{
			cin >> score;
			total.push_back(score);
		}

		int res = 0;
		int candidates = 0;
		for (int j=0; j<N; j++)
		{
			if (total[j] % 3 == 0)
			{
				if (total[j] / 3 >= p)
					res++;
				else if (total[j] / 3 + 1 == p && total[j] / 3 - 1 >= 0)
					candidates++;
			}
			else if (total[j] % 3 == 1)
			{
				if (total[j] / 3 + 1 >= p)
					res++;
			}
			else 
			{
				if (total[j] / 3 + 1 >= p)
					res++;
				else if (total[j] / 3 + 1 == p - 1)
					candidates++;
			}
		}
		res += min(candidates, S);

		printf("Case #%d: %d\n", t, res);
	}
	
	return 0;
}