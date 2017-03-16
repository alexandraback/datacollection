#include <bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
#define N 1001000
char s[N];
char v[5] = {'a','e','i','o','u'};
int main(){
	int cas;
	scanf("%d",&cas);
	rep(u,cas){
		int n;
		scanf("%s %d",s,&n);
		ll sum = 0;
		int ps=-2;
		int cnt=0;
		for(int i=0;s[i];i++){
			bool tem=false;
			rep(j,5) if(s[i]==v[j]){
				cnt = 0;
				tem = true;
			}
			if(!tem) cnt++, cnt=min(n,cnt);
			if(cnt==n) ps = i-n;
			//printf(">>%d\n",ps);
			sum += ps+2;
		}
		printf("Case #%d: %lld\n",u+1,sum);
	}
	return 0;
}

