#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int a, b;

bool f(int q)
{
	vector<int> d;
	while(q > 0)
	{
		d.pb(q % 10);
		q /= 10;
	}
	int l = 0, r = d.size() - 1;
	while(l < r && d[l] == d[r])
		l++, r--;
	if(l < r)
		return false;
	return true;
}

void solve(int test)
{
	int ans = 0;
	printf("Case #%d: ", test);
	for (int i = 1; i * i <= b; ++i)
		if(i * i >= a)
		if(f(i) && f(i * i))
			ans++;
	printf("%d\n", ans);
}

bool read()
{
	int t;
	cin >> t;
	forn (i, t)
	{
		cin >> a >> b;
		solve(i + 1);
	}
	return true;
}

int main()
{
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
	read();
	return 0;
}