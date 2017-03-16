// BEGIN CUT HERE

// END CUT HERE
#line 5 "ImportantSequence.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include<stdio.h>
#include<stdlib.h>
#include   <iomanip>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define SZ(v) (int)((v).size())

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

double prob(int a,int b,int k,double *p)
{
	double pright=1.0;
	double key=k+b-a+k+1;
	for(int i=0;i<a-k;i++)
		pright*=p[i];
	double pwrong=1.0-pright;
	key=key*pright+(key+b+1)*pwrong;
	return key;
}

int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("in.in");
	outfile.open("out.in");
	int T;
	infile>>T;
	string line;
	getline(infile,line);


	for(int i=1;i<=T;i++)
	{
		int a,b;
		double key=200000.0,nowkey;
		//getline(infile,line);
		infile>>a>>b;
		double *p;
		p=new double [a];
		for(int j=0;j<a;j++)
			infile>>p[j];
		key=1.0+b+1.0;
		for(int j=0;j<=a;j++)
		{
			nowkey=prob(a,b,j,p);
			if(nowkey<key)
				key=nowkey;
		}
		outfile.setf(ios::fixed); 
		outfile<<"Case #"<<i<<": "<<setprecision(6)<<key<<endl;
		delete [] p;
	}



	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
