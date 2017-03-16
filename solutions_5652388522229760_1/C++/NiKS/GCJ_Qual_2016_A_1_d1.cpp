#include<cstdio>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define MAXN 1001001
#define MAXM 10001

int T, n, bm, a[1001100];
long long m, p;

int main(){
	REP(N, 1, MAXN){
		//printf("%d\n", N);
		bm = 0;
		a[N] = 0;
		REP(i, 1, MAXN){
			m = i;
			p = N*m;
			while(p){
				int d = p%10;
				bm = bm|(1<<d);
				p /= 10;
			}
			//printf("%d %x\n", i, bm);
			if(bm==((1<<10)-1)){
				a[N] = N*m;
				break;
			}
		}
	}
	a[0] = 0;
	scanf("%d", &T);
	REP(t, 1, T+1){
		printf("Case #%d: ", t);
		scanf("%d", &n);
		if(a[n]) printf("%d", a[n]);
		else printf("INSOMNIA");
		printf("\n");
	}
	return 0;
}
