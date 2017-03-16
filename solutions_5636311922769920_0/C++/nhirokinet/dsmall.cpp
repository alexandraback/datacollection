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
	for (int iter=1; iter<=T; ++iter) {
	       cout << "Case #" << iter	<< ": ";

	       long long K,C,S;
	       cin>>K>>C>>S;

	       FOR(i,0,K){
		       long long ret=1;
		       long long base=1;
		       FOR(j,0,C){
			       ret+=base*i;
			       base*=K;
		       }
		       if(i>0)
			       cout<<" ";
		       cout<<ret;
	       }

	       cout << endl;
	}
}
