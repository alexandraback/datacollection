#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <Windows.h>

using namespace std;

void gener(long long int p,long long int q,int & count)
{
	++count;
	if(count>40)
		return;
	if(2*p-q<=q && 2*p-q>=0)
	{
		int c=count;
		if((2*p-q==0 || 2*p-q==1))// && q==1)
			return;
		else
		{
			gener(2*p-q,q,c);
			if(c<=40)
				return;
		}
	}
	gener(2*p,q,count);
}

int main()
{
	ifstream fin("A.in");
	ofstream fout("A-out.out");
	int t;
	char temp;
	long long int p;
	long long int q;
	long long int ps;
	long long int qs;
	int count=0;
	fin>>t;
	for(int i=0;i<t;++i)
	{
		count=0;
		fin>>p>>temp>>q;
		gener(p,q,count);
		if(count<40 && q%2==0)
			fout<<"Case #"<<i+1<<": "<<count<<endl;
		else
			fout<<"Case #"<<i+1<<": impossible"<<endl;
	}
	fin.close();
	fout.close();

	return 0;
}