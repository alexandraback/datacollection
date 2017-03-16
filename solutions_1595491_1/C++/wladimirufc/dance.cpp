#include <stdio.h>

int max_result(int n){
	int k,x,max;
	for(k=10;k>=0;k--){
		x = n-k;
		if(x < 0) continue;
		x = x/2;
		if( k > x && k-x < 2 ) return k;
		if( x > k && x-k < 2 ) return x; 
	}
	
	//printf("maior pontuacao %d\n",0);
	return 0; 
}


int max_result_surp(int n){
	int k,x,max;
	for(k=10;k>=0;k--){
		x = n-k;
		if(x<0) continue;
		x = x/2;
		if( k > x && k-x <= 2 ) return k;
		if( x > k && x-k <= 2 ) return x;
	}
	
	//printf("maior pontuacao surp %d\n",0);
	return 0;
}

int main(){

	int t;
	int n,s,p,i,teste=1;
	int v[101];
	int cont;
	scanf("%d",&t);
	
	
	while(t--){
		scanf("%d %d %d",&n,&s,&p);
			
		cont = 0;	
		for(i=0;i<n;i++){
			scanf("%d",&v[i]);
			
			
			if( max_result(v[i]) >= p ) { cont++; }
			else if( s > 0 && max_result_surp(v[i]) >= p  ){
				cont++;
				s--;
			}
			
		}
		
		printf("Case #%d: %d\n",teste++,cont);
			
	}

}
