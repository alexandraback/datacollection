#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;
const int inf = 999000999;

int solveStart(int a, int n, int m, int k)
{
	int s = a, l = 1;
	while (a+2 < n)
	{
		a += 2;
		++l;
		s += a;
		if (k <= 2 * s)
		{
			if (l*l <= m)
				return 2 * a;
			else
				return inf;
		}
	}
	k -= 2 * s;
	int ln = ((k + n-1)/n);
	if (2*l + ln <= m)
		return 2 * a + 2 * ln;
	else
		return inf;
}

int solve(int n, int m, int k)
{
	//n % 2 == 1
	int a = 1, s = 1;
	while (s < k)
	{
		++a;
		s += (2 * a - 1) + 2 * a - 3;
	}

	int ans = inf;
	if (2 * a - 1 <= n)
		ans = 4 * a - 4;

	int cans;
	forr(st,1,n-2)
	{
		forr(nn,st+2,n)
		{
			cans = solveStart(st,nn,m,k);
			if (cans < ans)
				ans = cans;
		}
	}

	return ans;
}

int main()
{
    ofstream fout("out.txt");
    freopen("in.txt","r",stdin);
	freopen("debug.txt","w",stdout);

    int t;
    cin >> t;
	int n, m, k;
	rep(tc,t)
	{
		cin >> n >> m >> k;
		if (n <= 2 || m <= 2 || k <= 4)
		{
			fout << "Case #" << tc + 1 << ": " << k << "\n";
		}
		else if (k >= n*m-4)
		{
			fout << "Case #" << tc + 1 << ": " << (2*(n-2 + m-2) + (k - n*m + 4)) << "\n";
		}
		else
		{
			if (n > m)
				swap(n,m);

			fout << "Case #" << tc + 1 << ": " << solve(n,m,k) << "\n";
		}
	}

    return 0;
}