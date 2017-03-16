#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;
int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("input1.txt");
	ofile.open("output1.txt");
	int t,n,s,p;
	int i,j,k=1,x,y=1,z;
	//fscanf(ifile,"%d",&t);
	ifile>>t;
	while(t--)
	{	
		x=0;
		
		//fscanf(ifile,"%d%d%d",&n,&s,&p);
		ifile>>n;
		ifile>>s;
		ifile>>p;
		y=3*p-3;
		j=0;
		for(i=0;i<n;i++)
		{
			//fscanf(ifile,"%d",&z);
			ifile>>z;
			if(z>y)
			{
				x++;
			//	printf("%d ",z);
			}
			else if(z>=y-1 && j<s && z!=0)
			{
				x++;
			//	printf("%d ",z);
				j++;
			}
		}
		//fprintf(ofile,"Case #%d: %d\n",k,x);
		ofile<<"Case #"<<k<<": "<<x<<"\n";
		k++;
	}
	ifile.close();
	ofile.close();
}
			
