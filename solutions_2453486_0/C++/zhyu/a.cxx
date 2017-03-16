#include <cstdio>
#include <cstring>

using namespace std;

const int N = 10;

char g[N][N];

inline bool judge(int x,int y,char c) {
	g[x][y]=c;
	int cnt;
	for(int i=0;i<4;i++) {
		for(int j=cnt=0;j<4;j++) cnt+=(g[i][j]==c);
		if(cnt==4) return 1;
		for(int j=cnt=0;j<4;j++) cnt+=(g[j][i]==c);
		if(cnt==4) return 1;
	}
	for(int i=cnt=0;i<4;i++) cnt+=(g[i][i]==c);
	if(cnt==4) return 1;
	for(int i=cnt=0;i<4;i++) cnt+=(g[i][3-i]==c);
	if(cnt==4) return 1;
	g[x][y]='T';
	return 0;
}
int main(void) {
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		for(int i=0;i<4;i++) scanf("%s",g[i]);
		int x=-1, y=-1;
		bool full=1;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) {
			if(g[i][j]=='.') full=0;
			if(g[i][j]=='T') {
				x=i;
				y=j;
			}
		}
		printf("Case #%d: ",cas);
		if(judge(x,y,'X')) puts("X won");
		else if(judge(x,y,'O')) puts("O won");
		else if(full) puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}
