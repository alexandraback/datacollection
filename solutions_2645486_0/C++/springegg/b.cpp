#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#define maxl 1000000000
#define maxn 11000
#define maxm 10000
using namespace std;

typedef set<int>::iterator IT;
typedef long long ll;
pair<int,int> a[maxn];
ll maxx[maxn],leave[maxn];
set<int> ss;

void solve(){
	ll e,r,ans=0;
	int n,i,id,j;
	cin>>e>>r>>n;
	for(i=1;i<=n;++i){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(&a[1],&a[n+1]);
	ss.clear();
	for(i=n;i>0;--i){
		id=a[i].second;
		IT it=ss.lower_bound(id);
		if(it==ss.end())leave[id]=0;else {
			int j=*it;
			leave[id]=max(0LL,maxx[j]-(j-id)*r);
		}
		if(it==ss.begin())maxx[id]=e;else {
			--it;
			int j=*it;
			maxx[id]=min(e,leave[j]+(id-j)*r);
		}
		ans+=(maxx[id]-leave[id])*a[i].first;
		//cout<<maxx[id]<<" "<<leave[id]<<" "<<a[i].first<<endl;
		ss.insert(id);
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}