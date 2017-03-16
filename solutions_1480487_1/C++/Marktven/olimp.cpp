#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); (i) <= (b); ++(i))
#define mp make_pair
#define inf 2000000000
#define pb push_back
#define X first
#define Y second
#define LL long long
const double eps = 0.0000000001;

double a[2002];
double ans[2002];
int n;


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	FOR(test,1,T)
	{
		cin >> n;
		double sum = 0.0;
		FOR(i,1,n)
		{
			cin >> a[i];
			sum += a[i];
		}
		FOR(i,1,n)
		{
			double left = 0.0, right = 1.0;
			while (right - left > eps)
			{
				double midle = (left + right)/2.0;
				double rest = 1.0 - midle;
				double res = a[i] + sum*midle;
				bool ok = true;
				FOR(j,1,n)
				if (i != j && a[j] < res)
				{
					double tt = (res - a[j]) / sum;
					rest -= tt;
					if (rest < 0)
					{
						ok  = false;
						break;
					}
				}
				if (!ok) right = midle;
				else left = midle;
			}
			ans[i] = (left+right)/2.0;
		}
		printf("Case #%d:",test);
		FOR(i,1,n)
			printf(" %.10lf",100*ans[i]);
//			cout << " " << ans[i];
		cout << endl;
	}
	
    return 0;
}