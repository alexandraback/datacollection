#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("b.in");
	ofstream fout;
	fout.open("b.out");
	int tc,round,n,t,p,i,s1,s2,v;

	fin>>tc;
	for (round=0;round<tc;round++)
	{
		fin>>n>>t>>p;
		s1=0;s2=0;
		for (i=0;i<n;i++)
		{
			fin>>v;
			if (v>=3*p-2)
				s1++;
			else
				if (p>1 && v>=3*p-4)
					s2++;
				else;
		}
		if (s2>t)
			s2=t;
		fout<<"Case #"<<round+1<<": "<<s1+s2<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}