#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
ll vs[512];
int cnt[20<<20];
int N;
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		cin>>N;
		ll s=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<N; ++i) cin>>vs[i],s+=vs[i];
		int r=-1;
		for(int i=0; i<1<<N; ++i) {
			ll a=0;
			for(int j=0; j<N; ++j) a += vs[j]*(1&(i>>j));
			++cnt[a];
			if (cnt[a]>1) r=a;
		}

		cout<<"Case #"<<a<<":\n";
		int asd=0;
		for(int i=0; asd<2; ++i) {
			ll a=0;
			for(int j=0; j<N; ++j) a += vs[j]*(1&(i>>j));
			if (a==r) {
				for(int j=0; j<N; ++j) if (1&(i>>j)) cout<<vs[j]<<' ';
				cout<<'\n';
				++asd;
			}
		}
	}
}
