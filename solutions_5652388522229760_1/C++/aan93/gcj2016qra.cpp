#include <stdio.h>
#include <vector>
using namespace std;
FILE *in,*out;
vector <int> a;
int g;
void adding(long long int z) {
	while (z>0) {
		if (a[z%10] == 0) {
			a[z%10] = 1;
			g++;
		}
		z /= 10;
	}
}
int main()
{
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int t;
	long long int n;
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++) {
		fscanf(in,"%lld",&n);
		if (n == 0) {
			fprintf(out,"Case #%d: INSOMNIA\n",i);
		} else {
			a.assign(10,0);
			g = 0;
			int j=0;
			while (g<10) {
				j++;
				adding(n*j);
			}
			fprintf(out,"Case #%d: %lld\n",i,n*j);
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
