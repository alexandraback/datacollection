#include<stdio.h>

__int64 f(__int64 a, __int64 b){
	if(b == 0) return a;
	else return f(b,a%b);
}
int main()
{
	FILE *fi=fopen("input.txt","r");
	FILE *fo=fopen("output.txt","w");
	__int64 p,q,r,i,temp,chk=1;
	int m,t;

	fscanf(fi,"%d",&t);
	for(m=0;m<t;m++){
		fscanf(fi,"%I64d/%I64d",&p,&q);
		fprintf(fo,"Case #%d: ",m+1);
		if(p == q) {fprintf(fo,"1\n"); continue;}
		if(p == 0 || p>q) { fprintf(fo,"impossible\n"); continue;}

		temp = f(p,q);
		p=p/temp;
		q=q/temp;
		chk = 1;
		while(1){
			if(chk>=q) break;
			chk*=2;
		}
		if(chk!=q){fprintf(fo,"impossible\n"); continue;}
		r=2;
		for(i=1;;i++,r*=2){
			if(r*p-q >=0) break;
		}
		fprintf(fo,"%d\n",i);
	}
	return 0;
}