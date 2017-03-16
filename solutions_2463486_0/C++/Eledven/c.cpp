#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));
const int MAXN = 10000000;

bool isPalindrome(LL a)
{
	vector <int> cur;
	do
	{
		cur.pb(a % 10);
		a /= 10;
	} while (a > 0);
	for (int i = 0; i < (int)cur.size(); i++)
	{
		if (cur[i] != cur[(int)cur.size() - i - 1])
			return false;
	}
	return true;	
}

vector <LL> all;
void prepare()
{
	for (int i = 1; i <= MAXN; i++)
	{
		if (!isPalindrome(i)) continue;
		LL sq = i * 1LL * i;
		if (isPalindrome(sq))
			all.pb(sq);
	}
	eprintf("total: %d\n", all.size());
	for (int i = 0; i < (int)all.size(); i++)
		cerr << all[i] << "\n";
}

int main()
{
	prepare();
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		LL a, b;
		scanf(LLD""LLD, &a, &b);
		vector <LL>::iterator left = lower_bound(all.begin(), all.end(), a);
		vector <LL>::iterator right = upper_bound(all.begin(), all.end(), b);
		printf("Case #%d: %d\n", test, right - left);
	}	
	return 0;
}
