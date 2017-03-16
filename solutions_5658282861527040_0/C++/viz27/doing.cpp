#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	int t,a,b,k,sum,cases;
	ifstream fin("a.txt");
	ofstream fout("b.in");
	fin>>t;
	for(cases=1;cases<=t;cases++)
	{
		fin>>a>>b>>k;
		sum=0;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i&j)<k) sum++;
			}
		}
		fout<<"Case #"<<cases<<": "<<sum<<endl;
	}
}
