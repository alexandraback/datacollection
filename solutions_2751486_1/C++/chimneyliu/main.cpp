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


vector<pair<int,int> > p;
string target = "";
string status = "";
int res = 2147483647;


int main()
{
	const char* inFile = "in.txt";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	int T;
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		string s;
		int n;
		int64 res = 0;
		
		cin >> s >> n;
		int L = s.length();

		int* cnt = new int[L+2];

		for (int i = 0; i < L; ++i)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o')
				cnt[i] = 0;
			else
				cnt[i] = (i == 0 ? 1 : cnt[i-1] + 1);
		}

		int ppos = -1, pos = -1;
		for (int i = 0; i < L; ++i)
		{
			if (cnt[i] >= n)
			{
				pos = i - n + 1;
				res += (pos - ppos) * (L - i);
				ppos = pos;
			}
		}

		printf("Case #%d: %d\n", t, res);

		delete [] cnt;
	}
	
	return 0;
}