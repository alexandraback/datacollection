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
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

bool good(int index, double per, int n, vector<double> &s)
{
	double sum = 0;
	fi(n)
		sum += s[i];
	double x = s[index] + sum * per;
	double sneed = 0;
	fi(n)
	{
		double need = max(0.0, (x - s[i]) / sum);
		sneed += need;
	}
	return sneed > 1;
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	int n;
	cin >> n;
	vector<double> s(n), res(n);
	fi(n)
		cin >> s[i];
	fi(n)
	{
		double lb = 0, rb = 1;
		for (int iter = 0; iter < 500; iter++)
		{
			double mid = (lb + rb) / 2;
			if (good(i, mid, n, s))
				rb = mid;
			else
				lb = mid;
		}
		res[i] = lb * 100;
	}
	fi(n)
		printf("%.10lf ", res[i]);
	printf("\n");
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