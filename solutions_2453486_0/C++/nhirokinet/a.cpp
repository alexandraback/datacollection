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

int main(){
	int T;
	cin>>T;

	FOR(count,0,T){
		cout<<"Case #"<<(count+1)<<": ";
		char map[4][4];
		FOR(i,0,4){
			FOR(j,0,4){
				cin>>map[i][j];
			}
		}

		int result=0;
		char prev;

		FOR(i,0,4){
			prev=map[i][0];

			if(prev=='T')
				prev=map[i][1];

			FOR(j,0,4){
				if(prev!=map[i][j] && map[i][j]!='T'){
					prev='.';
				}
			}
			if(prev=='O' || prev=='X'){
				cout<<prev<<" won\n";
				result=1;
				break;
			}

			prev=map[0][i];
			if(prev=='T')
				prev=map[1][i];
			FOR(j,0,4){
				if(prev!=map[j][i] && map[j][i]!='T'){
					prev='.';
				}
			}
			if(prev=='O' || prev=='X'){
				cout<<prev<<" won\n";
				result=1;
				break;
			}
		}

		if(result)
			continue;

		prev=map[0][0];
		if(prev=='T')
			prev=map[1][1];

		FOR(j,0,4){
			if(prev!=map[j][j] && map[j][j]!='T'){
				prev='.';
			}
		}
		if(prev=='O' || prev=='X'){
			cout<<prev<<" won\n";
			result=1;
			continue;
		}
		prev=map[0][3];
		if(prev=='T')
			prev=map[1][2];

		FOR(j,0,4){
			if(prev!=map[j][3-j] && map[j][3-j]!='T'){
				prev='.';
			}
		}
		if(prev=='O' || prev=='X'){
			cout<<prev<<" won\n";
			result=1;
			continue;
		}
		
		int end=1;

		FOR(i,0,3)
			FOR(j,0,3)
				if(map[i][j]=='.')
					end=0;
		if(end)
			cout<<"Draw\n";
		else
			cout<<"Game has not completed\n";







	}
}
