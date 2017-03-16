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
#define problem "a"


int n, s[123123];
int X;



void load()
{
	cin >> n;
	X = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		X += s[i];
	}
}

bool check(ldb x, int i)
{
	ldb z = s[i] + X * x;
	ldb sum = 0;
	for (int j = 0; sum < 1.0 - x - eps && j < n; j++)
	{
		if (j == i) continue;
		sum += max((z - s[j]) / (ldb)X, (ldb)0.0);
	}
	return !(sum < 1.0 - x - eps);
}

ldb ans[123123];

void solve(int test_number)
{
	cerr << "Case #" << test_number << "\n";
	for (int i = 0; i < n; i++)
	{
		ldb l = 0;
		ldb r = 1.0;
		ldb mid;
		for (int t = 1; t <= 300; t++)
		{
			mid = (l + r) * 0.5;
			if (check(mid, i))
				r = mid;
			else
				l = mid;
		}
		ans[i] = r;
	}
	cout << "Case #" << test_number << ": ";
	for (int i = 0; i < n; i++)
	{
		printf("%.7lf ", (double)ans[i] * 100);
	}
	cout << "\n";
}

int main()
{
	freopen(problem ".in", "rt", stdin);
	freopen(problem ".out", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		load();
		solve(i + 1);
	}
	return 0;
}

