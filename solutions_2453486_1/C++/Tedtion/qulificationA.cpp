#include <stdio.h>
int h[128];
char check(char b[][8]);
int main()
{
	int t,i;
	char b[8][8];
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	h['T'] = 0;
	h['X'] = 1;
	h['O'] = 10;
	h['.'] = 100;
	scanf("%d",&t);
	for (int cas = 1; cas <= t; cas++)
	{
		for (i=0; i<4; i++) scanf("%s",b[i]);
		char res = check(b); 
		printf("Case #%d: ", cas);
		if (res=='E') printf("Draw\n");
		else if (res=='C') printf("Game has not completed\n");
		else printf("%c won\n", res);
	}
	return 0;
}

char check(char b[][8])
{
	int i,j,s,sc;
	char res='E';
	for (i=0; i<4; i++)
	{
		s=sc=0;
		for (j=0; j<4; j++) s+=h[b[i][j]], sc+=h[b[j][i]];
		if (s<=4 || sc<=4) return 'X';
		if (s==30 || s==40 || sc==30 || sc==40) return 'O';
		if (s>=100 || sc>=100) res = 'C';
	}
	s=sc=0;
	for (j=0; j<4; j++) s+=h[b[j][j]], sc+=h[b[j][3-j]];
	if (s<=4 || sc<=4) return 'X';
	if (s==30 || s==40 || sc==30 || sc==40) return 'O';
	if (s>=100 || sc>=100) res = 'C';
	return res;
}
		
