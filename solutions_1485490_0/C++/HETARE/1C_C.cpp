#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef __int64 ll;

struct Data{
	ll type, num;
};

Data box[3];
Data toy[100];
ll ans;
ll n, m;

void func(ll b, ll t, ll sum){
	if(b == n || t == m){
		ans = max(sum, ans);
		return;
	}
	if(box[b].type == toy[t].type){
		if(box[b].num < toy[t].num){
			ll num = box[b].num;
			toy[t].num -= num;
			box[b].num = 0;
			func(b+1, t, sum+num);
			toy[t].num += num;
			box[b].num = num;
		}
		else if(box[b].num > toy[t].num){
			ll num = toy[t].num;
			box[b].num -= num;
			toy[t].num = 0;
			func(b,t+1, sum+num);
			toy[t].num = num;
			box[b].num += num;
		}
		else{
			ll num = box[b].num;
			box[b].num = 0;
			toy[t].num = 0;
			func(b+1,t+1, sum+num);
			box[b].num = num;
			toy[t].num = num;
		}
	}
	else{
		func(b+1, t, sum);
		func(b, t+1, sum);
	}
}
int main(){
	
	ll T;
	scanf("%I64d", &T);
	for(ll t = 0; t < T; t++){
		ans = 0;
		scanf("%I64d%I64d", &n, &m);
		for(ll i = 0; i < n; i++){
			ll num, type;
			scanf("%I64d%I64d", &num, &type);
			box[i].num = num;
			box[i].type = type;
		}
		for(ll i = 0; i < m; i++){
			ll num, type;
			scanf("%I64d%I64d", &num, &type);
			toy[i].num = num;
			toy[i].type = type;
		}
		func(0, 0, 0);
		printf("Case #%I64d: %I64d\n", t+1, ans);
	}
	
	return 0;
}