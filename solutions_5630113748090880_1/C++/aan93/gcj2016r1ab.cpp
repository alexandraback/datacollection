#include <stdio.h>
#include <vector>
using namespace std;
FILE *in,*out;
int main()
{
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int t;
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++) {
		int n,b;
		fscanf(in,"%d",&n);
		vector <int> a(10001,0);
		for (int j=0;j<n*(2*n-1);j++) {
			fscanf(in,"%d",&b);
			a[b]++;
		}
		fprintf(out,"Case #%d:",i);
		for (int j=1;j<=10000;j++) {
			if (a[j]%2==1) fprintf(out," %d",j);
		}
		fprintf(out,"\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}
