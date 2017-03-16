#include <stdio.h>
#include <math.h>
int main()
{
	FILE *fin=fopen("ass.in","r");
	FILE *fout=fopen("outputt.txt","w");
	int t,tc=1;
	fscanf(fin,"%d\n",&t);
	
	for(tc=1;tc<=t;tc++)
	{
		int R,P,n,a,amax,t;
		fscanf(fin,"%d %d\n",&R, &P);
		a=0;n=0;
		//amax=sqrt(P/M_PI);printf("amax=%f|",amax);
		amax=P;
		//if((P-1-R)%4==0)
//			P=P-1;
//		else if((P-2-R)%4==0)
//			P=P-2;
//		else if((P-3-R)%4==0)
//			P=P-3;
		
		a=1+2*R;n=1;
		t=1+2*R;
		for(;1;)
		{
			a=a+4;
			t=t+a;
			if(t>P)
			break;
			n++;
		}
			
		fprintf(fout,"Case #%d: %d\n",tc,n);
	}
	
	
return 0;
}
