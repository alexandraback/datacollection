#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int digits(int);
int power(int,int);

int main(void) {
	int i,j,l,
		d,k,s,
		t[8],
		n,m,
		T,A,B;
	FILE *fin=fopen("C-small-attempt0.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%d",&T);

	for(i=0;i<T;i++) {
		fscanf(fin,"%d%d\n",&A,&B);
		for(s=0,d=digits(A),n=A;n<B;n++)
			for(k=0,j=1;j<d;j++) {
				m=n%power(10,j)*power(10,d-j)+n/power(10,j);
				if(m>n && m<=B) {
					for(l=0;l<k && t[l]!=m;l++);
					if(l==k) t[k++]=m,s+=1;
				}
			}
		fprintf(fout,"Case #%d: %d\n",i+1,s);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

int digits(int n) {
	return n?1+digits(n/10):0;
}

int power(int n,int k) {
	int i;
	for(i=n,n=1;--k>=0;n*=i);
	return n;
}
