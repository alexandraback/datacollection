#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
FILE *in,*out;
vector <int> a,d;
int cln(int p,int pr,int q,int r,vector <int> s) {
	//cout << p << "\t" << q << "\t" << s[q] << "\t" << r << "\n";
	if (s[q] == 1) return -1000000000;
	else {
		s[q] = 1;
		if (pr != a[q]) d[q] = max(d[q], r);
		if (p == a[q]) return r+1;
		else return cln(p,q,a[q],r+1,s);
	}
}
int main()
{
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int t;
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++) {
		int n;
		fscanf(in,"%d",&n);
		a.resize(n);
		d.assign(n,0);
		for (int j=0;j<n;j++) {
			fscanf(in,"%d",&a[j]);
			a[j]--;
		}
		int b(0),c(0);
		for (int j=0;j<n;j++) {
			vector <int> e(n,0);
			e[j]=1;
			b = max(b,cln(j,j,a[j],1,e));
		}
		for (int j=0;j<n;j++) {
			if (j == a[a[j]] && j<a[j]) {
				c += 2 + d[j] + d[a[j]];
			}
		}
		//for (int j=0;j<n;j++) cout << j << "\t" << a[j] << "\t" << d[j] << "\n";
		//cout << i << "\t" << b << "\t" << c << "\n";
		fprintf(out,"Case #%d: %d",i,max(b,c));
		fprintf(out,"\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}
