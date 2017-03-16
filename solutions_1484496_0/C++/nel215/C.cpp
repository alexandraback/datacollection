#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

void solve(){
	int N;
	scanf("%d",&N);
	vector<int> S(N);
	REP(i,N)scanf("%d",&S[i]);
	map<int,set<vector<int> > > memo;
	for(int bit=1 ; bit<(1<<N) ; bit++){
		int sum = 0;
		vector<int> s;
		REP(i,N)if(bit>>i&1){
			sum += S[i];
			s.push_back(S[i]);
		}
		sort(ALL(s));
		if(memo.count(sum)==0)memo[sum] = set<vector<int> >();
		memo[sum].insert(s);
	}
	set<vector<int> > res;
	for(map<int,set<vector<int> > >::iterator it=memo.begin() ; it!=memo.end() ; it++){
		if(it->second.size()>=2){
			res = it->second;
			break;
		}
	}
	if(res.size()>=2){
		int i=0;
		for(set<vector<int> >::iterator it=res.begin() ; i<2 ; i++,it++){
			vector<int> tmp(it->begin(),it->end());
			REP(j,tmp.size())printf("%d%c",tmp[j],(j==(int)tmp.size()-1?'\n':' '));
		}
	}
	else printf("Impossible\n");
}

int main(){
	int T;
	scanf("%d",&T);
	for(int cc=1 ; cc<=T ; cc++){
		printf("Case #%d:\n",cc);
		solve();
	}
	return 0;
}
