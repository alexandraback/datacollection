#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

LL level[10005], total[10005];

void init()
{
	for (LL i = 0; i < 10005; i++)
		level[i] = 4*i+1;
	total[0] = level[0];
	for (LL i = 1; i < 10005; i++)
		total[i] = total[i-1] + level[i];
}

int main()
{
	init();
	int T,cc=0; scanf("%d", &T);
	while (T--)
	{
		cc++;
		LL N, X, Y;
		scanf("%lld %lld %lld", &N, &X, &Y);
		LL L = (abs(X) + abs(Y))/2;
		if (L >= 1) N -= total[L-1];

		if (N < 0) {
			printf("Case #%d: %.8lf\n", cc, 0.0);
			continue;
		}


		if (X == 0) {
			if (N >= level[L]) 
				printf("Case #%d: %.8lf\n", cc, 1.0);
			else 
				printf("Case #%d: %.8lf\n", cc, 0.0);
			continue;
		}

		LL low = L*2-abs(X)+1;
		LL high = low + (L*2);

		if (N < low) {
			printf("Case #%d: %.8lf\n", cc, 0.0);
		} else if (N > high) {
			printf("Case #%d: %.8lf\n", cc, 1.0);
		} else {
			double ans = pow(0.5, (double)N);
			double base = 1, sum = 1; 
			for (LL i = 1; i < low; i++)
			{
				base *= (N-i+1)*1.0/(i);
				ans += base * pow(0.5, (double)N);
			}
			printf("Case #%d: %.8lf\n", cc, 1-ans);
		}
	}
	return 0;
}
