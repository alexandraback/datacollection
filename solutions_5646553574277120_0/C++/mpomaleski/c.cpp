#include <bits/stdc++.h>

using namespace std;

int val[70];
int have[70];

int main(){
	int t;
	scanf("%d", &t);
	for(int k = 1; k <= t; k++){
		int c, d, v;
		for(int i = 1; i < 32; i++){
			val[i] = 0;
			have[i] = 0;
		}
		have[0] = 1;
		val[0] = 1;
		scanf(" %d %d %d", &c, &d, &v);
		int aux;
		for(int i = 2; i < d+2; i++){
			scanf(" %d", &aux);
			have[aux] = 1;
			for(int j = 0; j < v; j++){
				if(val[j] > 0 && val[j] != i)
					val[j+aux] = i;
			}
		}
		
		int res = 0;
		int j = 0;
		for(int i = 1; i <= v; i++){
			if(val[i] == 0){
				j = i;
				have[j] = 1;
				res++;
				aux = j;
				for(j = 0; j < v; j++){
					if(val[j] > 0 && val[j+aux] == 0 && val[j] != i+40){
						val[j+aux] = i+40;
					}
				}
			}
		}
		
		printf("Case #%d: %d\n", k, res);
	}
	return 0;
}
		