#include <cstdio>
#include <cstdlib>

int T,N;
double ns[1008];
double ks[1008];
int rem[1008];
int cmp(const void *ka,const void *kb) {
	double a=*(double *)ka;
	double b=*(double *)kb;
	if(a<b) return -1;
	if(a>b) return 1;
	return 0;
}
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%lf",&ns[i]);
		for(int i=0;i<N;i++) {
			scanf("%lf",&ks[i]);
			rem[i]=1;
		}
		qsort(ns,N,sizeof(double),cmp);
		qsort(ks,N,sizeof(double),cmp);
		int solx=N;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(rem[j]==1&&ks[j]>ns[i]) {
					rem[j]=0;
					solx--;
					break;
				}
			}
		}
		int soly=0;
		for(int i=0;i<N;i++) {
			int flg=1;
			for(int j=i;j<N;j++) {
				if(ns[j]<ks[j-i]) flg=0;
			}
			if(flg) {
				soly=N-i;
				break;
			}
		}
		printf("Case #%d: %d %d\n",ts,soly,solx);
	}
	return 0;
}
