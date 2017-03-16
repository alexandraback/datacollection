#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

char game[10][10]={};

int main() {
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T; ++cas) {
		for(int i=1; i<=4; ++i)
			scanf("%s", game[i]+1);
		bool over=true, Xwon=false, Owon=false;
		for(int i=1; i<=4; ++i) {
			bool Xfill=true, Ofill=true;
			for(int j=1; j<=4; ++j) {
				if(game[i][j]=='.') Xfill=false, Ofill=false, over=false;
				if(game[i][j]=='X') Ofill=false;
				if(game[i][j]=='O') Xfill=false;
			}
			if(Xfill) Xwon = true;
			if(Ofill) Owon = true;
		}
		for(int j=1; j<=4; ++j) {
			bool Xfill=true, Ofill=true;
			for(int i=1; i<=4; ++i) {
				if(game[i][j]=='.') Xfill=false, Ofill=false;
				if(game[i][j]=='X') Ofill=false;
				if(game[i][j]=='O') Xfill=false;
			}
			if(Xfill) Xwon = true;
			if(Ofill) Owon = true;
		}
		{
			bool Xfill=true, Ofill=true;
			for(int i=1; i<=4; ++i) {
				if(game[i][i]=='.') Xfill=false, Ofill=false;
				if(game[i][i]=='X') Ofill=false;
				if(game[i][i]=='O') Xfill=false;
			}
			if(Xfill) Xwon = true;
			if(Ofill) Owon = true;
		}
		{
			bool Xfill=true, Ofill=true;
			for(int i=1; i<=4; ++i) {
				if(game[i][5-i]=='.') Xfill=false, Ofill=false;
				if(game[i][5-i]=='X') Ofill=false;
				if(game[i][5-i]=='O') Xfill=false;
			}
			if(Xfill) Xwon = true;
			if(Ofill) Owon = true;
		}
		printf("Case #%d: ", cas);
		if(Xwon) printf("X won");
		else if(Owon) printf("O won");
		else if(over) printf("Draw");
		else printf("Game has not completed");
		printf("\n");
	}
}
