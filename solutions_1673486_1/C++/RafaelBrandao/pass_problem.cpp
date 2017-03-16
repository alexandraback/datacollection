#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
int cn;

double e[100010], p[100010];
int n,A,B;

int main() {
	int cases;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d%d",&A,&B);
		double allSu = 1.0;
		for (int i=0; i < A; ++i) {
			e[i] = 0.0;
			scanf("%lf",&p[i]);
			allSu *= p[i];
		}
		double res = 0.0, t;
		
		double prob = 1.0, probBad, su = 1.0;
		double cost, costBad;
		
		cost = B-A + 1;
		res = allSu * cost;
		cost = B-A + 1 + B + 1;
		res += (1.0-allSu) * cost;
		//printf("all su: %.2lf\n",res);
		cost = 1 + B + 1;
		res = min(res, cost);
		for (int i=0; i < A; ++i) {
			// fail at this char, but all the previous correct
			//printf("Mistake on %d (su = %.2lf):\n",i,1.0-su);
			if (i==0) prob = 1.0;
			else prob = (1.0 - p[i]) * su + allSu;

			cost = (A-i) + (B-i) + 1;
			//printf("  %.2lf * cost(%.2lf) = %.2lf\n", prob,cost,prob*cost);
			
			if (i) {
				probBad = 1.0 - prob;
				costBad = (A-i) + (B-i) + 1 + B + 1;
				t = prob*cost + probBad*costBad;
				//printf("  %.2lf * costBad(%.2lf) = %.2lf\n", probBad,costBad,probBad*costBad);
			} else {
				t = prob*cost;
			}
			res = min(res, t);
						//printf("exp: %.2lf\n", t);
			
			su *= p[i];
		}
		printf("Case #%d: %.10lf\n",++cn,res);
	}
	return 0;
}
