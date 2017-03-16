#include <stdio.h>
#include <math.h>

int f[10];

int G10[10]={
	1,10,100,1000,10000,100000,1000000,
	10000000,100000000,1000000000
};

int main()
{
	int t,i,A,B,c,j,k,l,h,n,m,flag;

	FILE* in;
	FILE* out;
	
	in=fopen("C-large.in","r");
	out=fopen("C-large.out","w");
	
	fscanf(in,"%d",&t);
	
	for(i=1;i<=t;i++)
	{
		
		fprintf(out,"Case #%d: ",i);
		
		fscanf(in,"%d %d",&A,&B);

		c=0;
			
		for(j=A;j<B;j++){
			h=j;
			n=(int)log10(A);
			for(k=0;k<n;k++){
				m=h%10;
				h=h/10+G10[n]*m;
				
				f[k]=h;
				flag=1;
				for(l=0;l<k;l++){
					if(f[l]==h){
						flag=0;break;
					}
				}
				
				if(flag&&h>j&&h<=B){
					c++;
					//printf("%d\n",h);
				}
			}
		}
		
		fprintf(out,"%d\n",c);
		//printf("\n");
	}
	
	fclose(in);
	fclose(out);
	return 0;
}

