// r1ba.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <vector>
#include <set>
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
	cout.precision(8);
	cout<<"Case #"<<n<<":";

	string line;
	getline(cin,line);
	auto ptr=line.c_str();
	char* pnext=nullptr;
	const int N=strtoul(ptr,&pnext,10);
	int ttl=0;
	vector<int> S;
	multiset<int> MS;
	int minpv=100;
	int maxpv=0;
	for(int i=0;i<N;++i){
		ptr=pnext;
		int si=strtoul(ptr,&pnext,10);
		MS.insert(si);
		S.push_back(si);
		ttl+=si;
		if(si<minpv)
			minpv=si;
		if(si>maxpv)
			maxpv=si;
	}
	int stl=0;
	int m=0;
	double edge=ttl;
	for(auto it=MS.cbegin();it!=MS.cend();++it){
		if(edge<*it)
			break;
		stl+=*it;
		++m;
		edge=double(ttl+stl)/m;
	}
	for(auto it=S.cbegin();it!=S.cend();++it){
		const int si=*it;
		if(double(si)>=edge){
			cout<<' '<<0.0;
			continue;
		}
		cout<<' '<<(edge-si)*100.0/ttl;
	}
	cout<<endl;
}

