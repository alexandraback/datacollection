#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <memory.h>
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

void prepare()
{
	freopen("c-small.in", "r", stdin);
	freopen("c-small.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

int s[505];
int n;

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d:\n", test_num);
	scanf("%d", &n);
	fi(n)
		scanf("%d", &s[i]);
	int _2n = 1 << n;
	fo(mask, 0, _2n)
	{
		int s1 = 0, alls2 = 0;
		fi(n)
		{
			if (((mask >> i) & 1) == 0)
				s1 += s[i];
			else
				alls2 += s[i];
		}
		if (alls2 < s1)
			continue;
		for (int sub = mask; sub > 0; sub = (sub - 1) & mask)
		{
			int s2 = 0;
			fi(n)
			{
				if ((sub >> i) & 1)
					s2 += s[i];
			}
			if (s1 == s2)
			{
				fi(n)
				{
					if (((mask >> i) & 1) == 0)
						printf("%d ", s[i]);
				}
				printf("\n");
				fi(n)
				{
					if (((sub >> i) & 1) == 1)
						printf("%d ", s[i]);
				}
				printf("\n");
				return;
			}
		}
	}
	printf("Impossible\n");
	//cerr << clock() << endl;
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
		solve(i + 1);
	return 0;
}