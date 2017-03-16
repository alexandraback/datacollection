#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int c;
	for(c = 1; c<=tc; c++){
		printf("Case #%d: ", c);

		double cost, farm, goal, res;
		scanf("%lf%lf%lf", &cost, &farm, &goal);

		res = goal / 2.;

		int nowFarm;
		double nowTime = cost / 2.;
		for(nowFarm = 1;; nowFarm++){
			double tTime = nowTime + goal/(2. + nowFarm*farm);
			if(res > tTime) res = tTime;
			else break;

			nowTime += cost / (2. + nowFarm*farm);
		}

		printf("%.7lf\n", res);
	}

	return 0;
}