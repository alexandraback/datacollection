#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int test,cntO,cntX,cntT;
char s[5][5];
bool O,X,empty;

int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	int cnt=1;
	for (;test--;cnt++){
		printf("Case #%d: ",cnt);
		for (int i=1;i<=4;i++)
			scanf("%s",s[i]+1);
		O=X=empty=false;
		for (int i=1;i<=4;i++){
			cntO=cntX=cntT=0;
			for (int j=1;j<=4;j++){
				if (s[i][j]=='.') empty=true;
				if (s[i][j]=='O') cntO++;
				if (s[i][j]=='X') cntX++;
				if (s[i][j]=='T') cntT++;
			}
			if (cntO+cntT==4) O=true;
			if (cntX+cntT==4) X=true;
		}
		for (int j=1;j<=4;j++){
			cntO=cntX=cntT=0;
			for (int i=1;i<=4;i++){
				if (s[i][j]=='.') empty=true;
				if (s[i][j]=='O') cntO++;
				if (s[i][j]=='X') cntX++;
				if (s[i][j]=='T') cntT++;
			}
			if (cntO+cntT==4) O=true;
			if (cntX+cntT==4) X=true;
		}
		cntO=cntX=cntT=0;
		for (int i=1;i<=4;i++){
			if (s[i][i]=='O') cntO++;
			if (s[i][i]=='X') cntX++;
			if (s[i][i]=='T') cntT++;
		}
		if (cntO+cntT==4) O=true;
		if (cntX+cntT==4) X=true;
		cntO=cntX=cntT=0;
		for (int i=1;i<=4;i++){
			if (s[i][5-i]=='O') cntO++;
			if (s[i][5-i]=='X') cntX++;
			if (s[i][5-i]=='T') cntT++;
		}
		if (cntO+cntT==4) O=true;
		if (cntX+cntT==4) X=true;
		
		if (X || O){
			if (X) puts("X won");
			if (O) puts("O won");
			continue;
		}
		if (empty) puts("Game has not completed");
			else puts("Draw");
	}
	return 0;
}
