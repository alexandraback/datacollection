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

int n, m;
int a[100][100];

void solve(int test)
{
	int ans = 0;
	printf("Case #%d: ", test);
	forn (i, n)
		forn (j, m)
		{
			bool h = true, w = true;
			forn (k, m)
				if(a[i][k] > a[i][j])
					w = false;
			forn (k, n)
				if(a[k][j] > a[i][j])
					h = false;
			if(!h && !w)
			{
				cout << "NO" << endl;
				return;
			}
		}
	printf("YES\n");
}

bool read()
{
	int t;
	cin >> t;
	forn (i, t)
	{
		scanf("%d%d", &n, &m);
		forn (i, n)
			forn (j, m)
				cin >> a[i][j];
		solve(i + 1);
	}
	return true;
}

int main()
{
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
	read();
	return 0;
}