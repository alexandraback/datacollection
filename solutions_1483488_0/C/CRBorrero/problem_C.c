#include <stdio.h>
#include <stdlib.h>

int len(int x){
	if (x<10)		return 1;
	if (x<100)		return 2;
	if (x<1000)		return 3;
	if (x<10000)	return 4;
	if (x<100000)	return 5;
	if (x<1000000)	return 6;
	if (x<10000000)	return 7;
}

int mypow(int base, int potencia){
	int res = 1;
	if (potencia >= 1) res *= base;
	if (potencia >= 2) res *= base;
	if (potencia >= 3) res *= base;
	if (potencia >= 4) res *= base;
	if (potencia >= 5) res *= base;
	if (potencia >= 6) res *= base;
	if (potencia >= 7) res *= base;
	return res;
}

int rotate(int x, int take){

	int xlen = len(x);
	
	// no se puede girar tanto
	if (xlen <= take || take == 0)
		return x;
		
	int datnumber = mypow(10,take);
		
	int final = x%datnumber;
	int principio = x/datnumber;
	
	int datothernumber = mypow(10,xlen-take);
	
	int res = final*datothernumber;
	res += principio;
	
	return res;
}

int main(){

	int anteriores[10];
	int ndc;
	int caso;
	scanf("%d\n",&ndc);
	
	for(caso=0; caso<ndc; caso++){
		
		int A, B;
		scanf("%d %d\n",&A,&B);
		
		int i, j;
		/*int *revisado = (int*)malloc(sizeof(int)*2000001);
		for(i=0;i<2000001; i++){
			revisado[i] = 0;
		}*/
		
		int n = A; // el primero del par
		if (n<12) n=12;
		
		int c = 0; // contador de pares
		int m = 0; // el segundo del par
		int rev = 0;
		
		// remember! A <= n < m <= B
		for(;n<B;n++){
			
			/*if (revisado[n]) {
				continue;
			} else {
				revisado[n] = 1;*/
				rev++;
				int nlen = len(n);
				for (i=1; i<nlen; i++){
				
					m = rotate(n,i);
					
					int con = 0;
					for (j=0; j<i-1; j++){
						if (anteriores[j]==m){
							con = 1;
							break;
						}
					}
					anteriores[i-1] = m;
					if (con) continue;
					
					if (m>n && m<=B){
						c++;
						//printf("(%d,%d)\n",n,m);
					}
					rev++;
				}
			//}
			
		}
		//free(revisado);
		printf("Case #%d: %d\n",caso+1,c);
	}
	return 0;
}
