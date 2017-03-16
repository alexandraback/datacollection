
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 110
typedef long long int LL;

using namespace std;

struct P{
	int h,x,y;
	P(){}
	P(int _h,int _x,int _y):h(_h),x(_x),y(_y){}
}s[N*N];

bool cmp(const P& a,const P& b){
	return a.h<b.h;
}

int n,m;
int b[N][N];
int v[N][N];

void input(){
	scanf("%d%d",&n,&m);
	for(int i=0,k=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &b[i][j]);
			s[k++] = P(b[i][j], i, j);
		}
	}
}

bool goodx(int x,int h){
	for(int i=0;i<m;i++){
		if(v[x][i]==0 && b[x][i]>h)return false;
	}
	for(int i=0;i<m;i++){
		v[x][i]=1;
	}
	return true;
}

bool goody(int y,int h){
	for(int i=0;i<n;i++){
		if(v[i][y]==0 && b[i][y]>h)return false;
	}
	for(int i=0;i<n;i++){
		v[i][y]=1;
	}
	return true;
}

bool good(){
	int k=n*m;
	sort(s,s+k,cmp);
	memset(v,0,sizeof(v));
	for(int i=0; i<k; i++){
		int h=s[i].h, x=s[i].x, y=s[i].y;
		//printf("%d %d %d\n",h,x,y);
		if(v[x][y])continue;
		int j;
		if(!goodx(x,h) && !goody(y,h)){
			return false;
		}
	}
	return true;
}

void solve(){
	static int zi=0;
	printf("Case #%d: %s\n",++zi,good()?"YES":"NO");
	
}

int main(){

	int zn;
	scanf("%d",&zn);
	while(zn--){
		input();
		solve();
	}

	return 0;
}
