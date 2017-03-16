#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int tt;
	scanf("%d",&tt);
	for(int t=1;t<=tt;t++){
		int m,n,k;
		scanf("%d%d%d",&m,&n,&k);
		if(k<4){
			printf("Case #%d: %d\n",t,k);
		}
		else{
			int min=k;
			for(int i=1;i<=m-2;i++)
				for(int j=1;j<=n-2;j++){
				//	printf("%d %d\n",i*2+j*2+i*j,i*2+j*2);
					if(i*2+j*2+i*j>=k-4){
						int jj=k-(i*2+j*2+i*j);
						if(jj<0)jj=0;
						if(min>(i*2+j*2+jj)){
							min=i*2+j*2+jj;
							//printf("m:%d %d %d\n",min,i,j);
						}
					}
				}
			printf("Case #%d: %d\n",t,min);
		}
	}
	return 0;
}