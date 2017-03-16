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

double d;
int n, A;
double ttime[2000];
double dist[2000];
double a[2000];
double ans;

void readdata ()
{
	scanf ("%lf %d %d", &d, &n, &A);
	forn(i, n)
	{
		scanf ("%lf %lf", &ttime[i], &dist[i]);
	}
	forn(i, A)
	{
		scanf ("%lf", &a[i]);
	}
}

void writedata ()
{
	printf ("%.8lf\n", ans);
}

void solve ()
{
	for (int i = 0; i < A; i++)
	{
		double v = dist[0];
		double iam = sqrt ((2*d)/a[i]);
		if (v >= d)
		{
			ans = iam;
		}
		else
		{
			if (n == 1)
			{
				double time_car = d / v;
				ans = max (time_car, iam);
			}
			else
			{
				v = (dist[1] - dist[0]) / (ttime[1]);
				double time_car = (d - dist[0]) / v;
				ans = max (time_car, iam);
			}
		}
		writedata ();
	}
}

int main()
{
    prepare();
	int t;
	scanf ("%d", &t);
	forn(i, t)
	{
		printf ("Case #%d:\n", i + 1);
		readdata ();
		solve ();
		//writedata ();
	}
    
    return 0;
}