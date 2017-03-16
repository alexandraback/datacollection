#include <cstdio>
char s[10][10];

bool check(char p)
{
	for(int i = 0; i < 4; i ++)
	{
		int cnt = 0;
		for(int j = 0; j < 4; j ++)
			if(s[i][j] == p || s[i][j] == 'T') cnt ++;
		if(cnt == 4) return true;
		cnt = 0;
		for(int j = 0; j < 4; j ++)
			if(s[j][i] == p || s[j][i] == 'T') cnt ++;
		if(cnt == 4) return true;
	}
	int cnt = 0;
	for(int i = 0; i < 4; i ++)
		if(s[i][i] == p || s[i][i] == 'T') cnt ++;
	if(cnt == 4) return true;
	cnt = 0;
	for(int i = 0; i < 4; i ++)
		if(s[i][3 - i] == p || s[i][3 - i] == 'T') cnt ++;
	if(cnt == 4) return true;
	return false;
}

bool draw()
{
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++)
			if(s[i][j] == '.') return false;
	return true;
}

void work()
{
	for(int i = 0; i < 4; i ++)
		scanf("%s", s[i]);
	if(check('X')) printf("X won\n");
	else if(check('O')) printf("O won\n");
	else if(draw()) printf("Draw\n");
	else printf("Game has not completed\n");
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int i = 1; i <= _; i ++)
		printf("Case #%d: ", i), work();
	return 0;
}
