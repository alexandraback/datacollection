// {{{ Boilerplate Code <--------------------------------------------------
//
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

// }}}

long long maximize(long long E, long long R, vector<long long> v, int start, long long current){
	if(v.size()==start)
		return 0;

	long long tmpmax=0;

	FOR(i,0,current+1){
		long long tmp=maximize(E,R,v,start+1,min(E,current-i+R))+i*v[start];
		if(tmp>tmpmax)
			tmpmax=tmp;
	}
	return tmpmax;
}

int main(){
	int T;

	cin>>T;

	FOR(wholecount,1,T+1){
		cout<<"Case #"<<wholecount<<": ";

		long long E,R,N;
		vector <long long> v;

		cin>>E>>R>>N;

		FOR(i,0,N){
			long long tmp;
			cin>>tmp;
			v.push_back(tmp);
		}

		cout<<maximize(E,R,v,0,E)<<"\n";

	}
}
