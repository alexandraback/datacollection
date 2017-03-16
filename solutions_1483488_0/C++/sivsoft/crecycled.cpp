// crecycled.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void docase(const int n);

int _tmain(int argc, _TCHAR* argv[])
{
	string line;
	getline(cin,line);
	const auto N=atoi(line.c_str());
	for(int n=1;n<=N;++n)
		docase(n);
	return 0;
}

int factors[]={
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
	100000000,
	1000000000
};

void docase(const int casen)
{
	string line;
	getline(cin,line);
	auto ptr=line.c_str();
	char* pnext=nullptr;
	const int A=strtoul(ptr,&pnext,10);
	ptr=pnext;
	const int B=strtoul(ptr,&pnext,10);

	int len=0;
	while(factors[len]<=A)
		++len;

	vector<int> used(len);

	int res=0;
	for(int n=A;n<B;++n){
		used.clear();
		for(int j=1;n>factors[j];++j){
			int f=factors[j];
			int m=n%f*factors[len-j] + n/f;
			if(n<m && m<=B && find(used.cbegin(),used.cend(),m)==used.cend()){
				//cout<<"( "<<n<<" - "<<m<<" ) "<<j<<" "<<len<<endl;
				used.push_back(m);
				++res;
			}
		}
	}

	cout<<"Case #"<<casen<<": "<<res<<endl;
}