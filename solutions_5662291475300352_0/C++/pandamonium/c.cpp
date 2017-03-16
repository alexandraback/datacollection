#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
bitset <500005>crossed;
int t,n,notcrossed,h1,cnt,ans,curr;
ll d1,m1,m[500005];
priority_queue<ii,vector<ii>,greater<ii> >pq;
int main(){
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		scanf("%d",&n);
		crossed.reset();
		cnt=0;
		for(int x=0;x<n;x++){
			scanf("%lld %d %lld",&d1,&h1,&m1);
			for(int y=0;y<h1;y++){
				m[cnt]=(m1+ll(y))*360ll;
				pq.push(ii((360ll-d1)*(m1+ll(y)),cnt));
				cnt++;
			}
		}
		ans=curr=cnt;
		while(curr-cnt<ans){
			ii currt=pq.top();
			ll crosstime=currt.first;
			while(currt.first==crosstime){
				pq.pop();
				pq.push(ii(crosstime+m[currt.second],currt.second));
				if(crossed[currt.second]) curr++;
				else{
					curr--;
					crossed[currt.second]=1;
					cnt--;
				}
				currt=pq.top();
			}
			if(curr<ans) ans=curr;
		}
		while(!pq.empty()) pq.pop();
		printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}
