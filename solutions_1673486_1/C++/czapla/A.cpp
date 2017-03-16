#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		long double wyn = 100000000.0, pdobrze = 1.0, p;
		int A, B;
		scanf("%d %d", &A, &B);
		for(int i = 1; i <= A; i++){
			scanf("%Lf", &p);
			pdobrze *= p;
			wyn = min(wyn, pdobrze*(B-A+(A-i)*2+1)+(1.0-pdobrze)*(B+B-A+(A-i)*2+2));
		}
		
		
		wyn = min(wyn, (long double)(B+2));
		
		printf("Case #%d: %Lf\n", t, wyn);
	}
	return 0;
}
