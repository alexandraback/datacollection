#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define F first
#define S second

using namespace std;

int t,n,m;
pair<long long,long long> a[111];
pair<long long,long long> b[111];

long long rec(int i,int j,pair<long long,long long> aa,pair<long long,long long> bb){
	if ( i >= n || j >= m ) return 0;
	long long ret=0,ret1=0,ret2=0;
	if ( aa.S == bb.S ){
		ret=min(aa.F,bb.F);
		aa.F-=ret;
		bb.F-=ret;
	}
	if ( aa.F == 0 && bb.F == 0 ){
		ret1 = rec(i+1,j+1,a[i+1],b[j+1]);
	}else if ( aa.F == 0 ){
		ret1 = rec(i+1,j,a[i+1],bb);
	}else if ( bb.F == 0 ){
		ret1 = rec(i,j+1,aa,b[j+1]);
	}else{
		ret1 = rec(i,j+1,aa,b[j+1]);
		ret2 = rec(i+1,j,a[i+1],bb);
	}
	ret += max(ret1,ret2);
	return ret;
}

int main(){
	scanf("%d",&t);
	for ( int cas = 1 ; cas <= t ; cas++ ){
		scanf("%d%d",&n,&m);
		for ( int i = 0 ; i < n ; i++ ){
			scanf("%lld %lld",&a[i].F,&a[i].S);
		}
		for ( int i = 0 ; i < m ; i++ ){
			scanf("%lld %lld",&b[i].F,&b[i].S);
		}
		printf("Case #%d: %lld\n",cas,rec(0,0,a[0],b[0]));
	}
	return 0;
}