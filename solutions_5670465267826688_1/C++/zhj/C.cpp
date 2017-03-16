#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define N 24
using namespace std;
const int mo=1e9+9;
const double pi=acos(-1);
int tr[4][4]={
	1,2,3,4,
	2,-1,4,-3,
	3,-4,-1,2,
	4,3,-2,-1
};
int d[N][N],f[12000][N][N],T,l,ans[N][N],tim;
char c[12000];
int64 X;
void Plus(int &x,int y){
	x+=y;
	if(x>=mo)x-=mo;
}
int ch(int x,int y){
	return x*8+y;
}
void cheng(int a[N][N],int b[N][N]){
	int c[N][N];
	memset(c,0,sizeof(c));
	rep(i,0,N-1)
		rep(j,0,N-1)
			rep(k,0,N-1)c[i][k]=(c[i][k]+1ll*a[i][j]*b[j][k])%mo;
	memcpy(a,c,sizeof(c));
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d%I64d",&l,&X);
		scanf("%s",c);
		rep(i,0,2){
			rep(j,0,7){
				memset(f,0,sizeof(f));
				f[0][i][j]=1;
				rep(k,0,l-1){
					int ch=(c[k]=='i'?2:c[k]=='j'?3:4);
					rep(x,0,2)
						rep(y,0,7)if(f[k][x][y]){
							int u=y%4,sn=(y<=3)?-1:1;
							if(x<=1 && u==x+1 && y>3)Plus(f[k+1][x+1][ch+3],f[k][x][y]);
							int v=tr[u][ch-1];
							if(v<0)v*=-1,sn*=-1;
							v--;
							Plus(f[k+1][x][v+(sn==1?4:0)],f[k][x][y]);
						}
				}
				rep(x,0,2)
					rep(y,0,7)d[ch(i,j)][ch(x,y)]=f[l][x][y];
			}
		}
		assert(ch(2,7)==23);
		memset(ans,0,sizeof(ans));
		ans[0][ch(0,4)]=1;
		while(X){
			if(X&1)cheng(ans,d);
			cheng(d,d);
			X/=2;
		}
		printf("Case #%d: ",++tim);
		if(ans[0][ch(2,7)])printf("YES\n");
		else printf("NO\n");
	}
}

