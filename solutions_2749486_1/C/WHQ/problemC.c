#include <stdio.h>
#include <string.h>
#define MIN(a,b) a<b?a:b
int sum;
int t,n,x,y,a,b;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j,k,w,q;
	int min1,min2;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d %d",&x,&y);
		if(x < 0){
			j = -x;
		}
		else{
			j = x;
		}
		
		if(y < 0){
			k = -y;
		}
		else{
			k = y;
		}
		if(j < k){
			min1 = 1;
			min2 = j;
		}
		else{
			min1 = 2;
			min2 = k;
		}
		n = j+k;
		sum = 0;
		for(q=1;sum <n || (sum-n)%2==1;q++){
			sum += q;
		}
		w = q-1;
		a = (sum-n)/2;
		b = 0;
		if(a == min2){
			b = min2+a;
		}	
		printf("Case #%d: ",i+1);
		for(q=1;q<=w;q++){
			if(b != 0 && q==b){
				if(min1 == 1){
					if(x > 0){
						printf("E");
					}
					else{
						printf("W");
					}
				}
				else{
					if(y > 0){
						printf("N");
					}
					else{
						printf("S");
					}
				}
			}
			else if(q==a){
				if(min1 == 1){
					if(x > 0){
						printf("W");
					}
					else{
						printf("E");
					}
				}
				else{
					if(y > 0){
						printf("S");
					}
					else{
						printf("N");
					}
				}
			}
			else{
				if(min1 == 1){
					if(x > 0){
						printf("E");
					}
					else{
						printf("W");
					}
				}
				else{
					if(y > 0){
						printf("N");
					}
					else{
						printf("S");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
