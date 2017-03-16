#include <cstdio>
#include <cmath>
#include <cstdlib>
const int MaxN= 222;
typedef double dbl;
int T, N, l, r, CaseCount;
dbl s[MaxN], X;
bool check(dbl x, int idx){
	dbl tmp= 1.0-x;
	dbl sig= s[idx] + X*x;
	for(int i= 1;i<= N;++ i) if(i!=idx)
		if(s[i] < sig)
			tmp-= (sig-s[i])/X;
	return tmp <= 0.0;
}
int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T --){
		X= 0;
		scanf("%d", &N);
		for(int i= 1;i<= N;++ i){
			scanf("%lf", s+i);
			X+= s[i];
		}
		printf("Case #%d: ", ++ CaseCount);
		for(int i= 1;i<= N;++ i){
			dbl l= 0.0, r= 100.0;
			while(fabs(r-l)>1e-8)
				check((l+r)/200.0, i) ? r= (l+r)/2.0 : l= (l+r)/2.0;
			printf(i==N ? "%lf\n" : "%lf ", l);
		}
	}
//	system("pause");
	return 0;
}
