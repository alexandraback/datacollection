#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
int t,c,r,m;
char ma[6][6];
int f[1<<25];
bool vis[5][5];
int xx[8]={-1,-1,-1,0,0,1,1,1};
int yy[8]={-1,0,1,-1,1,-1,0,1};

void init() {
	for(int i=0;i<(1<<25);i++) {
		int cnt=0;
		for(int j=0;j<25;j++) {
			if(i&(1<<j)) cnt++;
		}
		f[i]=cnt;
	}
}

bool check(int x,int y) {
	for(int i=0;i<8;i++) {
		int tmpx=x+xx[i];
		int tmpy=y+yy[i];
		if(tmpx>=r || tmpx<0 || tmpy>=c || tmpy<0) continue;
		if(ma[tmpx][tmpy]=='*') return 0;
	}
	return 1;
}
int dfs(int x,int y) {
	if(vis[x][y]) return 0;
	vis[x][y]=1;
	int res=1;
	if(check(x,y)){
		for(int i=0;i<8;i++) {
			int tmpx=x+xx[i];
			int tmpy=y+yy[i];
			if(tmpx>=r || tmpx<0 || tmpy>=c || tmpy<0) continue;
			res+=dfs(tmpx,tmpy);
		}
	}
	return res;
}

bool search(int x,int y) {
	memset(vis,0,sizeof(vis));
	if(dfs(x,y)==c*r-m) {
		ma[x][y]='c';
		for(int i=0;i<r;i++)
			cout<<ma[i]<<endl;
		return true;
	}
	return false;
}

bool good(int x) {
	memset(ma,0,sizeof(ma));
	for(int i=0;i<r*c;i++) {
		if(x&(1<<i)) ma[i/c][i%c]='*';
		else ma[i/c][i%c]='.';
	}
	for(int i=0;i<r*c;i++) {
		if(ma[i/c][i%c]=='.' && search(i/c,i%c)) return true;
	}
	return false;
}

bool get() {
	int x=r*c;
	for(int i=(1<<x)-1;i>=0;i--) {
		if(f[i]==m && good(i)) return true;
	}
	return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	cin>>t;
	for(int cas=1;cas<=t;cas++) {
		cin>>r>>c>>m;
		printf("Case #%d:\n",cas);
		if(!get()) puts("Impossible");
	}
    return 0;
}


