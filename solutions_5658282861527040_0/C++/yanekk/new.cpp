#include <stdio.h>

using namespace std;

int Ile[2000];

int main(){
	int t,i,j,l;
	int a,b,k,wynik;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d%d%d", &a,&b,&k);
		for(j=0; j<2000; j++) Ile[j] = 0;
		for(j=0; j<a; j++){
			for(l=0; l<b; l++){
				Ile[ j&l ]++;
			}
		}
		wynik = 0;
		for(j=0; j<k; j++) wynik += Ile[j];
		printf("Case #%d: %d\n", i+1, wynik);
	}
	return 0;
}
