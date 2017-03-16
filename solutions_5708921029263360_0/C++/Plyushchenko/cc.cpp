#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
#define problem "test"
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 11111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

int a[z], n, /*J, S, P,*/ m, ans, res[z];
double t;
struct three
{
	int x, y, z;
};
struct cmp 
{

    bool operator() (const three &aa, const three &other) const 
    {
   		if (aa.x == other.x)
		{
			if (aa.y == other.y)
				return aa.z < other.z;
			else
				return aa.y < other.y;
		}
		return aa.x < other.x;

    }
};
int states;
three num[z];
inline void check()
{
    states++;
    if (!(states % 1000000))
    	cerr << states << "\t" << (1 << 27) << "\t" << clock() - t;
    map <three, int, cmp> cnt;
/*	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << "\n";
*/	for (int i = 0; i < n; i++)
		if (a[i])
		{
			cnt[{num[i].x, num[i].y, inf}]++;
			cnt[{num[i].x, inf, num[i].z}]++;
			cnt[{inf, num[i].y, num[i].z}]++;
/*			cout << num[i].x << " " << num[i].y << " " << inf << "\n"
			<< num[i].x << " " << inf << " " << num[i].z << "\n"
			<< inf << " " << num[i].y << " " << num[i].z << "\n";
			cout << "sz = " << cnt.size() << "\n";
*/	}
//	cout << "\n";
//	cerr << "SIZE  = " << cnt.size() << "\n";
/*	for (auto it = cnt.begin(); it != cnt.end(); it++)
	{
		cout << "!";
	}
	cout << "\n";
*/	for (pair <three, int> tmp : cnt)
	{
//	    cout << tmp.first.x << " " << tmp.first.y << " " << tmp.first.z << "\t" << tmp.second << "\n";
		if (tmp.second > m)
			return;
	}
	int days = 0;
	for (int i = 0; i < n; i++)
		days += a[i];
//	cout << "days = " << days << "\n";
	if (ans < days)
	{
		ans = days;
		for (int i = 0; i < n; i++)
			res[i] = a[i];
	}
}
void gen(int k)
{
	if (k == n)
	{
		check();
		return;
	}	
	a[k] = 0;
	gen(k + 1);
	a[k] = 1;
	gen(k + 1);
	a[k] = 0;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
	    int J, S, P, m;
		n = ans = 0;
		map <three, int, cmp> cnt;
		cin >> J >> S >> P >> m;
		for (int i = 0; i < J; i++)
			for (int j = 0; j < S; j++)
				for (int k = 0; k < P; k++)
				{
				    					num[n++] = {i, j, k};
}
		for (int i = 0; i < n; i++)
				    if (cnt[{num[i].x, num[i].y, inf}] < m && cnt[{num[i].x, inf, num[i].z}] < m && cnt[{inf, num[i].y, num[i].z}] < m)
					{
						cnt[{num[i].x, num[i].y, inf}]++;
						cnt[{num[i].x, inf, num[i].z}]++;
						cnt[{inf, num[i].y, num[i].z}]++;
						res[i] = 1;
						ans++;
					}
		cout << "Case #" << test << ": " << ans << "\n";
		for (int i = 0; i < n; i++)
			if (res[i])
			{
				cout << num[i].x + 1 << " " << num[i].y + 1 << " " << num[i].z + 1 << "\n";
			}
		
	                                          }
	return 0;
}