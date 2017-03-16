#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define mod 1000000007
#define inf 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define lim 200007

int main(){
	freopen("file.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1,tst = 1;
	cin>>t;
	while(t--){
		int r,c,w,ans;
		cin>>r>>c>>w;
		ans = r*((c-1)/w) + w;
		if(c%w==0){
			ans += r-1;
		}
		printf("Case #%d: %d\n",tst++,ans);
	}
	return 0;
}
