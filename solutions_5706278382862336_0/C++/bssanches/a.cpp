#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>
#include <deque>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define B 33
#define MAX 100010
#define eps 1e-8
#define pi 3.14159
#define ull unsigned long long
#define MOD 1000000009

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

ll n,p,q;

int main(void)
{
	// ios :: sync_with_stdio(false);

	cin >> n;
	char c;
	for (int i = 0; i < n; ++i)
	{
		cin >> p >> c >>  q;
		long double d = (long double) p / q;

		int j = 0;
		int answ = -1;
		while (j < 40)
		{
			// printf ("%d %.15llf\n",j,d);
			if (d >= 1 && answ == -1)
			{
				answ = j;
			}

			if (d >= 1)
				d -= 1;

			d *= 2;
			j++;
		}

		if ( answ != -1 && (fabs(d - 2) < eps || fabs(d - 1) < eps || fabs(d - 0) < eps))
		{
			cout << "Case #" << i+1 << ": " << answ << "\n";
		}
		else cout << "Case #" << i+1 << ": " << "impossible" << "\n";
	}	
	return 0;
}