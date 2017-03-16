#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	int t;
	scanf("%d",&t);
	rep1(ppp,t){
		printf("Case #%d: ",ppp);
		ll n;
		ll cnt = 0;
		priority_queue<P1,vector<P1>,greater<P1>> que;
		scanf("%lld",&n);
		rep(i,n){
			ll d,h,m;
			scanf("%lld%lld%lld",&d,&h,&m);
			rep(j,h){
				que.push( mp1 ( (360-d)*(m+j) , 1 , m+j ) );
			}
			cnt += h;
		}
		ll ret = cnt;
		ll now = cnt;
		while(now-cnt < ret){
			P1 p = que.top(); que.pop();
			if(p.sc.fr == 1){
				now --;
				cnt --;
				ret = min ( ret , now );
				que.push( mp1 ( p.fr+360*p.sc.sc , -1 , p.sc.sc ) );
			}
			else {
				now ++;
				que.push( mp1 ( p.fr+360*p.sc.sc , -1 , p.sc.sc ) );
			}
		}
		printf("%d\n",ret);
	}
}
