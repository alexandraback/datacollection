#include<bits/stdc++.h>
#define ll long long 
#define M 20
#define fi first
#define se second
using namespace std;
typedef pair < ll , ll > L;
typedef pair < ll , L > LL;
int n;
ll pw[M + 5];
LL f[M + 5][5];
char sx[M + 5] , sy[M + 5];
int tx[M + 5] , ty[M + 5];
void prepare(){
	pw[0] = 1;
	for(int i = 1 ; i <= 18 ; i++)	pw[i] = 1ll*pw[i - 1]*10;
}
void solve(){
	scanf("%s %s",sx,sy);
	n = strlen(sx);
	reverse(sx , sx + n) ; reverse(sy , sy + n);
	for(int i = 0 ; i < n ; i++){	tx[i] = sx[i] - '0'; ty[i] = sy[i] - '0'; }
	for(int i = n ; i >= 0 ; i--)
		for(int c = 0 ; c < 3 ; c++)	f[i][c] = LL(1e18 , L(1e18 , 1e18));
	f[n][0] = LL(0 , L(0 , 0));
	for(int i = n ; i >= 1 ; i--)
		for(int c = 0 ; c < 3 ; c++){
			if(f[i][c].fi == 1e18)	continue;
			for(int x = 0 ; x < 10 ; x++)
				for(int y = 0 ; y < 10 ; y++){
					if(sx[i - 1] != '?' && tx[i - 1] != x )	continue;
					if(sy[i - 1] != '?' && ty[i - 1] != y ) continue;
					int nc = c;
					if(nc == 0){
						if(x > y)	nc = 1;
						else if(x < y) nc = 2;
					}
					LL tmp = f[i][c];
					tmp.se.fi += (x*pw[i - 1]); tmp.se.se += (y*pw[i - 1]); tmp.fi = (nc == 1 ? tmp.se.fi - tmp.se.se : tmp.se.se - tmp.se.fi);
					if(f[i - 1][nc] > tmp)	f[i - 1][nc] = tmp;
				}
		}
	int c = 0;
	for(int i = 1 ; i < 3 ; i++)	if(f[0][i] < f[0][c])	c = i;
	string ax , ay;
	for(int i = 1 ; i <= n ; i++){
		ax += ( f[0][c].se.fi %10 + '0' ); f[0][c].se.fi /= 10;
		ay += ( f[0][c].se.se %10 + '0' ); f[0][c].se.se /= 10;
	}
	reverse(ax.begin() , ax.end()); reverse(ay.begin() , ay.end());
	cout<<ax<<' '<<ay<<'\n';
}
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int tc;
	prepare();
	scanf("%d",&tc);
	for(int i = 1 ; i <= tc ; i++){
		printf("Case #%d: ",i);
		solve();
	}
}
