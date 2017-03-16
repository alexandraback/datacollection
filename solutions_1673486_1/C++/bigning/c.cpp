#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream fin("A-large.in");
	ofstream fout("re2.txt");
	int T,A,B;
	double * p;
	double min;
	fin>>T;
	for(int i=0;i<T;i++)
	{
		fin>>A>>B;
		p=new double[A];

		for(int j=0;j<A;j++)
		{
			fin>>p[j];
		}

		min=2+B;
		double temp=1;

		for(int j=0;j<A;j++)
		{
			temp=temp*p[j];
			double r=temp*(double)((A-j-1)+(B-j-1)+1)+(1-temp)*(double)(A-j-1+(B-j-1)+2+B);
			if(r<min)
			{
				min=r;
			}
		}
		double r=A+B+1;
		if(r<min)
		{
			min=r;
		}
		fout<<setiosflags(ios::fixed)<<setprecision(6);

		fout<<"Case #"<<i+1<<": "<<min<<endl;


		delete[] p;
	}
	return 0;
}