#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T, u, L, resp, aux, prox;
long long int X, N;
char c;
int v[10010];

int sign(int a){
	if(a>0) return 1;
	if(a<0) return -1;
	return 0;
}

int mult_abs(int a, int b){
	if(a == 1) return b;
	if(b == 1) return a;
	if(a == b) return -1;
	if(a == 2){
		if(b == 3) return 4;
		if(b == 4) return -3;
	}
	if(a == 3){
		if(b == 2) return -4;
		if(b == 4) return 2;
	}
	if(a == 4){
		if(b == 2) return 3;
		if(b == 3) return -2;
	}
}

int mult(int a, int b){
	return sign(a)*sign(b)*mult_abs(abs(a),abs(b));
}

bool check_possible(){
	if(aux == 1) return false;
	if(aux == -1) return (X%2LL == 1LL);
	return (X%4LL == 2LL);
}

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d %lld", &L, &X);
		aux = 1;
		for(int i=0; i<L; i++){
			scanf(" %c", &c);
			v[i] = c - 'i' + 2;
			aux = mult(aux, v[i]);
		}
		
		resp = 0;
		if(check_possible()){
			N=10LL;
			if(X<N) N=X;
			
			aux = 1;
			prox = 2;
			
			for(int k=0; k<N; k++){
				for(int i=0; i<L; i++){
					aux = mult(aux, v[i]);
					if(aux == prox){
						prox++;
						aux = 1;
						if(prox == 4) resp = 1;
					}
				}
			}
		}
		
		if(resp == 0) printf("Case #%d: NO\n", u);
		else printf("Case #%d: YES\n", u);
	}
	return 0;
}
