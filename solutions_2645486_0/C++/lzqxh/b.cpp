//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

bool	cmp( const pii &a , const pii &b ){
	if ( a.X != b.X ) return a.X > b.X;
	return a.Y < b.Y;
}
#define N 10011
int		Lim,r,n;
pii		data[N];
map<int,pii> mm;
map<int,pii>::iterator iter;

int		main(){
	int cas,tt=0;
	scanf("%d", &cas );
	while ( cas -- ) {
		scanf("%d%d%d", &Lim , &r , &n );
		r = min( Lim , r );
		Rep(i,n){
			scanf("%d", &data[i].X );
			data[i].Y = i+1;
		}
		sort( data , data+n , cmp );
		mm.clear();
		mm[0] = mp(0,Lim);
		mm[n+1] = mp(0,0);
		LL	ans = 0;
		Rep(ii,n){
			int val = data[ii].X , i = data[ii].Y;
			iter = mm.lower_bound(i);
			int k = iter->X , h = iter->Y.X;
			iter--;
			int j = iter->X , g = iter->Y.Y;
			int in = min(Lim,g+(i-j)*r);
			int	out = max(0,h-(k-i)*r);
			out = min(in,out);
			ans += ((LL)(in-out))*val;
			mm[i] = mp(in,out);
		}
		printf("Case #%d: %lld\n" , ++tt , ans );
	}
	return 0;
}

