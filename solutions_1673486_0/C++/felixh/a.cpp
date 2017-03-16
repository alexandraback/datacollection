#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

double P[1000010];
int T,A,B;

int main(){
	scanf("%d",&T);
	for (int tc=1; T--; tc++){
		scanf("%d %d",&A,&B);

		double prob = 1.0;
		REP(i,A){
			scanf("%lf",&P[i]);
			prob *= P[i];
		}

		// press enter right away
		double res = B + 2;

		// press backspace i times, and complete
		for (int i=0; i<=A; i++){
			double rem = B - A + i*2 + 1;
			double cur = prob * rem + (1.0-prob) * (rem+B+1);
			res = min(res, cur);
			if (A-i-1 >= 0) prob /= P[A-i-1];
		}

		printf("Case #%d: %.6lf\n",tc,res);
	}
}
