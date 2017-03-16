#include<stdio.h>

int main()
{
	int T,t;
	double time=0,F,C,X,r;
	FILE *fi,*fo;
	fi=fopen("B-small-practice.in","r");
	fo=fopen("B-small-practice.out","w");
	
	fscanf(fi,"%d",&t);
	for(T=1;T<=t;T++) {
		time=0;
		fprintf(fo,"Case #%d: ",T);
		r=2;
		fscanf(fi,"%lf %lf %lf",&C,&F,&X);
		while(X/r>C/r+X/(r+F))
		{
			time=C/r+time;
			r=r+F;
		}
		time=time+X/r;
		fprintf(fo,"%0.7lf\n",time);
	}
	fclose(fi);
	fclose(fo);
	return 0;
}

