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

int iabs(int in){
	if(in<0)
		return -in;
	return in;
}

int main(){
	int T;
	cin>>T;
	FOR(iter,0,T){
		string c_judge,j_judge;
		cin>>c_judge>>j_judge;

		int upperbound=1;
		FOR(i,0,c_judge.length()){
			upperbound*=10;
		}
		
		int c_ret=999999;
		int j_ret=9999999;
		FOR(tmpc,0,upperbound){
			int fl=0;
			int ib=upperbound;
			FOR(i,0,c_judge.length()){
				if(c_judge[i]!='?' && (c_judge[i]-'0'!=(tmpc%ib)/(ib/10))){
					fl=1;
				}
				ib/=10;
			}
			if (fl) continue;

			FOR(tmpj,0,upperbound){
				fl=0;
				ib=upperbound;

				FOR(i,0,c_judge.length()){
					if(j_judge[i]!='?' && (j_judge[i]-'0'!=(tmpj%ib)/(ib/10))){
						fl=1;
					}
					ib/=10;
				}

				if(fl) continue;

				if(iabs(c_ret-j_ret)>iabs(tmpc-tmpj)){
					c_ret=tmpc;
					j_ret=tmpj;
				}
				if(iabs(c_ret-j_ret)==iabs(tmpc-tmpj) && c_ret>tmpc){
					c_ret=tmpc;
					j_ret=tmpj;
				}
				if(iabs(c_ret-j_ret)==iabs(tmpc-tmpj) && c_ret==tmpc && j_ret>tmpj){
					c_ret=tmpc;
					j_ret=tmpj;
				}
			}
		}


		cout<<"Case #"<<iter+1<<": ";

		int digi=upperbound;
		FOR(i,0,c_judge.length()){
			cout<<(c_ret%digi)/(digi/10);
			digi/=10;
		}
		cout<<' ';
		digi=upperbound;
		FOR(i,0,j_judge.length()){
			cout<<(j_ret%digi)/(digi/10);
			digi/=10;
		}

		cout<<endl;
	}
}
