#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int f[200][100];
int a[1000];
int max1(int x,int y,int z)
{
	if (x>y&&x>z) return x;
    if (y>x&&y>z) return y;
	if (z>x&&z>y) return z;
	return x;
}
int main()
{
	ifstream ifile;
	ofstream ofile;
	int t,n,s,p,i,j,k,g,h,u,tot;
	ifile.open("B-large.in");
	ifile>>t;
	ofile.open("2.txt");
	for(i=1;i<=t;i++)
	{
		ifile>>n>>s>>p;
		for(j=1;j<=n;j++)
			ifile>>a[j];
		tot=0;
		for(j=1;j<=n;j++)
		{
			f[j][0]=0;
			f[j][1]=0;
		}
		if (i==4)
		{
			int o=0;
		}
		for(j=1;j<=n;j++)
		{
			for(k=0;k<=10;k++)
				for(g=0;g<=10;g++)
				{
					if (a[j]-k-g<0) continue;
					h=a[j]-k-g;
					if (k==6&&g==7&&h==8)
					{
						int uu=0;
					}
					
					if (abs(k-g)<=1&&abs(k-h)<=1&&abs(g-h)<=1&&max1(k,g,h)>=p)
					{
						f[j][0]=1;
						//tot++;
					}
					if (abs(k-g)<=2&&abs(k-h)<=2&&abs(g-h)<=2&&(k-g-2)*(k-h-2)*(g-h-2)==0&&max1(k,g,h)>=p)
					{
						f[j][1]=1;
					}
				}
		}
		for(j=1;j<=n;j++)
			if (f[j][0]==1) tot++;
		u=0;
		for(j=1;j<=n;j++)
			if (f[j][0]==0&&f[j][1]==1) u++;
		if (u>s) u=s;
		ofile<<"Case #"<<i<<": "<<u+tot<<endl;//3
	}
	ifile.close();
	ofile.close();
	return 0;
}

