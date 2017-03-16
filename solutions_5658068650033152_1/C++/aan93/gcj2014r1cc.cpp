#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
FILE *in,*out;
int main()
{
	in=fopen("in.txt","r");
	out=fopen("out.txt","w");
	int t,n,m,k,h;
	int p,s,q,r;
	int a[100000][4],z;
	fscanf(in,"%d",&t);
	for (int i=3;i<=1000;i++) for (int j=3;j<=i && i*j<1000;j++) for (int l=0;l<=2*(j-1);l++)
	{
		p=2*i+2*j-4-l;
		q=l%4;
		r=l/4;
		s=i*j-(4-q)*r*(r+1)/2-q*(r+1)*(r+2)/2;
		a[z][0]=i;
		a[z][1]=j;
		a[z][2]=p;
		a[z][3]=s;
		z++;
	}
	for (int i=1;i<=t;i++)
	{
		fscanf(in,"%d%d%d",&n,&m,&k);
		if (m>n) swap(n,m);
		h=k;
		for (int j=0;j<z;j++) if (n>=a[j][0] && m>=a[j][1])
		{
			if (k<=a[j][3]) h=min(h,a[j][2]);
			else h=min(h,a[j][2]+k-a[j][3]);
		}
		fprintf(out,"Case #%d: %d\n",i,h);
	}
	fclose(in);
	fclose(out);
	return 0;
}
