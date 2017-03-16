#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define N 2
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b){
	if(!b) return a;
	else return gcd(b,a%b);
}
bool cek(ll x){
	while(x!=1){
		if(x%2)return true;
		x=x>>1;
	}
	return false;
}


ll doo(ll a,ll b){
	ll ans=0;
	ll x=gcd(a,b);
	a=a/x;
	b=b/x;
	//printf("%lld %lld\n",a,b);
	if(a>b) return -1;
	if(a==b) return 0;
	if(cek(b))return -1;
	while(a<b){
		ans++;
		a=a<<1;
	}
	return ans;
}

int main(){
	ll n,x,y;
	scanf("%lld",&n);
	for(int t=1;t<=n;t++){
		scanf("%lld/%lld",&x,&y);
		x=doo(x,y);
		if(x==-1||x>40){
			printf("Case #%d: impossible\n",t);
		}
		else printf("Case #%d: %lld\n",t,x);
	}
}