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

		int N,M;
		int a[100][100];
		int map[100][100];

		cin>>N>>M;

		FOR(i,0,N)
			FOR(j,0,M)
				cin>>a[i][j];

		FOR(i,0,N)
			FOR(j,0,M)
				map[i][j]=100;

		FOR(i,0,N){
			int max=a[i][0];
			FOR(j,0,M){
				if(max<a[i][j])
					max=a[i][j];
			}
			FOR(j,0,M){
				if(map[i][j]>max)
					map[i][j]=max;
			}
		}
		FOR(j,0,M){
			int max=a[0][j];
			FOR(i,0,N){
				if(max<a[i][j])
					max=a[i][j];
			}
			FOR(i,0,N){
				if(map[i][j]>max)
					map[i][j]=max;
			}
		}
		int ans=1;
		FOR(i,0,N){
			FOR(j,0,M){
				if(map[i][j]!=a[i][j])
					ans=0;
			}
		}
		cout<<(ans?"YES":"NO")<<"\n";




	}
}
