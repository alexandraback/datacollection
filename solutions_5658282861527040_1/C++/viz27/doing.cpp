#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	unsigned long long t,a,b,k,sum,cases,i,j;
	ifstream fin("a.txt");
	ofstream fout("b.in");
	fin>>t;
	for(cases=1;cases<=t;cases++)
	{
		fin>>a>>b>>k;
		if(b<a)
		{
			sum=b;
			b=a;
			a=sum;
		}
		sum=0;
		if(a<=k)
		{
			sum=a*b;
			fout<<"Case #"<<cases<<": "<<sum<<endl;
		}
		else
		{
			sum=b*k;
			sum+=((a-k)*k);
			//fout<<sum<<endl;
			for(i=k;i<a;i++)
			{
				for(int j=k;j<b;j++)
				{
					if((i&j)<k) 
					{
						//fout<<i<<" and "<<j<<endl; 
						sum++;
					}
				}
			}
			fout<<"Case #"<<cases<<": "<<sum<<endl;
		}
	}
}
