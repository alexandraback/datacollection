#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

const int INF=1e9;

int d[20];
int h[20];
int m[20];

//int dd[20];
//int mm[20];

struct hiker{
	int d;
	int m;
	double speed;
	double time;
	double dist;
	bool operator<(const hiker &other)const{
		return d<other.d;
	}
}hikers[20];

int main(){
	
	freopen("C-small-2-attempt1.in","r",stdin);
	
	freopen("C-small-2-attempt1.out","w",stdout);
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int n;
		cin>>n;
		
		
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>h[i]>>m[i];
			for(int j=1;j<=h[i];j++){
				hikers[++cnt].d=d[i];
				hikers[cnt].m=m[i]+j-1;
				hikers[cnt].speed=1.0/hikers[cnt].m;
				hikers[cnt].time = (360.0-hikers[cnt].d)/hikers[cnt].speed/360;
			}
		}
		sort(hikers+1,hikers+1+cnt);
		if(cnt==1){
			printf("Case #%d: 0\n",cas);
		}else{
			double maxtime=0;
			for(int i=1;i<=cnt;i++){
				maxtime=max(maxtime ,hikers[i].time );
			}
			
			for(int i=1;i<=cnt;i++){
				hikers[i].dist = hikers[i].d+360.0*maxtime*hikers[i].speed;
			}
			
			//cout<<maxtime<<endl;
			int ans=0;
			for(int i=1;i<=cnt;i++){
				
				for(int j=i+1;j<=cnt;j++){
					if(i==j)continue;
					double d=hikers[i].dist-hikers[j].dist;
					if(d<0)d=-d;
					if( d>=360 ){
						ans++;break;
					}
				}
			}
			
			//ans/=2;
			
			printf("Case #%d: %d\n",cas,ans);
			
			
		}
	}
	return 0;
}

/*
const int INF=1e9;

#define ll long long


ll inv(ll x){
	ll tmp[10];
	ll m=0;
	ll last=0;
	while(x){
		tmp[m++]=x%10;
		if(x%10){
			last=m;
		}
		x/=10;
	}
	ll re=0;
	for(ll i=0;i<m;i++){
		re+=tmp[i];
		re*=10;
	}
	re/=10;
	return re;
}

ll wei(ll x){
	int re=0;
	while(x){
		x/=10;
		re++;
	}
	return re;
}

ll fun(ll x){
	if(x<=20)return x;
	
	int weishu=wei(x);
	ll invx=inv(x);
	int weishu2=wei(invx);
	if(invx<x&&weishu==weishu2){
		return fun(invx)+1;
	}else{
		return fun(x-1)+1;
	}

}

int main(){
	
	freopen("A-small-attempt0.in","r",stdin);
	
	freopen("cmp.out","w",stdout);
	
	
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		ll n;
		cin>>n;
		
		ll re=fun(n);
		
		printf("Case #%d: %I64d\n",cas,re);
		
	}
	return 0;
}*/
