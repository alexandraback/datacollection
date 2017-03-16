#include<fstream>
#include<iostream>
#include<cmath>
int nd(int n)
{
	int c=0;
	while(n>0)
	{
		n=n/10;
		c++;
	}
	return c;
}
int shift(int n,int k)
{
	int t;
	int p=(int)pow(10,k);
	t = n%p;
	n = n/p;
	n = t*((int)pow(10,nd(n)))+n;
	return n;
}
using namespace std;
int main()
{
	int a,b;
	ifstream ifile;
	ifile.open("input2.txt");
	ofstream ofile;
	ofile.open("output2.txt");
	int t;
	ifile>>t;
	int i,j,k=1;
	int x,y,z,m=0;
	
	while(t--)
	{
		ifile>>a;
		ifile>>b;
		m=0;
		for(x=a;x<=b;x++)
		{
			y= nd(x);
			for(i=1;i<y;i++)
			{
				z=shift(x,i);
				if(z==x)
					break;
				if(z>x && z<=b)
				{	m++;
					
				}
			}
					
		}
		ofile<<"Case #"<<k<<": "<<m<<"\n";
		k++;
	}
	ifile.close();
	ofile.close();
}
