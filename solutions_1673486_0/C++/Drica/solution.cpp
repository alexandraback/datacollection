#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;


double acu[100010];
int A, B;
int main(){
	int casos, caso;
	scanf("%d", &casos);
	acu[0] = 1; caso = 0;
	while(casos--){ ++caso;
		scanf("%d%d", &A, &B);
		for(int i = 1; i <= A; ++i){
			scanf("%lf", &acu[i]);
			acu[i] *= acu[i-1];
		}
		double prob, menor = 9999999999;
		menor = acu[A]*(B-A+1) + (1-acu[A])*(B+B-A+2);
		prob = 2+B;
	//	printf("%lf %lf\n", prob, menor);
		if(prob < menor) menor = prob;
		for(int backs = A; backs > 0; --backs){
			prob = acu[A-backs]*(backs+(B-(A-backs)+1)) + (1-acu[A-backs])*(backs+(B-(A-backs))+2+B);
		//	printf("%lf\n", prob);
			if(prob < menor) menor = prob;
			
		}
		printf("Case #%d: %.6lf\n", caso, menor);
		
		
	}
	
	return 0;
}