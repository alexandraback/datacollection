#include <stdio.h>

int main(){

	/*freopen("B/in.txt","r",stdin);
	freopen("B/out.txt","w",stdout);*/

	long int T;
	scanf("%ld",&T);
	for(int t=1;t<=T;t++){
		long int E,R,N;
		scanf("%ld%ld%ld",&E,&R,&N);
		long int v[N];

		for(int i=0;i<N;i++)
			scanf("%ld",&v[i]);

		long int sum = 0;
		long int ene = E;
		for(int i=0;i<N;i++){
			long int save = 0;
			int n=i+1;
			while(1){
				if(v[n] > v[i] || (n-i) == (E/R)  || n >= N-1 ){

					if(v[n] > v[i] && i<N-1)
						save = E-(R*(n-i));
					break;
				}else{
					n++;
				}
			}

			if(save == 0){
				sum += ene*v[i];
				ene = 0;
			}else{
				if(save < ene){
					sum += (ene-save)*v[i];
					ene = save;
				}
			}
			ene += R;
			if(ene > E)
				ene = E;
		}


		printf("Case #%d: %ld\n",t,sum);
	}
}

