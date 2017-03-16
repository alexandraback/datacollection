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

		int smax;
		cin>>smax;

		int cur=0;
		int already=0;

		int ret=0;

		FOR(shy,0,smax+1){
			char tmp;
			cin>>tmp;

			int ct=tmp-'0';

			if(shy>already){
				ret=max(ret,shy-already);
			}

			already+=ct;
		}

		cout<<ret;


		cout<<endl;
	}

}
