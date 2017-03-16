#include <stdio.h>
#include <string.h>

int T, u, N, resp, aux;
int v[1010];

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d", &N);
		for(int i=0; i<N; i++){
			scanf(" %d", &v[i]);
		}
		resp = 1000000000;
		for(int k=1; k<=1000; k++){
			aux = k;
			for(int i=0; i<N; i++){
				aux += (v[i] - 1)/k;
			}
			if(aux < resp) resp = aux;
		}
		printf("Case #%d: %d\n", u, resp);
	}
	return 0;
}
