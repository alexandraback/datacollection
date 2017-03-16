#include <bits/stdc++.h>

int h[60][60];
int res[60][60];
int num[3000];

using namespace std;

int main(){
	int t;
	scanf(" %d", &t);
	for(int k = 1; k <= t; k++){
		int n;
		scanf(" %d", &n);
		for(int i = 0; i <=2500; i++){
			num[i] = 0;
		}
		for(int i = 0; i < 2*n-1; i++){
			for(int j = 0; j < n; j++){
				int aux;
				scanf(" %d", &aux);
				num[aux]++;
				//printf("num[%d] = %d\n", aux, num[aux]);
			}
		}
		printf("Case #%d:", k);
		for(int i = 0; i <= 2500; i++){
			if(num[i]%2 != 0){
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
		