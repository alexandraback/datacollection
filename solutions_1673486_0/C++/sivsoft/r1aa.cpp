// r1aa.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
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

void docase(const int n)
{
	cout<<"Case #"<<n<<": ";

	string line;
	getline(cin,line);
	auto ptr=line.c_str();
	char* pnext=nullptr;
	// A is the number of characters that I have already typed
	const int A=strtoul(ptr,&pnext,10);
	ptr=pnext;
	// B is the total number of characters in my password
	const int B=strtoul(ptr,&pnext,10);
	// line containing A real numbers: p1, p2, ..., pA. pi represents the probability that I correctly typed the ith letter in my password
	vector<double> prob(A);
	double ok=1.0;
	double res=2.0*(B+1);
	double tmp;
	getline(cin,line);
	ptr=line.c_str();
	pnext=nullptr;
	for(int i=0;i<A;++i){
		// we backspaced to this point
		tmp=(A-i)+ok*(B-i+1)+(1.0-ok)*(B-i+1+B+1);
		if(tmp<res) res=tmp;
		double pi=strtod(ptr,&pnext);
		ptr=pnext;
		prob.push_back(pi);
		ok*=pi;
	}
	// if keep typing
	tmp=ok*(B-A+1)+(1.0-ok)*(B-A+1+B+1);
	if(tmp<res) res=tmp;
	// press enter right now
	tmp=B+2;
	if(tmp<res) res=tmp;

	cout<<res<<endl;
}

