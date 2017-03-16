#pragma comment(linker, "/STACK:25600000")
#define _CRT_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(ll i=0; i<n; i++)
#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define RFOR(i, x, y) for(ll i=x; i>=y; i--)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define PII pair<ll, ll>
const double pi=acos(-1.0);
const double eps = 1e-9;
const double INF = 1000000000000000;

double d;
int N, A, n;
double a;
double t[2048];
double x[2048];

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("b-large.txt", "w", stdout);

	int tests;
	cin >> tests;
	REP(TEST, tests)
	{
		printf("Case #%lld:\n", TEST + 1);
		cin >> d >> N >> A;						
		REP(i, N)		
		{
			cin >> t[i] >> x[i];
			if (x[i] > d)
			{
				double t_prev = 0;
				double x_prev = 0;
				if (i)
				{
					t_prev = t[i-1];
					x_prev = x[i-1];
				}
							
				t[i] = (d - x_prev) / (x[i] - x_prev) * (t[i] - t_prev);
				x[i] = d;
			}
		}
		
		if (N)
		{
			t[N] = t[N-1];
			x[N] = d;
		}
		else
		{
			t[0] = 0;
			x[0] = d;
		}
		++N;

		REP(i, A)
		{
			cin >> a;			
			double speed = 0;
			double res = 0;

			REP(i, N)
			{
				double dist = 0;
				if (i == 0)
					dist = x[0];
				else
					dist = x[i] - x[i-1];

				double add_time = (-2 * speed + sqrt(4 * speed * speed + 8 * a * dist)) / 2.0 / a;
				speed += add_time * a;
				res = max(t[i], res + add_time);
			}
			printf("%.12lf\n", res);
		}
	}
}