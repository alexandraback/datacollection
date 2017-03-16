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

#define N 100

char ans[N][N];

void doit(int n, int m, int mm)
{
	int mmax = max(n,m);
	if (mmax - 2 >= mm)
	{
		int cc = 0;
		for (int i = 0; i < n; i++)
		{
			for (int h = 0; h < m; h++)
			{
				if (!cc)
					printf("c");
				else
					(cc > 1 + mmax - 2 - mm ? printf("*") : printf("."));
				cc++;
			}
			printf("\n");	
		}
	}
	else
		printf("Impossible\n");	
}

void output(int n, int m)
{
	bool first = true;
	for (int i = 0; i < n; i++)
	{
		for (int h = 0; h < m; h++)
		{
			if (first)
			{
				first = false;
				printf("c");
				continue;
			}
			(ans[i][h]?printf("*"):printf("."));
		}
		printf("\n");
	}		
}

int main()
{
	int t;
	scanf("%d", &t);
	freopen("output1","w",stdout);
	for (int ii = 0; ii<t; ii++)
	{
		printf("Case #%d:\n", ii + 1);
		int n,m,mm;
		scanf("%d%d%d", &n,&m,&mm);
		for (int i = 0; i < n; i++)
			for (int h = 0; h < m; h++)
				ans[i][h] = true;		
		if (mm == n * m - 1)
		{
			ans[0][0] = false;
			output(n,m);
			continue;
		}
		if (min(n,m) == 1)
		{
			doit(n,m,mm);
			continue;
		}
		for (int i = 0; i < 2; i++)
			for (int h = 0; h < m; h++)
				ans[i][h] = false;
		for (int i = 0; i < n; i++)
			for (int h = 0; h < 2; h++)
				ans[i][h] = false;

		if ((n - 2)*(m - 2) >= mm)
		{
			int cc = (n - 2)*(m - 2) - mm;
			for (int i = 2; i < n; i++)
				for (int h = 2; h < m; h++)
				{
					if (!cc)
						goto label;
					ans[i][h] = false;
					--cc;	
				}
label:
			output(n, m);
			continue;
		}
		int val = mm - (n - 2)*(m - 2);

		if (val <= (n - 2) * 2 + (m - 2) * 2 
			&& !(val&1))
		{
			int cc = val;
			for (int i = n - 1; i >= 2; i--)
			{
				if (!cc)
					goto label1;
				cc -= 2;
				ans[i][0] = true;
				ans[i][1] = true;
			}
			for (int i = m - 1; i >= 2; i--)
			{
				if (!cc)
					goto label1;
				cc -= 2;
				ans[0][i] = true;
				ans[1][i] = true;
			}
label1:
			output(n, m);
			continue;
		}
		if ((n - 2)*(m - 2) != 0)
			val = mm - (n - 2)*(m - 2) + 1;
		else
			val = mm;
		if (val <= (n - 3) * 2 + (m - 3) * 2
			&& !(val&1))
		{
			ans[2][2] = false;
			int cc = val;
			for (int i = n - 1; i >= 3; i--)
			{
				if (!cc)
					goto label2;
				cc -= 2;
				ans[i][0] = true;
				ans[i][1] = true;
			}
			for (int i = m - 1; i >= 3; i--)
			{
				if (!cc)
					goto label2;
				cc -= 2;
				ans[0][i] = true;
				ans[1][i] = true;
			}
label2:
			output(n, m);
			continue;

		}
		printf("Impossible\n");	
	}
	return 0;	
}