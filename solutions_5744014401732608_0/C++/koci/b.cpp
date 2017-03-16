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

int a[55];

void solve(int prim){
	int b,m;
	scanf("%d%d",&b,&m);
	printf("Case #%d: ",prim);
	if(m>(1<<(b-2))){
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("POSSIBLE\n");
	memset(a,0,sizeof(a));
	for(int i=b-1;i>1;i--){
		if(m>=(1<<(i-2))){
			a[i]=1;
			m-=(1<<(i-2));
		}else a[i]=0;
	}
	if(m>0)a[1]=1;
	else a[1]=0;
	FORR(i,1,b){
		FORR(j,1,b){
			if(j>i)printf("1");
			else printf("0");
		}
		printf("%d\n",a[i]);
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
