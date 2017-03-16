#include <stdlib.h>
#include <stdio.h>

typedef long long int ll;

int main(void) {
	char s[600];
	ll t,x,y,
		k,i,j,l,
		ax,ay,
		jump;
	FILE *fin=fopen("B-small-attempt0.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%lld",&t);

	for(k=0;k<t;k++) {
		fscanf(fin,"%lld%lld",&x,&y);

		ax=abs(x),ay=abs(y);
		for(l=i=j=0,jump=1;i!=ax;jump++) {
			if(i+jump==ax) s[l++]=(x==ax?'E':'W'),i+=jump;
			else {
				if(j+jump==ay) s[l++]=(y==ay?'N':'S'),j+=jump;
				else {
					if(i+jump<=ax) s[l++]=(x==ax?'E':'W'),i+=jump;
					else s[l++]=(x==ax?'W':'E'),i-=jump;
				}
			}
		}
		for(;j!=ay;jump++) {
			if(j+jump<=ay) s[l++]=(y==ay?'N':'S'),j+=jump;
			else s[l++]=(y==ay?'S':'N'),j-=jump;
		}
		if(l>500) printf("Error\n");
		s[l]=0;
		fprintf(fout,"Case #%lld: %s\n",k+1,s);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
