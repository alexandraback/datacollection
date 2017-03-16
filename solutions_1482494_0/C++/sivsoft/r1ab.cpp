// r1ab.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
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
	const int N=strtoul(ptr,&pnext,10);
	// levels information: stars needed to complete level
	//vector<int> ast(N);
	//vector<int> bst(N);
	// levels information: stars we can earn
	vector<int> g1st(N);
	vector<int> g2st(N);
	// levels to complete with 1-star rating ordered by needed rating
	multimap<int,int> levelstogo1;
	// levels to complete ordered by needed rating
	multimap<int,int> levelstogo;
	for(int i=0;i<N;++i){
		getline(cin,line);
		ptr=line.c_str();
		pnext=nullptr;
		const int ai=strtoul(ptr,&pnext,10);
		//ast.push_back(ai);
		g1st[i]=1;
		ptr=pnext;
		const int bi=strtoul(ptr,&pnext,10);
		//bst.push_back(bi);
		g2st[i]=2;
		levelstogo1.insert(multimap<int,int>::value_type(ai,i));
		levelstogo.insert(multimap<int,int>::value_type(bi,i));
	}
	// result
	int res=0;
	// current stars
	int score=0;
	auto ltg1=levelstogo1.cbegin();
	auto ltg=levelstogo.cbegin();

	while(ltg!=levelstogo.cend()){
		if(ltg->first<=score){
			if(g2st[ltg->second]>0){
				++res;
				score+=g2st[ltg->second];
				g1st[ltg->second]=0;
				g2st[ltg->second]=0;
			}
			++ltg;
		}
		else{
			// need to earn some stars
			if(ltg1==levelstogo1.cend()){
				res=0;
				break;
			}
			if(ltg1->first<=score){
				if(g1st[ltg1->second]>0){
					++res;
					score+=g1st[ltg1->second];
					g1st[ltg1->second]=0;
					g2st[ltg1->second]=1;
				}
				++ltg1;
			}
			else{
				res=0;
				break;
			}
		}
	}

	if(res)
		cout<<res<<endl;
	else
		cout<<"Too Bad"<<endl;
}

