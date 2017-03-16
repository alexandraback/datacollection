#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#include <cassert>
#include <cmath>
using namespace std ;

typedef long long int64;

#define two(x) (1)<<(x)
#define SZ(x) (int)x.size()
#define LEN(x) (int)x.length()
//typedef long long int64 ;
typedef long long int64 ;

const int mod = 1e9 + 7;

bool same(string &s){
	for(int i = 0 ; i < s.size()-1; ++i)
		if(s[i]!=s[i+1]) return false;
	return true;
}
int main (){
	freopen("B-large.in","r",stdin) ;
	freopen("B-large.out","w",stdout);
	int T;
	cin >> T;
	for(int Cas = 1 ; Cas <= T; ++Cas){

		int N ;
		cin >> N ;
		vector < string > data(N);
		for(int i = 0 ;  i < N ; ++i)
			cin >> data[i];
		sort(data.begin(), data.end());

		int64 ans = 1;
		vector < string > tmp;
		vector< bool > vis(N,false);
		for(int i = 0 ; i < N ;++i ){
			if(vis[i]) continue;
			string cur = "";
			char c = data[i][0];
			int cnt =0 ;
			if(same(data[i]))
				for(int j = i ; j < N; ++j){
					if(!vis[j]&&same(data[j])&&data[j][0]==c){
						cur += data[j];
						++cnt;
						ans = ans * cnt % mod;
						vis[j]=true;
					}
				}
				vis[i]=true;
				if(cur=="")
					cur = data[i];
				//  cout << cur << endl;
				tmp.push_back(cur);
		}
		data = tmp;
		N = data.size();
		// for(int i = 0 ; i < N ; ++i)
		//  cout << data[i]<<endl;
		vector< vector<int> > adj(N);
		vector< int > deg(N,0);

		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				if(i == j) continue;
				if(data[i][data[i].length()-1] == data[j][0]){
					++deg[j];
					adj[i].push_back(j);
					if(same(data[j]))
						swap(adj[i][0],adj[i][adj[i].size()-1]);
				}
			}
		}

		vector< bool > used(N,false) ;
		string res = "";
		int cnt = 0 ;
		for(int i = 0 ; i < N ; ++i){
			if(!deg[i]){
				++cnt;
				int cur = i,next=-1 ;
				used[cur] = 1;
				res += data[i];
				do{
					next = -1;
					for(int j = 0 ; j < adj[cur].size(); ++j){
						if(used[adj[cur][j]]) continue;
						res += data[adj[cur][j]];
						next = adj[cur][j];
						used[adj[cur][j]]=true;
					}
					cur = next;
				}while( next != -1) ;
			}
		}
		for(int i=1; i<=cnt ; ++i)
			ans = ans * i % mod;
		cout <<"Case #"<<Cas<<": ";
		for(int i = 0 ; i < N ; ++i)
			if(!used[i]) ans =0;
		int state = 0 ;
		char cur = 0;
		// cout << res << endl;
		for(int i = 0 ; i < res.size(); ){
			if(cur!=res[i])
				cur = res[i];
			while( i < res.size() && cur == res[i] ){
				++i;
			}
			if(state & (1<<(cur-'a')))
				ans = 0;
			state |= (1<<(cur-'a'));
		}
		cout << ans << endl ;
	}
	return 0;
}