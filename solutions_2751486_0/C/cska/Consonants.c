#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define C(c) ((c)=='a' || (c)=='e' || (c)== 'i' || (c)=='o' || (c)=='u')

typedef long long int ll;

int nvalue(char *s,int k,int n) {
	ll i,m,r;
	for(r=i=0;i<k;i++) {
		for(m=0;i<k && !C(s[i]);i++,m++);
		if(m>=n) r+=1;
		if(m!=0) i--;
	}
	return r!=0;
}
int gendigits(char *o,int k,int n) {
	int i,j;
	for(i=k-1;i>=0 && o[i]==i+n+1-k;i--);
	if(i>=0) for(o[i]++,j=i+1;j<=k-1;j++) o[j]=o[j-1]+1;
	return i>=0;
}

int main(void) {
	char o[2],*s,*s2;
	int i,k,l,t,n;
	ll N;
	FILE *fin=fopen("A-small-attempt2.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%d",&t);

	s=malloc(1000000);
	s2=malloc(1000000);

	for(k=0;k<t;k++) {
		fscanf(fin,"%s%d",s,&n);

		N=0;
		if(strlen(s)!=1) {
		for(i=0;i<2;i++) o[i]=i;
		do {
			for(l=0,i=o[0];i<=o[1];s2[l++]=s[i++]);
			s2[l]=0;
			N+=nvalue(s2,l,n);
		} while(gendigits(o,2,strlen(s)-1));
		}

		for(i=0;i<strlen(s);i++)
			N+=nvalue(s+i,1,n);

		fprintf(fout,"Case #%d: %lld\n",k+1,N);
		//system("pause");
	}

	fclose(fin);
	fclose(fout);
	free(s);
	return 0;
}
