#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque> 
#include<ext/numeric>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<tr1/unordered_map>
#include<tr1/unordered_set>
#include<utility>
#include<vector>
using namespace std;

#define ForEach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it) 
typedef long long int i64;

const string IMPOSSIBLE="IMPOSSIBLE";
#define KEY_MAX 200

void pr(const vector<int>&V){
	ForEach(it,V) cerr<<*it<<' ';cerr<<endl;
}

int main(){
	int ncases; cin>>ncases;
	for (int kase=1;kase<=ncases;++kase){
		int K,N; cin>>K>>N;
		cerr<<"K: "<<K<<", N: "<<N<<endl;
		vector<vector<int> > A(1<<N);
		vector<vector<int> > B(1<<N, vector<int> (1+KEY_MAX,0));
		for (int i=0;i<K;++i){
			int u; cin>>u;
			++B[0][u];
		}		
		int H[N];
		vector<int> J[N];
		for (int i=0;i<N;++i){
			cin>>H[i]; int x; cin>>x;
			for (int j=0;j<x;++j){int u; cin>>u; J[i].push_back(u);}
		}
		for (int i=1;i<1<<N;++i){
			for (int j=0;j<N;++j){
				if (i>>j&1){
					for (int k=1;k<=KEY_MAX;++k) B[i][k]=B[i^1<<j][k];
					for (int k=0;k<J[j].size();++k) ++B[i][J[j][k]];
					--B[i][H[j]];
					break;
				}
			}
		}
		for (int i=1;i<1<<N;++i){
			int pc=__builtin_popcount(i);
			if (pc==1){
				int j=0; while(!(i>>j&1)) ++j;
				if (B[0][H[j]]) A[i].push_back(1+j);
			}else{
				for (int j=0;j<N;++j){
					if (i>>j&1){
						int k=i^1<<j;
						if (A[k].size()!=pc-1)continue;
						if (B[k][H[j]]){
							vector<int> t=A[k];
							t.push_back(1+j);
							if (!A[i].size()||A[i]>t) A[i]=t;
						}
					}
				}
			}
		}
		int M=(1<<N)-1;
		if (!A[M].size()){
			cout<<"Case #"<<kase<<": "<<IMPOSSIBLE<<endl;
		}else{
			
			cout<<"Case #"<<kase<<":";
			for (int i=0;i<A[M].size();++i)cout<<' '<<A[M][i];cout<<endl;
		}
	}
	return 0;
}