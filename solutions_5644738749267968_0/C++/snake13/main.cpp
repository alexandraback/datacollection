#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <ctime>
#define LL long long int
#define double long double
using namespace std;

void solve ()
{
	int i, n;
	cin >> n;
	vector <double> v1(n), v2(n);
	for (i = 0; i < n; i++) cin >> v1[i];
	for (i = 0; i < n; i++) cin >> v2[i];
	sort(v1.begin(), v1.end());
	set <double> s, h;
	for (i = 0; i < n; i++) s.insert(v2[i]);
	set <double>::iterator j;

	double my;
	h = s;
	int ans1 = 0, ans2 = 0;
	for (i = 0; i < n; i++)
	{
		my = v1[i];
		if (my > *h.begin())
		{
			ans1++;
			h.erase(h.begin());
		}
		else
		{
			j = h.end();
			j--;
			h.erase(j);
		}
	}

	for (i = 0; i < n; i++)
	{
		my = v1[i];
		j = s.upper_bound(my);
		if (j != s.end()) s.erase(j);
		else
		{
			ans2 += (n - i);
			break;
		}
	}
	cout << ans1 << " " << ans2 << endl;
}

int main()
{
	freopen("D-small-attempt1.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i, t;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}