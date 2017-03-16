#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int  main()
{
	ifstream fin;
	fin.open("in.txt");
	ofstream fout;
	fout.open("output.txt");
	int cases;
	fin>>cases;
	int i=0;
	long long r,c,w;
	while(i<cases)
	{
		fin>>r;
		fin>>c;
		fin>>w;
		long long init,final,total;
		init = c/w *r;
		if(c%w==0)
		{
			final = w-1;
		}
		else
		{
			final = w;
		}
		total = init + final;


		fout << "Case #" << i + 1 << ": "<<total<<"\n";	
		i++;
	}
	fout.close();
	system("pause");
	return 0;
}