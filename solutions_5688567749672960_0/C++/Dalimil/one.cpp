#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;


map<ll, ll> dp;
map<ll, ll> dis;

ll N;

ll reverse(ll x){
	ll n = 0;
	while(x != 0 ){
		n = n*10 + x%10;
		x /= 10;
	}
	return n;
}


ll best(ll x){

	set<pair<int, ii> > q;
	q.insert(pair<int, ii>(1, ii(N-1, 1)));
	dis[1] = 1;
	ll sofar = (1LL)<<50;

	while(!q.empty()){
		ll u = q.begin()->second.second;
		ll d = q.begin()->first;
		q.erase(q.begin());

		//cout << u << "-"<<d <<endl;

		if(d >= sofar) continue;

		if(u == N){ 
			sofar = min(sofar, dis[N]);
			continue;
		}

		if(dis.count(u+1) == 0 || dis[u+1] > d+1){
			dis[u+1] = d+1;
			q.insert(pair<int, ii>(d+1, ii(abs(N-(u+1)), u+1)));
		}
		ll k = reverse(u);
		if(dis.count(k) == 0 || dis[k] > d+1){
			dis[k] = d+1;
			q.insert(pair<int, ii>(d+1, ii(abs(N-k), k)));
		}
	}
	return sofar;
}

int main(){
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++){
		scanf("%d", &N);

		dp.clear();
		dis.clear();
		//cout << reverse(3200) << "-"<<reverse(3201) <<endl;
		ll ans = best(N);
		printf("Case #%d: %lld\n", t, ans);
	}
}
