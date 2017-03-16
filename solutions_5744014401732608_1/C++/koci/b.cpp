#include <iostream>
#include <iomanip>
#include <climits>
#include <stack>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

ll a[55];

void solve(int prim){
	ll b,m;
	scanf("%lld%lld",&b,&m);
	printf("Case #%d: ",prim);
	if(m>(1LL<<(b-2LL))){
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("POSSIBLE\n");
	memset(a,0,sizeof(a));
	for(ll i=b-1LL;i>1LL;i--){
		if(m>=(1LL<<(i-2LL))){
			a[i]=1LL;
			m-=(1LL<<(i-2LL));
		}else a[i]=0;
	}
	if(m>0)a[1LL]=1LL;
	else a[1LL]=0;
	FORR(i,1,b){
		FORR(j,1,b){
			if(j>i)printf("1");
			else printf("0");
		}
		printf("%lld\n",a[i]);
	}
	FOR(i,b)printf("0");
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	FORR(i,1,n+1)solve(i);
	return 0;
}
