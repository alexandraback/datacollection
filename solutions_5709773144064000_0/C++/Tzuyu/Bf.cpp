#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int T,ti,i,j;
	double C,F,X,sum,t,v,k;
	FILE * inf, * outf;
	inf=fopen("B-small-attempt0.in.txt","r");
	outf=fopen("B-small.out","w");
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		fscanf(inf,"%lf%lf%lf",&C,&F,&X);
		v=2;
		t=0;
		if (C>X){
			t=X/v;
		}
		else{
			k=(X*F-C*v-C*F)/(C*F);
			for(t=0,i=0;i<k;i++){
				t+=C/(v+i*F);
			}
			t+=X/(v+i*F);
		}
		fprintf(outf,"Case #%d: %.7lf\n",ti+1,t);
	}
	fclose(inf);
	fclose(outf);
	return 0;
}
