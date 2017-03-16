#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

template<typename T>
class heap : public priority_queue<T,vector<T>,greater<T> > {};


vector<int> ans;
vector<int> cur;
vector<tuple<int,int,int> > combs;
int k;

int c13[30][30];
int c23[30][30];
int c12[30][30];

void solve(int i) {
	if(i==combs.size()) {
		if(cur.size() > ans.size()) ans = cur;
	}
	else {
		for(int j=i;j<combs.size();++j) {
			auto x = combs[j];
			if(c13[get<0>(x)][get<2>(x)]<k && c12[get<0>(x)][get<1>(x)]<k && c23[get<1>(x)][get<2>(x)]<k) {
				++c13[get<0>(x)][get<2>(x)];
				++c12[get<0>(x)][get<1>(x)];
				++c23[get<1>(x)][get<2>(x)];
				
				cur.push_back(j);
				solve(j+1);
				cur.pop_back();
				
				
				--c13[get<0>(x)][get<2>(x)];
				--c12[get<0>(x)][get<1>(x)];
				--c23[get<1>(x)][get<2>(x)];
				
			}
		}
	}
}
			





int main(void) {
	
	map<tuple<int,int,int,int>,vector<tuple<int,int,int> > > memo;
	
	
	
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt) {
		
		
		ans.clear();
		cur.clear();
		combs.clear();
		FOR(i,30) FOR(j,30) {
			c12[i][j] = 0;
			c23[i][j] = 0;
			c13[i][j] = 0;
		}
		
		int j,p,s;
		scanf("%d%d%d%d",&j,&p,&s,&k);
		printf("Case #%d: ",tt);
		
		if(memo.find(make_tuple(j,p,s,k))==memo.end()) {
			FOR(a,j) FOR(b,p) FOR(c,s) combs.push_back(make_tuple(a+1,b+1,c+1));
			solve(0);
			vector<tuple<int,int,int> > x;
			for(auto v:ans) x.push_back(combs[v]);
			memo[make_tuple(j,p,s,k)] = x;
		}
		auto x = memo[make_tuple(j,p,s,k)];
		printf("%d\n",x.size());
		for(auto v:x) printf("%d %d %d\n",get<0>(v),get<1>(v),get<2>(v));
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
}