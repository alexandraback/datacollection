#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		double C, F, X; scanf("%lf%lf%lf", &C, &F, &X);
		double Rate = 2, UsedTime = 0, AllTime = X / Rate;
		while (1){
			double d = C / Rate;
			UsedTime += d;
			Rate += F;
			double NewTime = UsedTime + X / Rate;
			if (NewTime > AllTime)
				break;
			else
				AllTime = NewTime;
		}
		printf("%.7lf\n", AllTime);
	}
}
