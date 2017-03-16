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

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";

		int D;
		cin>>D;

		vector <int> P;

		FOR(i,0,D){
			int tmp;
			cin>>tmp;
			P.push_back(tmp);
		}

		int ret=2e9;

		FOR(finmax,1,1001){
			int tmp=finmax;

			FOR(i,0,P.size()){
				tmp+=(P[i]+finmax-1)/finmax-1;
			}

			ret=min(ret,tmp);
		}

		cout<<ret;

		cout<<endl;
	}

}
