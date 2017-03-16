#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
char p[107], q[107];
const ll INF = (ll)1e18 + 228;
int maxVal(char c)
{
	if (c == '?') return 9;
	return c - '0';
}
int minVal(char c)
{
	if (c == '?') return 0;
	return c - '0';
}
pair<ll, pair<string, string> >doit(char a[], char b[], int bestPos)
{
	int n = strlen(a);
	string ansa(a), ansb(b);
	for (int i = 0; i < bestPos; i++)
	{
		int cur = '0';
		if (a[i] != '?') cur = a[i];
		if (b[i] != '?') cur = b[i];
		ansa[i] = cur;
		ansb[i] = cur;
	}
	if (a[bestPos] == '?' && b[bestPos] == '?')
	{
		ansa[bestPos] = '1';
		ansb[bestPos] = '0';
	}
	else if (a[bestPos] == '?')
	{
		ansa[bestPos] = b[bestPos] + 1;
	}
	else if (b[bestPos] == '?')
	{
		ansb[bestPos] = a[bestPos] - 1;
	}
	for (int i = bestPos + 1; i < n; i++)
	{
		if (ansa[i] == '?') ansa[i] = '0';
		if (ansb[i] == '?') ansb[i] = '9';
	}
	long long goa = 0, gob = 0;
	for (int i = 0; i < n; i++)
	{
		goa = 10 * goa + ansa[i] - '0';
		gob = 10 * gob + ansb[i] - '0';
	}
	return make_pair(abs(goa - gob), make_pair(ansa, ansb));
}
pair<ll, pair<string, string> >calc(char a[], char b[])
{
	int n = strlen(a);
	string ansa(a), ansb(b);
	bool veryGood = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) veryGood = false;
	}
	if (veryGood)
	{
		for (int i = 0; i < n; i++)
		{
			int cur = '0';
			if (a[i] != '?') cur = a[i];
			if (b[i] != '?') cur = b[i];
			ansa[i] = cur;
			ansb[i] = cur;
		}
		return make_pair(0, make_pair(ansa, ansb));
	}
	int bestPos = -1;
	bool canBeGood = true;
	for (int i = 0; i < n; i++)
	{
		if (canBeGood && maxVal(a[i]) > minVal(b[i]))
		{
			bestPos = i;
		}
		if (a[i] != '?' && b[i] != '?' && a[i] != b[i])
		{
			canBeGood = false;
		}
	}
	pair<long long, pair<string, string> >res = make_pair(INF, make_pair(ansa, ansb));
	for (int i = 0; i <= bestPos; i++)
	{
		if (maxVal(a[i]) > minVal(b[i]))
		{
			res = min(res, doit(a, b, i));
		}		
	}
	return res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%s %s\n", p, q);
		int n = strlen(p);
		pair<long long, pair<string, string> >goa = calc(p, q);
		pair<long long, pair<string, string> >gob = calc(q, p);
		swap(gob.second.first, gob.second.second);
		if (gob < goa) swap(gob, goa);
		cout << "Case #" << tt << ": " << goa.second.first << ' ' << goa.second.second << endl;
	}
}
