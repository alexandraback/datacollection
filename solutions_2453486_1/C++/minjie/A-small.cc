#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char ch[5][5];
int x, y;
bool check(char c){
	//printf("%d %d\n",x,y);
	if(x != -1) ch[x][y] = c;
	for(int i = 0;i < 4; ++i){
		if(ch[i][0] == c && ch[i][1] == c && ch[i][2] == c && ch[i][3] == c)
			return true;
		if(ch[0][i] == c && ch[1][i] == c && ch[2][i] == c && ch[3][i] == c)
			return true;
	}
	if(ch[0][0] == c && ch[1][1] == c && ch[2][2] == c && ch[3][3] == c)
			return true;
	if(ch[0][3] == c && ch[1][2] == c && ch[2][1] == c && ch[3][0] == c)
			return true;
	return false;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int it = 1;it <= T; ++it){
			x = y = -1;
			bool emp = false;
			for(int i = 0;i < 4; ++i){
				scanf("%s",ch[i]);
				for(int j = 0;j < 4; ++j){
					if(ch[i][j] == '.') emp = true;
					if(ch[i][j] == 'T') x = i, y = j;
				}
			}
			printf("Case #%d: ",it);
			if(check('X')) puts("X won");
			else if(check('O')) puts("O won");
			else if(!emp) puts("Draw");
			else puts("Game has not completed");
	}

}
