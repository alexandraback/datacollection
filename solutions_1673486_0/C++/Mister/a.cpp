#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		int A,B;
		double pdt = 1, ans;
		scanf("%d%d",&A,&B);
		ans = min(2 + B, 2*A + B - A + 1);
		for(int i=1;i<=A;++i) {
			double p;
			scanf("%lf",&p);
			pdt *= p;
			ans = min(ans, (1-pdt)*(2*(A-i)+2*B-A+2) + pdt*(2*(A-i)+B-A+1));
		}
		printf("Case #%d: %.9lf\n",cn,ans);
	}
}
