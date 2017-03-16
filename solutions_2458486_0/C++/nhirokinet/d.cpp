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

	FOR(counter,0,T){
		cout<<"Case #"<<(counter+1)<<": ";
		int N,K;
		cin>>K>>N;

		map<string,int> eachkeynums[300];
		vector<string> eachkeylist[300];
		string req[300];

		map<string,int> needkeynums;

		int open[300];
		FOR(i,0,N)
			open[i]=0;

		map<string,int> keynums;

		FOR(i,0,K){
			string tmpk;
			cin>>tmpk;
			keynums[tmpk]++;
		}

		FOR(i,0,N){
			cin>>req[i];
			needkeynums[req[i]]++;
			int num;
			cin>>num;
			FOR(j,0,num){
				string nk;
				cin>>nk;
				eachkeynums[i][nk]++;;
				eachkeylist[i].push_back(nk);
			}
		}

		int remain=N;

		vector <int> ans;

		
		int impossible=0;
		while(remain){
			int next=0;
			int yet=1;


			while(yet){
				if(next==N){
					impossible=1;
					break;
				}
				if(open[next] || keynums[req[next]]==0){
					next++;
					continue;
				}
				if(keynums[req[next]]==1 && needkeynums[req[next]]>1 && eachkeynums[next][req[next]]==0){
					next++;
					continue;
				}
				yet=0;
			}
			if(impossible)
				break;

			open[next]=1;
			remain--;
			keynums[req[next]]--;
			needkeynums[req[next]]--;

			FOR(i,0,eachkeylist[next].size()){
				keynums[eachkeylist[next][i]]++;
			}

			ans.push_back(next+1);
		}
		if(impossible){
			cout<<"IMPOSSIBLE";
		}else{
			FOR(i,0,ans.size()){
				cout<<ans[i];
				if(i<ans.size()-1)
					cout<<" ";
			}
		}
		cout<<"\n";
	}
}
