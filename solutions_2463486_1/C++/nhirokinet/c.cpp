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

int is_palindrome(long long in){
	int eachdigit[100];

	int digits=0;
	long long in_copy=in;
	while(in_copy){
		eachdigit[digits++]=in_copy%10LL;
		in_copy/=10LL;
	}

	FOR(i,0,digits/2+1){
		if(eachdigit[i]!=eachdigit[digits-1-i])
			return 0;
	}
	return 1;

}

long long make_palindrome(long long in, int center){
	int eachdigit[100];

	int digits=0;
	long long in_copy=in;
	while(in_copy){
		eachdigit[digits++]=in_copy%10LL;
		in_copy/=10LL;
	}

	FOR(i,0,digits-(1-center))
		in*=10;

	long long ten=1;
	FOR(i,0,digits-(1-center)){
		in+=eachdigit[digits-1-i]*ten;
		ten*=10LL;
	}

	return in;
}


int main(){
	int T;
	cin>>T;

	FOR(counter,0,T){
		cout<<"Case #"<<(counter+1)<<": ";
		long long A,B;

		cin>>A>>B;

		int conti=1;
		long long count=0;

		long long base=1;

		while(conti){
			long long p1=make_palindrome(base,0);
			long long p2=make_palindrome(base,1);

			p1=p1*p1;
			p2=p2*p2;

			if(A<=p1 && p1<=B && is_palindrome(p1)){
				count++;
			}
			if(A<=p2 && p2<=B && is_palindrome(p2)){
				count++;
			}

			if(p1>B)
				break;
			base++;

		}

		cout<<count<<"\n";
	}
}
