#include <iostream>
#include <fstream>
#include <math.h>
#include <set>
using namespace std;

int digit(int number)
{
	int d=1;
	number=number/10;
	while(number)
	{
		d++;
		number=number/10;
	}
	return d;
}

int move(int m,int n,int d)
{
	int p=int(pow(10.0,n));
	int q=int(pow(10.0,d-n));
	int r=m/p+(m%p)*q;
	return r;
}

void main(){
	ifstream infile;
	ofstream outfile;
	int count;
	int a,b;
	int digits;
	
	infile.open("d:\\1.txt");
	outfile.open("d:\\2.txt");
	infile>>count;
	for(int i=1;i<=count;i++)
	{
		int result=0;
		infile>>a>>b;
		digits=digit(a);
		for(int j=a;j<=b;j++)
		{
			set<int> s;
			int t=j;
			for(int k=1;k<digits;k++)
			{
				int num=move(t,k,digits);
				if(num>j)
				{
					if(num<=b)
					{
						if(s.find(num)==s.end())
						{
							s.insert(num);
						    result++;
						}
					}
				}
			}
			s.clear();
		}

		outfile<<"Case #"<<i<<": "<<result<<endl;
	}

	infile.close();
	outfile.close();
}