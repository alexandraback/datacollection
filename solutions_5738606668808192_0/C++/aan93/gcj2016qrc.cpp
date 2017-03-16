#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
FILE *in,*out;
string nexts(string p) {
	for (int i=(int)p.size()-2;i>=1;i--) {
		if (p[i]=='0') {
			p[i] = '1';
			for (int j=i+1;j<=(int)p.size()-2;j++) {
				p[j] = '0';
			}
			return p;
		}
	}
	return p;
}
int main()
{
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int t,n,j;
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++) {
		fscanf(in,"%d%d",&n,&j);
		vector <long long int> a(9,0);
		for (int k=0;k<9;k++) {
			a[k] = 1;
			for (int l=0;l<n/2;l++) a[k] *= (k+2);
			a[k] += 1;
		}
		fprintf(out,"Case #%d:\n",i);
		string z("1");
		for (int k=0;k<n/2-2;k++) z+="0";
		z+="1";
		for (int k=0;k<j;k++) {
			fprintf(out,"%s%s",z.c_str(),z.c_str());
			for (int l=0;l<9;l++) fprintf(out," %lld",a[l]);
			z = nexts(z);
			fprintf(out,"\n");
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
