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
		cout << "Case #" << iter << ": "<<endl;

		int N,J;
		cin>>N>>J;

		for (long long patt=0; patt<(1<<(N/2-1)); ++patt) {
			if (J--==0)
				break;
			cout<<"1";
			FOR(i,0,(N/2-1)) {
				cout<<((patt>>i)&1);
			}
			FOR(i,0,(N/2-1)) {
				cout<<((patt>>(N/2-2-i))&1);
			}
			cout<<"1";

			cout<<" ";

			FOR(i,3,11){
			cout<<i<<" ";
			}
			cout<<11<<endl;
		}
	}
}
