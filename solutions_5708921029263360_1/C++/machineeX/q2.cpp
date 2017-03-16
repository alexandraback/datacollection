#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	
	fstream fin,fout;
	fin.open("input.txt",ios::in);
	fout.open("output.txt",ios::out);
	
	int i,t;
	fin>>t;
	for(i=1;i<=t;i++)
	{

		int j,p,s,k;
		fin>>j>>p>>s>>k;
		int temp,temp1=0;
		temp=s;
		
		
		if(s>k)
		s=k;
		int x1,x2,x3;
		
		
		fout<<"Case #"<<i<<": "<<(j*p*s)<<endl;
		for(x1=1;x1<=j;x1++)
		{
			for(x2=1;x2<=p;x2++)
			{
				if(temp==p&&x2==1)
					temp1++;
					
				for(x3=1;x3<=s;x3++)
				{
					
					temp1=temp1%temp;
					temp1++;
					fout<<x1<<" "<<x2<<" "<<temp1<<endl;
				}
			}
		}











	
	}
	
	cout<<"done";
	return 0;
}
