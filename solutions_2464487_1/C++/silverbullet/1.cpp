#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<bitset>
using namespace std;
typedef long long ll;
int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	ll r,t;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		cin>>r>>t;
		ll res=t;
		ll L=1,R=(ll)1e9;
		ll ans=-1;
		while(L<=R){
			ll m=(L+R)>>1;
			if((2*m-1+2*r)<=res/m){
				ans=m;
				L=m+1;
			}else R=m-1;
		}
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}

