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

	       long long N;
	       cin>>N;

	       if(N==0){
		       cout<<"INSOMNIA"<<endl;
		       continue;
	       }

	       int seen=0;
	       long long ret=0;

	       while(seen!=1023){
		       ret++;

		       long long cur=N*ret;

		       while(cur){
			       seen|=1<<(cur%10);
			       cur/=10;
		       }
	       }

	       cout << ret*N << endl;
	}
}
