// r1ca.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
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

struct sclass{
	int M;
	int parents[10];
};

bool check(int idx,set<int>& tochk,set<int>& list,sclass* clarr);

void docase(const int n)
{
	cout<<"Case #"<<n<<": ";

	string line;
	getline(cin,line);
	auto ptr=line.c_str();
	char* pnext=nullptr;
	const int N=strtoul(ptr,&pnext,10);
	sclass clarr[1000];
	set<int> tochk;
	for(int i=0;i<N;++i){
		getline(cin,line);
		ptr=line.c_str();
		pnext=nullptr;
		clarr[i].M=strtoul(ptr,&pnext,10);
		for(int j=0;j<clarr[i].M;++j){
			ptr=pnext;
			clarr[i].parents[j]=strtoul(ptr,&pnext,10)-1;
		}
		if(clarr[i].M>1){
			tochk.insert(i);
		}
	}

	while(!tochk.empty()){
		int idx=*(tochk.cbegin());
		set<int> list;
		if(check(idx,tochk,list,clarr)){
			cout<<"Yes"<<endl;
			return;
		}
	}

	cout<<"No"<<endl;
}

bool const dbg=false;

bool check(int idx,set<int>& tochk,set<int>& list,sclass* clarr)
{
	tochk.erase(idx);
	if(dbg)cout<<"check "<<idx<<endl;
	if(list.find(idx)!=list.cend()){
		if(dbg)cout<<"true (in list)"<<endl;
		return true;
	}
	list.insert(idx);
	for(int j=0;j<clarr[idx].M;++j){
		if(check(clarr[idx].parents[j],tochk,list,clarr)){
			if(dbg)cout<<"true (from nested)"<<endl;
			return true;
		}
	}
	if(dbg)cout<<"false (from nested)"<<endl;
	return false;
}
