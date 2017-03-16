#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;
int table[201];
int T;
int main()
{
	ifstream fin("test.in");
	ofstream fout("test.out");
	fin>>T;
	for(int i=0;i<T;i++)
	{
		int n;
		fin>>n;
		int sum=0;
		for(int j=0;j<n;j++)
		{
			fin>>table[j];
			sum+=table[j];
		}
		fout<<"Case #"<<i+1<<":";
		for(int p=0;p<n;p++)
		{
			double result=0;
			for(result=0;result<=1;result+=2e-6)
			{
				double temp=sum*result+table[p];
				double temp2=sum*(1-result);
				for(int q=0;q<n;q++)
				{
					if(p==q)
						continue;
					if(table[q]>=temp)
						continue;
					else
					{
						temp2-=temp-table[q];
					}
					if(temp2<0)
						break;
				}
				if(temp2<0)
					break;

			}
			for(result=result>0? result-2e-6:0;result>0&&result<=1;result+=2e-7)
			{
				double temp=sum*result+table[p];
				double temp2=sum*(1-result);
				for(int q=0;q<n;q++)
				{
					if(p==q)
						continue;
					if(table[q]>=temp)
						continue;
					else
					{
						temp2-=temp-table[q];
					}
					if(temp2<0)
						break;
				}
				if(temp2<0)
					break;

			}
			for(result=result>0? result-2e-7:0;result>0&&result<=1;result+=1e-8)
			{
				double temp=sum*result+table[p];
				double temp2=sum*(1-result);
				for(int q=0;q<n;q++)
				{
					if(p==q)
						continue;
					if(table[q]>=temp)
						continue;
					else
					{
						temp2-=temp-table[q];
					}
					if(temp2<0)
						break;
				}
				if(temp2<0)
					break;

			}

			result*=100;
			fout<<setiosflags(ios::fixed)<<setprecision(6)<<' '<<result;
		}
		fout<<endl;

	}
	fout.close();
	fin.close();
	return 1;
}
