#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#define ll long long
#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair <int, int>
#define ff first
#define ss second
#define ldb long double
#define sqr(a) ((a) * (a))
#define nextLine() {int c = 0; while((c = getchar()) != 10 && c != EOF);}
#define addEdge(a, b) next[edges] = first[a]; first[a] = edges; end[edges] = a;
#define debug(a) cerr << #a << " = " << (a) << " ";
#define debugl(a) cerr << #a << " = " << (a) << "\n";
const ldb eps = 1e-9;
const ldb pi = fabsl(atan2l(0.0, -1.0));
const ll inf = 1 << 28;
using namespace std;
#define problem "c"


int n;
ll s[1000];
ll sum[1000];
int pw[(1 << 20) + 1];
class m
{
	public:
		int f1, f2, s, i;
};

inline bool operator < (const m & t1, const m & t2)
{
	return t1.f1 < t2.f1 || t1.f1 == t2.f1
	&& (
		t1.f2 < t2.f2 || t1.f2 == t2.f2 && 
		(
			t1.s < t2.s || t1.s == t2.s &&
			(
				t1.i < t2.i
			)
		)
	);
}

map <m, bool> dp;



void load()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	sort(s, s + n);
	for (int i = n - 1; i >= 0; i--)
	{
		sum[i] = s[i];
		if (i < n - 1)
			sum[i] += sum[i + 1];
	}
}

bool f(int S, int i, int f1, int f2)
{
	if (i == n)
		return S == 0 && f1 && f2;
	if (S > sum[i] || S < -sum[i]) return 0;
	m k;
	k.f1 = f1;
	k.f2 = f2;
	k.s = S;
	k.i = i;
	if (dp.find(k) != dp.end()) return dp[k];
	return (dp[k] = f(S, i + 1, f1, f2) | f(S - s[i], i + 1, f1, 1) | f(S + s[i], i + 1, 1, f2));
}

vector <int> fst, sec;

void out(int S, int i, int f1, int f2)
{
	if (i == n) return;
	if (f(S, i + 1, f1, f2))
		out(S, i + 1, f1, f2);
	else if (f(S - s[i], i + 1, f1, 1))
	{
		sec.pb(i);
		out(S - s[i], i + 1, f1, 1);
	}
	else
	{
		fst.pb(i);
		out(S + s[i], i + 1, 1, f2);
	}
}


void solve(int test_number)
{
	cerr << "Case #" << test_number << "\n";
	dp.clear();
	fst.clear();
	sec.clear();
	/*all.clear();
	for (int i = 1; i < (1 << n); i++)
	{
		sum[i] = sum[i - (i & -i)] + s[pw[i & -i]];
		all.pb(sum[i]);
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < all.size(); i++)
	{
		int j = i;
		while (j < all.size() && all[i] == all[j])
		{
			j++;
			}
	}
	*/
	cout << "Case #" << test_number << ": ";
	if (!f(0, 0, 0, 0))
	{
		printf("Impossible\n");
		return;
	}
	cout << "\n";
	out(0, 0, 0, 0);
	for (int i = 0; i < fst.size(); i++)
	{
		cout << s[fst[i]] << " ";
	}
	cout << "\n";
	for (int i = 0; i < sec.size(); i++)
	{
		cout << s[sec[i]] << " ";
	}
	cout << "\n";
}

int main()
{
	freopen(problem ".in", "rt", stdin);
	freopen(problem ".out", "wt", stdout);
	int t;

	pw[0] = 1;
	for (int i = 1; i <= 20; i++)
		pw[1 << i] = i;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
	return 0;
}

