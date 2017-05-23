#include <stdio.h>

long long answer();
long long bi(long long, long long);
long long r, t, an;

FILE *in = fopen("A-large.in", "r");
FILE *out = fopen("A-large.out", "w");

long long cal(long long n){

	return n * 2 * r + (n) * (2 * n - 1);

}
int main(){

	int T, i;

	fscanf(in, "%d", &T);

	for (i = 1; i <= T; i++){
	
		fscanf(in, "%lld %lld", &r, &t);

		fprintf(out, "Case #%d: %lld\n", i, answer());
	
	}

	return 0;

}
long long answer(){

	long long s = 1, e = 1;

	while (1){
	
		e *= 2;
		if (cal(e) >= t) break;
		s *= 2;
	
	}

	an = s;
	return bi(s, e);

}
long long bi(long long s, long long e){

	if (s > e) return an;

	long long mid = (s + e) / 2;
	
	if (cal(mid) < t){
		an = mid;
		bi(mid + 1, e);
	}else if (cal(mid) > t)
		bi(s, mid - 1);
	else 
		return mid;

}