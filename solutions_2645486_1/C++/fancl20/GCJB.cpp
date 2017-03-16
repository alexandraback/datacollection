#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
pair<int,int> v[10000010];
int upb[10000010],in[10000010];
int main() {
	int _,E,R,N,tmp,ca(0); cin>>_;
	unsigned long long res(0);
	while(_--) {
		res = 0;
		cin>>E>>R>>N;
		memset(in,0,sizeof in);
		for(int i(0);i!=N;++i) {
			scanf("%d",&in[i]);
			v[i] = make_pair(in[i],i);
			upb[i] = E;
		}
		sort(v,v+N,greater<pair<int,int> >());
		for(int i(0);i!=N;++i) {
			int u = v[i].second;
			int va = v[i].first;
			if(u>0 && in[u-1]<in[u]) upb[u-1] = upb[u]==E?R:0;
			for(int j(1);u+j<N && va>=in[u+j];++j) {
				upb[u+j] = min(upb[u+j],min(j*R,E));
				if(j*R>=E) break;
			}
		}
		for(int i(0);i!=N;++i)
			res+=in[i]*upb[i];
		printf("Case #%d: ",++ca);
		cout<<res<<'\n';
	}
}
