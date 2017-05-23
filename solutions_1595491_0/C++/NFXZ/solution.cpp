#include <stdio.h>

int sum[105];

int main()
{
	int t,i,s,p,n,m,j,k;

	FILE* in;
	FILE* out;
	
	in=fopen("B-small-attempt0.in","r");
	out=fopen("B-small-attempt0.out","w");
	
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		fscanf(in,"%d %d %d",&n,&s,&p);
		//printf("%d \n",p);
		m=0;
		for(j=0;j<n;j++){
			fscanf(in,"%d",&sum[j]);
			
			if(p>sum[j])continue;
			
			if(3*p<=sum[j]){
				m++;
				continue;
			}

			k=(sum[j]-p)/2;
			
			if(p-k<2){
				m++;
			}
			else if(p-k==2&&s!=0){
				s--;m++;
			}
		}	
		
		fprintf(out,"%d\n",m);
	}
	fclose(in);
	fclose(out);
	return 0;
}

