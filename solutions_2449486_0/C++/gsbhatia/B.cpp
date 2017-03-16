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

int main(){
	int ncases; cin>>ncases;
	for (int kase=1;kase<=ncases;++kase){
		int M,N; cin>>M>>N;
		vector<int> R(M,0),C(N,0);
		vector<pair<int,int> > V[101];
		for (int i=0;i<M;++i) for (int j=0;j<N;++j){
			int x; cin>>x;
			R[i]=max(R[i],x);
			C[j]=max(C[j],x);
			V[x].push_back(make_pair(i,j));
		}
		bool ok=1;
		for (int i=100;i;--i){
			ForEach(it,V[i]){
				int r=it->first,c=it->second;
				ok&=R[r]<=i||C[c]<=i;
			}
		}
		cout<<"Case #"<<kase<<": "<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}