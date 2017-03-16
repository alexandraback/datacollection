#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	FILE * rfp;
	FILE * wfp;
	
	int n,t,i,j,k,a,b;
	double rp,minH,H,p;
	
	rfp=fopen("A-large.in","r");
	wfp=fopen("A-large.out","w");
	
	fscanf(rfp,"%d",&t);
	
	for(i=1;i<=t;i++){
		fprintf(wfp,"Case #%d: ",i);
		fscanf(rfp,"%d %d",&a,&b);
		
		minH=2+b;rp=1;
		for(j=a-1;j>=0;j--){
			fscanf(rfp,"%lf",&p);
			rp=p*rp;
			H=rp*(j*2+b-a+1)+(1-rp)*(j*2+b*2-a+2);
			if(H<minH){
				minH=H;
			}
		}
		fprintf(wfp,"%.6lf\n",minH);
	}

	fclose(rfp);
	fclose(wfp);
	return 0;
}