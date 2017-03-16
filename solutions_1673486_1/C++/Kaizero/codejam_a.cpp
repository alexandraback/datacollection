#include<stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int t,n,a,b,i,m,c;
double w[100000],p,pp,res,rr;
int main(){
	fscanf(in,"%d",&t);
	while(t){
		c++;
		t--;
		fscanf(in,"%d%d",&m,&n);
		for(i=0;i<m;i++)fscanf(in,"%lf",&w[i]);
		res=m+n+1;
		if(res>n+2)res=n+2;
		pp=0,p=1;
		for(i=0;i<m;i++){
			pp+=(1.0-w[i])*p;
			rr=(1-pp)*(m-i-1+n-i)+pp*(m-i-1+n-i+n+1);
			if(res>rr)res=rr;
			p*=w[i];
		}
		fprintf(out,"Case #%d: %.6lf\n",c,res);
	}
}