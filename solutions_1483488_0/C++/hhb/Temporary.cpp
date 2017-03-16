#include<stdio.h>

bool hash[2000001];
int stk[16];
long long solve() {
	int A, B;
	scanf("%d%d", &A, &B);
	int len=0, wt=1;
	for(int n=A;n>0;n/=10) {
		len++;
		wt*=10;
	}
	wt/=10;
	long long res=0;
	for(int i=A;i<=B;i++) {
		int r=10, l=wt, p=0;
		for(int j=1;j<len;j++) {
			int t=i%r*l+i/r;
			if(t>i&&t<=B&&!hash[t]) {
				res++;
				hash[t]=true;
				stk[p++]=t;
			}
			r*=10;
			l/=10;
		}
		for(int i=0;i<p;i++) hash[stk[i]]=false;
	}
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;c++) {
		printf("Case #%d: %lld\n", c, solve());
	}
}