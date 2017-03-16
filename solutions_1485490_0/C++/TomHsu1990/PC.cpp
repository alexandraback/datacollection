#include <stdio.h>
int c, m, n;
struct box{
	long long n, t;
};
struct box B[200], P[200], GG[200];
int main(){
	scanf("%d", &c);
	for(int i=1;i<=c;++i){
		scanf("%d%d", &m, &n);
		for(int j=1;j<=m;++j)
			scanf("%lld%lld", &B[j].n, &B[j].t);
		for(int j=1;j<=n;++j){
			scanf("%lld%lld", &P[j].n, &P[j].t);
		}
		long long mm = 0;
		for(int j=1;j<=n;++j){
			for(int k=j;k<=n;++k){
				long long r1 = 0, r2 = 0, r3 = 0;
				long long left1 = B[1].n, left2 = B[2].n, left3 = B[3].n;
				for(int l=1;l<=n;++l){
					GG[l].n = P[l].n;
				}
				for(int l=1;l<=n;++l){
					if(l <= j){
						if(P[l].t == B[1].t){
							if(left1-GG[l].n >= 0){
								r1 += GG[l].n;
								left1 -= GG[l].n;
								GG[l].n = 0;
							}
							else{
								r1 += left1;
								left1 = 0;
								GG[l].n -= left1;
							}
						}
					}
					if(l >= j && l <= k){
						if(P[l].t == B[2].t){
							if(left2-GG[l].n >= 0){
								r2 += GG[l].n;
								left2 -= GG[l].n;
								GG[l].n = 0;
							}
							else{
								r2 += left2;
								left2 = 0;
								GG[l].n -= left2;
							}
						}
					}
					if(l >= k){
						if(P[l].t == B[3].t){
							if(left3-GG[l].n >= 0){
								r3 += GG[l].n;
								left3 -= GG[l].n;
								GG[l].n = 0;
							}
							else{
								r3 += left3;
								left3 = 0;
								GG[l].n -= left3;
							}
						}
					}
				}
				if(mm < r1+r2+r3) mm = r1+r2+r3;
			}
		}
		printf("Case #%d: %lld\n", i, mm);
	}
	return 0;
}
