#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <math.h>
#define int64 long long
#define ld long double
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define mp make_pair

using namespace std;

const int N = 300000;
const int inf = 1000000000;


int a1[10][10], a2[10][10], a[17];

int main()
{
/*#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
//#ifndef _DEBUG
	freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
//#endif
	int q;
	scanf("%d", &q);
	rep(ii,1,q)
	{
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double res = x / 2.0;
		double val = 0;
		for (double j = 0; j <= 110000; j++)
		{
			val += c / (2.0 + j * f);
			res = min(res, val + x / ((j + 1) * f + 2.0));
		}
		printf("Case #%d: ", ii);
		printf("%.7lf", res);
		if (ii != q) printf("\n");
	}
	return 0;
}