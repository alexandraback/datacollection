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
		int N;
		cin>>N;

		vector <string> firsts;
		vector <string> seconds;

		FOR(i,0,N){
			string t1,t2;
			cin>>t1>>t2;

			firsts.push_back(t1);
			seconds.push_back(t2);
		}

		int ret=0;

		FOR(patt,0,1<<N){
			int flag=0;
			FOR(line,0,N){
				if((patt>>line)&1){
					int ok=0;
					FOR(i,0,N){
						if((patt>>i)&1)
							continue;
						if(firsts[i]==firsts[line])
							ok|=1;
						if(seconds[i]==seconds[line])
							ok|=2;

					}

					if(ok!=3){
						flag=1;
						break;
					}
				}
			}

			if(flag)
				continue;
			
			int tmp=0;
			FOR(i,0,N){
				if((patt>>i)&1){
					tmp++;
				}
			}

			if(tmp>ret)
				ret=tmp;

		}

		cout<<"Case #"<<iter+1<<": ";
		cout<<ret;
		cout<<endl;
	}
}
