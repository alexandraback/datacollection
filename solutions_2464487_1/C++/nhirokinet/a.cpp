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

int main(){
	int T;

	cin>>T;

	FOR(wholecount,1,T+1){
		cout<<"Case #"<<wholecount<<": ";
		long long r,t;
		cin>>r>>t;

		long long upper=sqrt(t/2)+1;
		if(upper>t/2/r)
			upper=t/2/r+1;

		long long lower=0;

		while(upper>lower){
			long long mid=(upper+lower+1)/2;
			if(t<2*mid*mid+(2*r-1)*mid)
				upper=mid-1;
			else
				lower=mid;
		}
		cout<<upper<<"\n";

	}
}
