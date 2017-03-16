#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;

int T;

int main()
{
	scanf("%d", &T);
	for(int tt = 1; tt <= T; ++tt)
	{
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);

		double sol = X / 2;
		double rate = 2;
		double t = 0;

		while(sol > t)
		{
			t += C / rate;
			rate += F;
			double res = X / rate + t;

			sol = min <double> (sol, res);
		}

		printf("Case #%d: %.7lf\n", tt, sol);
	}

	return 0;
}
