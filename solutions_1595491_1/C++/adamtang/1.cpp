#include <iostream>
#include <fstream>
using namespace std;

void main(){
	ifstream infile;
	ofstream outfile;
	int count;
	int num;
	
	infile.open("d:\\1.in");
	outfile.open("d:\\2.txt");
	infile>>count;
	for(int i=1;i<=count;i++)
	{
		num=0;
		int s=0,p=0;
		int m[100];
		for(int t=0;t<100;t++)
		{
			m[t]=0;
		}
		infile>>num>>s>>p;
		
		for(int j=0;j<num;j++)
		{
			infile>>m[j];
		}

		int min=3*p-2;
		int max=3*p-4;
		if(max<2)
			max=2;
		int result=0;
		
		for(int k=0;k<num;k++)
		{
			if(m[k]>=min)
			{
				result++;
			}
			else if(s>0)
			{
				if(m[k]>=max)
				{
					result++;
					s--;
				}
			}
		}
		outfile<<"Case #"<<i<<": "<<result<<endl;
	}

	infile.close();
	outfile.close();
}