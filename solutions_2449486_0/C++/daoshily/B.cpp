#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int t,n,m,ct;
int a[1000][1000];
int h[1000],v[1000];

void init(){
	scanf("%d%d",&n,&m);
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ )
			scanf("%d",&a[i][j]);
}
void work(){
	memset(h,0,sizeof(h));
	memset(v,0,sizeof(v));
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ ){
			h[i] = max(h[i],a[i][j]);
			v[j] = max(v[j],a[i][j]);
		}
	bool feasible = true;
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = 0 ; j < m ; j++ )
			feasible &= (h[i]<=a[i][j] || v[j]<=a[i][j]);
	printf("%s\n",(feasible)?"YES":"NO");
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	for ( scanf("%d",&t),ct = 1 ; ct <= t ; ct++ ){
		printf("Case #%d: ",ct);
		init();
		work();
	}
}
