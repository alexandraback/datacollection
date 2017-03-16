#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>
#include<cmath>
#define INF 0x7fffffff
#define pb push_back
#define pn(x) cerr<<x<<endl

using namespace std;
typedef long long ll;
const int maxv=500005;
int T,t=0,r,c,w;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	while(T--){
		t++;
		cin>>r>>c>>w;
		ll ans=(r-1)*(c+w-1)/w;
		ans+=(c+w-1)/w+w-1;
		printf("Case #%d: %I64d\n",t,ans);
	}
    return 0;
}