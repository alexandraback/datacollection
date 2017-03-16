#include <cstdio>

char a[4][5];
int c[10][128];

char *solve()
{
	
	bool completed = true;
	for (int i = 0; i < 10; i++)
		c[i]['O'] = c[i]['X'] = c[i]['T'] = c[i]['.'] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			c[i][a[i][j]]++;
			c[j + 4][a[i][j]]++;
		}
		c[8][a[i][i]]++;
		c[9][a[i][3 - i]]++;
	}
	for (int i = 0; i < 10; i++) {
		if (c[i]['X'] + c[i]['T'] == 4)
			return "X won";
		if (c[i]['O'] + c[i]['T'] == 4)
			return "O won";
		if (c[i]['.'])
			completed = false;
	}
	if (completed)
		return "Draw";
	return "Game has not completed";
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++)
			scanf("%s", a[j]);
		printf("Case #%d: %s\n", i, solve());
	}
}