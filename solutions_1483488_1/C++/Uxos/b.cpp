#include<stdio.h>
#include<string.h>
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int A,B,T,pot=1,tot=0;
	int ps[] = {1,10,100,1000,10000,100000,1000000};
	int arr[10];
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		pot=1;
		tot=0;
		scanf("%d %d",&A,&B);
		int nd = 0;
		int aux = A;
		while( aux ){
			aux/=10;
			nd++;
		}
		for(int n=A;n<=B;n++ ){
			pot=1;
			int c=0;
			int p = 0;
			while(pot < nd){
				int m = n%ps[pot] * ps[nd-pot] + n/ps[pot];
				if( m >= A && m <= B && m > n ){
				   int pon = 1;
				   for(int l=0;l<p;l++)
					if( arr[l] == m ) 
						pon = 0;
				   if(pon){
					c++;	
					arr[p++] = m;
				   }
				}
				pot++;
			}
			tot+=c;
		}
		printf("Case #%d: %d\n",k,tot);
	}
	return 0;
}

