#include<stdio.h>
#include<algorithm>
main(){
	int T,TN;
	int i,j,k;
	int n,m;
	double a[222],sum,b[222],c[222],d,e;
	double bmin,bmax,bb;
	int bt;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%lf",&a[i]);
			sum+=a[i];
		}

		for(i=0;i<n;i++){
			b[i]=a[i]/sum*100;
			//printf("%lf ",b[i]);
		}
	//	puts("");
		printf("Case #%d: ",T);
		for(i=0;i<n;i++){
			bmin=0;
			bmax=100;
			bt=0;
			while(bt++<=100){
				bb=(bmin+bmax)/2;
				for(j=0;j<n;j++){
					if(j==i){
						c[j]=b[j]+bb;
						d=c[j];
					} else {
						c[j]=b[j];
					}
				}
				//printf("%lf;;",d);
				e=0;
				for(j=0;j<n;j++){
					if(c[j]<d){
						e+=d-c[j];
					}
				}
				//printf("%lf %lf;",e,100-bb);
				if(e>100-bb){
					bmax=bb;
					//putchar('a');
				} else {
					bmin=bb;//putchar('b');
				}
			}
			printf("%lf ",bmax);
		}
		puts("");
		
		
	}
}
