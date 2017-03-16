#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<pair<int,vector<int> > > tmp;
#define go(x) for(x=2;x<=8;++x)
int main(){
	cout << "Case #1:"<< endl;
	int T,r,n,m,k;cin>>T;
	cin >> r >> n >> m >> k;
	random_shuffle(tmp.begin(),tmp.end());
	int a[5];
	go(a[0])go(a[1])go(a[2])go(a[3])go(a[4]){
		int f[32]={1};
		for(int i=1;i<32;++i){
			int h = i&-i;
			f[i]=f[i^h]*a[__builtin_ctz(h)];
		}
		sort(f,f+32);
		tmp.push_back(make_pair(
			a[0]*10000+a[1]*1000+a[2]*100+a[3]*10 + a[4],
			vector<int>(f,f+32)));
	}
	cerr << tmp.size() << endl;
	random_shuffle(tmp.begin(),tmp.end());
	int cnt = 0;
	for(int g[12],u;r--;){
		for(int i=0;i<k;++i)cin >> g[i];
		for(int p=8;p>=2;--p){
			for(int i=0;i<k;++i)
				if(g[i]%p==0)g[i]/=p;
		}
		sort(g,g+12,greater<int>());
		for(u=0;g[u]!=1 &&u<k;++u);
		bool ok=true;
		for(auto x:tmp){
			ok=true;
			vector<int> const &set=x.second;
			for(int i=0;i<u&&ok;++i){
				if(!binary_search(set.begin(),set.end(),g[i]))ok=false;
			}
			if(ok){
				int a = x.first;
				cout << "2345678"<<a/10000 << a/1000%10
				<< a/100%10 << a/10%10 << a%10 << endl;
				break;
			}
		}
		if(!ok){
			cout << "234567823456" << endl;
			++cnt;
		}
	}
	cerr << cnt << endl;
}
