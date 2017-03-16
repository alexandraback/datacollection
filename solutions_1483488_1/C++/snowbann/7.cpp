#include<stdio.h>
int main()
{
	int T;
	int A,B;
	int n,m;
	int count;
	int t;
	int k,l;
	int a[10];
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&A,&B);
		count=0;
		for(int j=A;j<=B;j++){
			n=10;
			m=10;
			l=0;
			k=0;
			while(j/m!=0)
				m*=10;

			while(j/n!=0){
				t=(j%n)*(m/n)+j/n;
				if((t>j&&t<=B)||(j%n==0&&t>=A)){
					if(l>0){
						for(k=0;k<l;k++)
							if(t==a[k])
								break;
					}
					if(k>=l){
						count++;
						a[l++]=t;
					}
				}
				n*=10;
			}
		}
		printf("Case #%d: %d\n",i,count);
	}
	return 0;
}
