#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

long long int P, Q;
FILE *in = fopen("A-large.in", "r");
FILE *out = fopen("output.txt", "w");

long long int gcd(long long int a, long long int b){
	long long int g;
	while (!(b%a == 0)){
		b -= (long long int)(b / a) * a;
		g = b;
		b = a;
		a = g;
	}
	g = a;
	return g;
}

int main(){
	int T, tests;
	fscanf(in, "%d", &T);
	tests = T;
	while (T--){
		fscanf(in, "%lld/%lld", &P, &Q);
		long long int g = gcd(P, Q);
		P /= g;
		Q /= g;
		fprintf(out, "case #%d: ", tests - T);
		if ((long long int)pow(2, 40) % Q != 0) fprintf(out, "impossible\n");
		else{
			P *= ((long long int)pow(2, 40) / Q);
			Q = (long long int)pow(2, 40);
			for (int i = 39; i >= 0; i--){
				if (P >= (long long int)pow(2, i)){
					fprintf(out, "%d\n", 40 - i);
					break;
				}
			}
		}
	}
	fcloseall();
	return 0;
}