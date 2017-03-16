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

void flip(string &S, int num) {
	int iter1=0;
	int iter2=num-1;

	while(iter1<iter2){
		char tmp=S[iter1];
		S[iter1]=S[iter2];
		S[iter2]=tmp;

		iter1++;
		iter2--;
	}

	FOR(i,0,num){
		if(S[i]=='+'){
			S[i]='-';
		}else{
			S[i]='+';
		}
	}
}

int main(){
	int T;
	cin>>T;
	for (int iter=1; iter<=T; ++iter) {
	       cout << "Case #" << iter	<< ": ";

	       string S;
	       cin>>S;

	       int ret = 0;

	       while(1){
		       int lastminus=-1;
		       FOR(i,0,S.length()){
			       if(S[i]=='-')
				       lastminus=i;
		       }

		       if(lastminus==-1)
			       break;

		       if(S[0]=='+'){
			       int i=0;
			       while(S[i]=='+')
				       S[i++]='-';
			       ret++;
		       }
		       flip(S,lastminus+1);

		       ret++;
	       }

	       cout << ret << endl;
	}
}
