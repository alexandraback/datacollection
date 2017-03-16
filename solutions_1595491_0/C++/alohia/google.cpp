#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;
int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("input2.txt");
	ofile.open("output2.txt");
	int t,n,s,p;
	int i,j,k=1,x,y=1,z;
	ifile>>t;
	while(t--)
	{	
		x=0;
		ifile>>n;
		ifile>>s;
		ifile>>p;
		y=3*p-3;
		j=0;
		for(i=0;i<n;i++)
		{
			ifile>>z;
			if(z>y)
			{
				x++;
			}
			else if(z>=y-1 && j<s && z!=0)
			{
				x++;
				j++;
			}
		}
		ofile<<"Case #"<<k<<": "<<x<<"\n";
		k++;
	}
	ifile.close();
	ofile.close();
}
			
