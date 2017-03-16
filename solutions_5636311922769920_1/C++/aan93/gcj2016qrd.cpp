#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
FILE *in,*out;
int main()
{
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int t;
	int k,c,s;
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++) {
		fscanf(in,"%d%d%d",&k,&c,&s);
		fprintf(out,"Case #%d:",i);
		if (k>c*s) fprintf(out," IMPOSSIBLE\n");
		else {
			for (int j=0;j<k;j+=c) {
				long long int d(0);
				for (int l=j;l<j+c && l<k;l++) d = d*k + l;
				fprintf(out," %lld",d+1);
			}
			fprintf(out,"\n");
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
