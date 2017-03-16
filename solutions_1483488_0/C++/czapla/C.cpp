#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long LL;

LL A, B, wyn, m, pot10, cyfry;
LL wyniki[10], ilewyn;

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		printf("Case #%d: ", t);
		scanf("%lld %lld", &A, &B);
		wyn = 0;
		for(LL n = A; n < B; n++){
			pot10 = 1;
			while(pot10 <= n)
				pot10 *= 10;
			ilewyn = 0;
//printf("pot10: %lld %lld\n", n, pot10);
			for(LL i = 10; i < pot10; i *= 10){
				m = n%i*(pot10/i) + n/i;
				if(m > n && m <= B){
					cyfry = 1;
					while(cyfry <= m)
						cyfry *= 10;
					if(cyfry==pot10)
						wyniki[ilewyn++] = m;
				}
//printf("%lld %lld\n", n, m);
			}
			sort(wyniki, wyniki+ilewyn);
			wyn += LL(unique(wyniki, wyniki+ilewyn)-wyniki);
		}
		printf("%lld\n", wyn);
	}
	return 0;
}
