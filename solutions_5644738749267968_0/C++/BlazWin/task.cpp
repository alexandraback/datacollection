#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <ctime>

using namespace std;

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make_triple(x,y,z) make_pair((x), make_pair((y),(z)))
#define fr first
#define sc second
#define ts second.first
#define td second.second

typedef long long ll;
typedef unsigned long long ull; 
typedef double ld;

const long double eps = 1e-9;
const int inf = LONG_MAX;
const ll inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;

#define N 10000

double a[N], b[N];
bool c[N];

int main()
{
	int t;
	scanf("%d", &t);
	freopen("output1","w",stdout);
	for (int ii = 0; ii<t; ii++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
			scanf("%lf", &a[i]);
		for (int i = 0; i<n; i++)
			scanf("%lf", &b[i]);
		sort(a, a+n);
		sort(b, b+n);
		deque<double> b1(b, b+n);
		int ans1 = 0, ans2 = 0;
		fill(c, c+n, false);
		for (int i = 0; i<n; i++)
		{
			if (a[i] < b1.front())
				b1.pop_back();
			else
				b1.pop_front(), ans1++;
			bool found = false;
			for (int h = 0; h<n; h++)
				if (!c[h] && b[h] > a[i])
				{
					c[h] = true, found = true;
					break;
				}
			if (!found)
				ans2++;
		}
		printf("Case #%d: %d %d\n", ii+1, ans1, ans2);
	}
	return 0;	
}