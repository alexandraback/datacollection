#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int naivechk[4][4];
int naivevis[4][4];
int xx[8] = {-1,-1,-1,0,1,1,1,0}, yy[8] = {-1,0,1,1,1,0,-1,-1};

int dfs(int R,int C,int x, int y)
{
	naivevis[x][y] = 1;
	int i, ret = 0;
	for(i=0;i<8;i++){
		int tx = x + xx[i];
		int ty = y + yy[i];
		if(tx < 0 || tx >= R || ty < 0 || ty >= C || naivevis[tx][ty])continue;
		if(naivechk[tx][ty])ret += dfs(R, C, tx, ty);
	}
	return ret + 1;
}

bool naivesolve(int R,int C,int M)
{
	//R, C <= 3;
	int i, cell = R*C;
	for(i=1;i<1<<cell;i++){
		int j;
		memset(naivechk, 0, sizeof naivechk);
		for(j=0;j<cell;j++){
			if(1<<j&i)naivechk[j/C][j%C] = 1;
		}
		memset(naivevis, 0, sizeof naivevis);
		int a = dfs(R,C,0,0);
		int t = i;
		while(t)a--, t -= (t&-t);
		if(a != 0)continue;
		int cnt = 0;
		int here[5][5];
		memset(here, 0, sizeof here);
		for(j=0;j<R;j++){
			for(int k=0;k<C;k++){
				int t;
				int flag = 0;
				if(naivechk[j][k])continue;
				for(t=0;t<8;t++){
					int tx = j + xx[t];
					int ty = k + yy[t];
					if(tx < 0 || tx >= R || ty < 0 || ty >= C)continue;
					if(naivechk[tx][ty])flag = 1;
				}
				if(!flag)here[j][k] = 1, cnt++;
			}
		}
		if(cnt == M){
			int c = 0;
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					if(naivechk[i][j] && !c){printf("c");c=1;}
					else if(here[i][j])printf("*");
					else printf(".");
				}
				puts("");
			}
			return true;
		}
	}
}

int is_swaped;
int chk[55][55];
int click[2];

void output(int R, int C)
{
	if(is_swaped)swap(R, C);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			int x=i, y=j;
			if(is_swaped)swap(x, y);
			if(click[0] == x && click[1] == y)printf("c");
			else if(chk[x][y])printf("*");
			else printf(".");
		}
		puts("");
	}
}

bool solve(int R, int C, int M)
{
	if(M==0){click[0] = 0, click[1] = 0;output(R, C);return true;}
	int rest = R*C - M;
	int i, j;
	if(rest >= 9){
		int cnt = 0;
		for(i=0;i<R-2;i++)for(j=0;j<C-2;j++){
			chk[i][j] = 1, cnt++;
			if(cnt == M){
				click[0] = R-1, click[1] = C-1;
				output(R, C);return true;
			}
		}
		for(i=0;i<R-3;i++){
			chk[R-3][C-3] = 0;
			chk[i][C-2] = chk[i][C-1] = 1;
			cnt++;
			if(cnt == M){
				click[0] = R-1, click[1] = C-1;
				output(R, C);return true;
			}
			chk[R-3][C-3] = 1;
			cnt++;
			if(cnt == M){
				click[0] = R-1, click[1] = C-1;
				output(R, C);return true;
			}
		}
		for(i=0;i<C-3;i++){
			chk[R-3][C-3] = 0;
			chk[R-2][i] = chk[R-1][i] = 1;
			cnt++;
			if(cnt == M){
				click[0] = R-1, click[1] = C-1;
				output(R, C);return true;
			}
			chk[R-3][C-3] = 1;
			cnt++;
			if(cnt == M){
				click[0] = R-1, click[1] = C-1;
				output(R, C);return true;
			}
		}
		printf("??");
		return true;
	}
	if(rest == 2 || rest == 3 || rest == 5 || rest == 7)return false;
	if(rest == 4){
		click[0] = click[1] = 0;
		for(i=0;i<R;i++)for(j=0;j<C;j++)if(i>1||j>1)chk[i][j] = 1;
		output(R, C);
		return true;
	}
	if(rest == 6){
		click[0] = click[1] = 0;
		for(i=0;i<R;i++)for(j=0;j<C;j++)if(i>2||j>1)chk[i][j] = 1;
		output(R, C);
		return true;
	}
	if(rest == 8){
		click[0] = click[1] = 0;
		for(i=0;i<R;i++)for(j=0;j<C;j++)if(i>2||j>2)chk[i][j] = 1;
		chk[2][2] = 1;
		output(R, C);
		return true;
	}
	printf("???");
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int tt=1;tt<=Tc;tt++){
		memset(chk,0,sizeof chk);
		is_swaped = 0;
		printf("Case #%d:\n", tt);
		int R, C, M;
		scanf("%d%d%d",&R,&C,&M);
		if(M == R*C - 1){
			for(int i=0;i<R;i++){for(int j=0;j<C;j++)printf("%c",(!i&&!j)?'c':'*');puts("");}
			continue;
		}
//		if(R<=3&&C<=3){
//			if(!naivesolve(R, C, M))printf("Impossible\n");
//			continue;
//		}
		if(C<=2){
			is_swaped = 1;
			swap(R, C);
		}
		if(R == 1){
			for(int i=0;i<M;i++)chk[0][i] = 1;
			click[0] = 0, click[1] = C-1;
			output(R, C);
			continue;
		}
		if(R == 2){
			if(C==1 && M==0);
			else if((M&1) || R*C-M == 2){printf("Impossible\n");continue;}
			for(int i=0;i<M/2;i++)chk[0][i] = chk[1][i] = 1;
			click[0] = 0, click[1] = C-1;
			output(R, C);
			continue;
		}
		if(!solve(R, C, M))printf("Impossible\n");
	}
	return 0;
}
