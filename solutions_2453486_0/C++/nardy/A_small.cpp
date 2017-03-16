#include <cstdio>
#include <cstring>
#include <cstdlib>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;
char map[6][6];
int T;

bool check(char x)
{
    int cnt;
	rep(i,1,4){
	   cnt = 0;
	   rep(j,1,4) if(map[i][j] == x || map[i][j] == 'T') ++ cnt;
	   if(cnt == 4) return true;
	}
	rep(j,1,4){
	   cnt = 0;
	   rep(i,1,4) if(map[i][j] == x || map[i][j] == 'T') ++ cnt;
	   if(cnt == 4) return true;
	}
	cnt = 0;
	rep(i,1,4)
	if(map[i][i] == x || map[i][i] == 'T') ++ cnt;
	if(cnt == 4) return true;
	cnt = 0;
	rep(j,1,4)
	if(map[4 - j + 1][j] == x || map[4 - j + 1][j] == 'T') ++ cnt;
	if(cnt == 4) return true;
	return false;
}
void solve()
{
	int emp = 0;
    rep(i,1,4){
	   scanf("%s",map[i] + 1);
       rep(j,1,4) if(map[i][j] == '.') ++ emp;
	} 
	if(check('X')) puts("X won");
	else if(check('O')) puts("O won");
	else if(emp) puts("Game has not completed");
	else puts("Draw");
	return;
}
int main()
{
	//freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
	return 0;
}
