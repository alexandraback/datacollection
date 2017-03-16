#include <bits/stdc++.h>
using namespace std;
const int MAX_ITERATIONS=1000000;
int t,J,P,S,K;
vector<tuple<int,int,int> > v,sol;
void update() {
	map<pair<int,int>,int> mj,mp,ms;
	int ans=v.size();
	for(int i=0;i<v.size();++i) {
		int jacket,pant,shirt;
		tie(jacket,pant,shirt)=v[i];
		mj[{pant,shirt}]++;
		if(mj[{pant,shirt}]>K) {
			ans=i;
			break;
		}
		mp[{jacket,shirt}]++;
		if(mp[{jacket,shirt}]>K) {
			ans=i;
			break;
		}
		ms[{jacket,pant}]++;
		if(ms[{jacket,pant}]>K) {
			ans=i;
			break;
		}

	}
	if(ans>sol.size()) {
		sol.clear();
		for(int i=0;i<ans;++i) {
			sol.push_back(v[i]);
		}
	}
}
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);
	cin>>t;
	for(int test=1;test<=t;++test) {
		cout<<"Case #"<<test<<": ";
		cin>>J>>P>>S>>K;
		v.clear();
		for(int I=0;I<1;++I) {
			for(int i=0;i<J;++i) {
				for(int j=0;j<P;++j) {
					for(int k=0;k<S;++k) {
						v.push_back(make_tuple(i,j,k));
					}
				}
			}
		}
		int iterations=MAX_ITERATIONS/5;
		sol.clear();
		while(iterations--) {
			random_shuffle(v.begin(),v.end());
			update();
		}
		cout<<sol.size()<<"\n";
		for(int i=0;i<sol.size();++i) {
			int jacket,pant,shirt;
			tie(jacket,pant,shirt)=sol[i];
			cout<<jacket+1<<" "<<pant+1<<" "<<shirt+1<<"\n";
		}
	}
}