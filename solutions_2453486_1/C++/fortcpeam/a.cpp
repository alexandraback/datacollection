/*
 * Author: 67h2gak0
 * PROG: A
 * DATE: 2013.4.13
*/
#include <cstdio>

using namespace std;

const int N = 4;

char st[N+3][N+3];
int ret;

void init()
{
	for (int i = 1; i <= N; i ++)
		scanf("%s", st[i] + 1);
}

void work()
{
	ret = 100;
	//line or row
	for (int i = 1; i <= N; i ++){
		int a = 0, b = 0;
		for (int j = 1; j <= N; j ++){
			if (st[i][j] == 'T' || st[i][j] == 'X') a ++;
			if (st[i][j] == 'T' || st[i][j] == 'O') b ++;
		}
		if (a == 4){
			ret = 1; return;
		}
		if (b == 4){
			ret = -1; return;
		}
		a = b = 0;
		for (int j = 1; j <= N; j ++){
			if (st[j][i] == 'T' || st[j][i] == 'X') a ++;
			if (st[j][i] == 'T' || st[j][i] == 'O') b ++;
		}
		if (a == 4){
			ret = 1; return;
		}
		if (b == 4){
			ret = -1; return;
		}
	}
	//dia
	int a = 0, b = 0;
	for (int i = 1; i <= 4; i ++){
		if (st[i][i] == 'T' || st[i][i] == 'X') a ++;
		if (st[i][i] == 'T' || st[i][i] == 'O') b ++;		
	}
	if (a == 4){
		ret = 1; return;
	}
	if (b == 4){
		ret = -1; return;
	}
	a = b = 0;
	for (int i = 1; i <= 4; i ++){
		if (st[i][5-i] == 'T' || st[i][5-i] == 'X') a ++;
		if (st[i][5-i] == 'T' || st[i][5-i] == 'O') b ++;		
	}
	if (a == 4){
		ret = 1; return;
	}
	if (b == 4){
		ret = -1; return;
	}
	//draw
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= N; j ++)
			if (st[i][j] == '.') return;
	ret = 0;
}

void print()
{
	if (ret == 1) puts("X won");
		else if (ret == -1) puts("O won");
		else if (ret == 0) puts("Draw");
		else puts("Game has not completed");
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, t = 0;
	scanf("%d", &T);
	while (T --){
		init();
		work();
		printf("Case #%d: ", ++ t);
		print();
	}
	return 0;
}
