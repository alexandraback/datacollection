#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef long long LL;

bool is_pal(long long n)
{
	int m = 0;
	int digits[20];
	while (n > 0)
	{
		digits[m++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i + i < m - 1; ++i)
	{
		if (digits[i] != digits[m - i - 1]) return false;
	}
	return true;
}

bool only012(int n)
{
	while (n > 0)
	{
		if (n % 10 > 2) return false;
		n /= 10;
	}
	return true;
}

int brute(LL a, LL b)
{
	int ans = 0;
	int st = (int)(sqrt((long double)a - 1) + 1e-9) + 1;
	int ed = (int)(sqrt((long double)b) + 1e-9);
	for (int i = st; i <= ed; ++i)
	{
		if (i >= 10 && !only012(i)) continue;
		if (!is_pal(i)) continue;

		LL x = (LL)i * i;
		if (is_pal(x))
		{
			++ans;
			printf("%d: %I64d\n", i, x);
		}
	}
	return ans;
}

vector<string> numbers;

int d[128], f[128];
void print(int a[], int m)
{
	for (int i = 0; i < m; ++i)
	{
		printf("%d", a[m - i - 1]);
	}
	puts("");
}
inline void expand1(int d[], int n)
{
	for (int i = 0; i < n - 1; ++i) d[n * 2 - i - 2] = d[i];
}
inline void expand2(int d[], int n)
{
	for (int i = 0; i < n; ++i) d[n * 2 - i - 1] = d[i];
}
int sqr(int c[], int a[], int n)
{
	memset(c, 0, sizeof(*c) * n * 2);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			c[i + j] += a[i] * a[j];
	int m = 0;
	for (; m < n * 2; ++m)
	{
		if (c[m] >= 10)
		{
			c[m + 1] += c[m] / 10;
			c[m] %= 10;
		}
	}
	while (m > 1 && c[m - 1] == 0) --m;
	return m;
}
bool is_pal(int a[], int m)
{
	for (int i = 0; i + i < m - 1; ++i)
		if (a[i] != a[m - i - 1]) return false;
	return true;
}
void add_ans(int a[], int m)
{
	string str;
	for (int i = 0; i < m; ++i)
	{
		str += (char)(a[i] + '0');
	}
	numbers.push_back(str);
}

void dfs(int n)
{
	if (n > 25) return;
	int first = (n == 1) ? 1 : 0;
	for (int i = first; i < 10; ++i)
	{
		d[n - 1] = i;
		expand1(d, n);
		int m = sqr(f, d, n * 2 - 1);
		if (!is_pal(f, m)) break;
		add_ans(f, m);
	}
	int last = 10;
	for (int i = first; i < 10; ++i)
	{
		d[n - 1] = i;
		expand2(d, n);
		int m = sqr(f, d, n * 2);
		if (!is_pal(f, m))
		{
			last = i;
			break;
		}
		add_ans(f, m);
	}
	for (int i = first; i < last; ++i)
	{
		d[n - 1] = i;
		dfs(n + 1);
	}
}

void gen_number()
{
	dfs(1);
}

struct cmp
{
	bool operator()(const string &a, const string &b)
	{
		if (a.length() < b.length()) return true;
		if (a.length() > b.length()) return false;
		return a < b;
	}
};

int main()
{
	gen_number();
	sort(numbers.begin(), numbers.end(), cmp());

	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		char a[1024], b[1024];
		scanf("%s%s", a, b);
		string x(a), y(b);
		int ans = upper_bound(numbers.begin(), numbers.end(), y, cmp()) - lower_bound(numbers.begin(), numbers.end(), x, cmp());
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}
