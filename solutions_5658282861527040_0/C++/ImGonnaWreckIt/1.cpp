#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	int i,j,k,l;
	int A,B,K,T,count;
	ifstream ip("B-small-attempt0.in");;
	ofstream op("output.txt");;
	ip>>T;
	//cout<<T;
	for(l=1;l<=T;l++)
	{
		op<<"Case #"<<l<<": ";
		ip>>A>>B>>K;
		count=0;
		for(i=0;i<A;i++)
		{
			for(j=0;j<B;j++)
			{
				if((i&j)<K )
				{
					//if(l==1)
					//	cout<<i<<"\t"<<j<<"\n";
					count++;
				}
			}
		}
		op<<count<<"\n";
	}
	return 0;
}
