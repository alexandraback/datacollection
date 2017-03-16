// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

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

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

int main(){
	int T;
	cin>>T;
	FOR(iter,0,T){
		string s;
		cin>>s;



		int ct[128];
		FOR(i,0,128)ct[i]=0;

		FOR(i,0,s.length()) ct[s[i]]++;
		
		int num[10];
		num[0]=ct['Z'];
		num[2]=ct['W'];
		num[8]=ct['G'];
		num[6]=ct['X'];
		num[7]=ct['S']-num[6];
		num[5]=ct['V']-num[7];
		num[4]=ct['F']-num[5];
		num[3]=ct['R']-num[0]-num[4];
		num[1]=ct['O']-num[0]-num[2]-num[4];
		num[9]=ct['I']-num[6]-num[5]-num[8];

		cout<<"Case #"<<iter+1<<": ";
		FOR(i,0,10){
			FOR(j,0,num[i]){
				cout<<i;
			}
		}

		cout<<endl;
	}
}
