#include <stdio.h>

long long int_pow(int k, int c) {
	if (c < 0) return 0;
	long long r = 1;
	for (int i = 0; i < c; i++)
		r *= k;
	return r;
}

long long recurse_skip(int pos, int k, int c) {
	if (c <= 1)
		return pos;
	return pos*int_pow(k,c-1) + recurse_skip(pos, k, c-1);
}

long long calc(int a, int b, int k, int c) {
	//printf("[%d %d]\n",a,b);
	//printf("[%d %d]\n",a*int_pow(k,c-1),recurse_skip(b,k,c-1));
	return a*int_pow(k,c-1)+recurse_skip(b,k,c-1);
	
	printf("[%d %d]\n",a,b);
	long long skip2 = int_pow(k,c-2);
	long long skip1 = skip2*k;
	printf("[%d %d]\n",skip1,skip2);
	long long r = a*skip1;
	r += b*skip2;
	r += b;
	return r;
}

int main() {
	int __;
	scanf("%d",&__);
	for (int _ = 1; _ <= __; _++) {
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		if (s < k/2 || (c==1&&s<k)) {
			printf("Case #%d: IMPOSSIBLE\n",_);
		} else if (c == 1) {
			printf("Case #%d: ",_);
			for (int i = 1; i <= k; i++) {
				printf("%d ", i);
			}
			printf("\n");
		} else {
			printf("Case #%d: ",_);
			int h = (k+1)/2;
			int t = k;
			for (int i = 0; i < h; i++) {
				printf("%lld ", calc(i,--t,k,c)+1);
			}
			printf("\n");
		}
	}
	return 0;
}

