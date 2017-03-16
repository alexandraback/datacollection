#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

long long mc(long long a, long long b){
	if (a==0) return b;
	if (b==0) return a;
	if (a>=b) return mc(a%b,b);
	else return mc(a,b%a);
}

int di(long long a){
	if (a==0) return 1;
	if (a==1) return 1;
	while (a>1){
		if (a%2==0) a/=2;
		else {
			if (a!=1) return 0;
		}
	}
	return 1;
}

int main(){
	int T,ti;
	int i,flag;
	long long p,q;
	long long fq,fp,mi;
	FILE * inf, * outf;
	inf=fopen("A-large.in","r");
	outf=fopen("A-large.out","w");
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		flag=0;
		fscanf(inf,"%lld/%lld",&p,&q);
		mi=mc(p,q);
		fq=q/mi;
		fp=p/mi;
		flag=di(fq);
		i=0;
		if (flag==1) while (fq>fp) {
			fq/=2;
			i++;
		}
		if (flag==1) fprintf(outf,"Case #%d: %d\n",ti+1,i);
		else fprintf(outf,"Case #%d: impossible\n",ti+1);
	}
	fclose(inf);
	fclose(outf);
	return 0;
}
