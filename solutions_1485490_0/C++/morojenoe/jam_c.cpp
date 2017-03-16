#pragma comment(linker, "/STACK:1073741824")
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1000000000;

using namespace std;

void prepare(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
#endif  
}

int n, m;
pair <ll, int> a[200][2];
ll ans;

void readdata ()
{
	ans = 0;
	scanf ("%d %d", &n, &m);
	forn(i, n)
	{
		scanf ("%lld %d", &a[i][0].first, &a[i][0].second);
	}
	forn(i, m)
	{
		scanf ("%lld %d", &a[i][1].first, &a[i][1].second);
	}
}

void writedata ()
{
	cout << ans << endl;
}

ll get (int i, int j, ll remi, ll remj)
{
	if (i >= n || j >= m) return 0;
	if (a[i][0].second == a[j][1].second)
	{
		ll mn = min (remi, remj);
		return mn + max (
			get(i + 1, j + 1, a[i + 1][0].first, a[j + 1][1].first), 
			max ( get ( i, j + 1, remi - mn, a[j + 1][1].first )   ,  
			get (i + 1, j, a[i + 1][0].first, remj - mn)  ));
	}
	else
		return max (get(i + 1, j, a[i + 1][0].first, remj), get(i, j + 1, remi, a[j + 1][1].first));
}


void solve ()
{
	ans = get (0, 0, a[0][0].first, a[0][1].first);
}

int main()
{
    prepare();
	int t;
	scanf ("%d", &t);
	forn (i, t)
	{
		printf("Case #%d: ", i + 1);
		readdata ();
		solve ();
		writedata ();
	}
    return 0;
}