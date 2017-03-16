// bdancers.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
using namespace std;

void docase(const int n);
int best(int score);
bool nosurp(int score,int limit);
int bestws(int score);
bool withsurp(int score,int limit);

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
	const int total=strtoul(ptr,&pnext,10);
	ptr=pnext;
	int surp=strtoul(ptr,&pnext,10);
	ptr=pnext;
	const int limit=strtoul(ptr,&pnext,10);
	ptr=pnext;
	int result=0;
	for(int i=1;i<=total;++i){
		const int score=strtoul(ptr,&pnext,10);
		ptr=pnext;
		if(nosurp(score,limit))
			++result;
		else if(surp>0 && withsurp(score,limit)){
			++result;
			--surp;
		}
	}

	cout<<result<<endl;
}

int best(int score)
{
	if(score==0)
		return 0;
	return (score-1)/3+1;
}

bool nosurp(int score,int limit)
{
	return best(score)>=limit;
}

int bestws(int score)
{
	if(score<2)
		return score;
	if(score<29)
		return (score-2)/3+2;
	return 10;
}

bool withsurp(int score,int limit)
{
	return bestws(score)>=limit;
}

