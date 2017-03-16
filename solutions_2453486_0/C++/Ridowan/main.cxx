//BISMILLAHIRRAHMANIRRAHIM



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define i64 long long
#define pii pair < int , int >
#define CLR(x) memset(x,0,sizeof x)
#define SET(x,y) memset(x,y,sizeof x)
#define PB(x) push_back(x)

char g[5][5];

bool win(int x,int y) {
	if(g[x][y]=='.' || g[x][y]=='T') return 0;
	int tx,ty,i,j,n;
	bool f;
	for(i=-1;i<=1;i++) for(j=-1;j<=1;j++) if(i!=0 || j!=0) {
		n=3;
		f=1;
		tx=x;ty=y;
		while(n--) {
			tx+=i;
			ty+=j;
			if(tx<0 || tx>3 || ty<0 || ty>3 || !(g[tx][ty]==g[x][y] || g[tx][ty]=='T')) {
				f=0;
				break;
			}
		}
		//if(f) cerr<<i<<' '<<j<<'\n';
		if(f) return true;
	}
	return 0;
}
string rs[]={"X won","O won","Draw","Game has not completed"};

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	int I,T;
	int i,j,k;
	cin>>T;
	for(I=1;I<=T;I++) {
		printf("Case #%d: ",I);
		cerr<<I<<'\n';
		for(i=0;i<4;i++) cin>>g[i];
		k=0;
		int r=3;
		for(i=0;i<4;i++) for(j=0;j<4;j++) {
			if(win(i,j)) {
				r=g[i][j]=='X'?1:2;
				//cerr<<i<<' '<<j<<' '<<r<<'\n';
			}
			if(g[i][j]=='.') k=1;
		}
		if(r==3 && k==1) r=4;
		puts(rs[r-1].c_str());
	}
	return 0;
}
