#include<stdio.h>

char a[111][111], N = 4;
int T;
int tx, ty;

int Go(char target)
{
	int l1, l2;

	if(tx >= 0 && ty >= 0)
	{
		a[tx][ty] = target;
	}

	for(l1=0;l1<N;l1++)
	{
		if(a[l1][0] == target && a[l1][1] == target && a[l1][2] == target && a[l1][3] == target) return 1;
		if(a[0][l1] == target && a[1][l1] == target && a[2][l1] == target && a[3][l1] == target) return 1;
	}
	if(a[0][0] == target && a[1][1] == target && a[2][2] == target && a[3][3] == target) return 1;
	if(a[3][0] == target && a[2][1] == target && a[1][2] == target && a[0][3] == target) return 1;

	return 0;
}

int Full(void)
{
	int l1, l2;
	for(l1=0;l1<N;l1++) for(l2=0;l2<N;l2++) if(a[l1][l2] == '.') return 0;
	return 1;
}

int main(void)
{
	int l1, l2, l0;

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		for(l1=0;l1<N;l1++) scanf("%s",a[l1]);
		tx=ty=-1;
		for(l1=0;l1<N;l1++) for(l2=0;l2<N;l2++) if(a[l1][l2]=='T'){ tx=l1; ty=l2; }

		printf("Case #%d: ",l0);

		if(Go('X')) printf("X won");
		else if(Go('O')) printf("O won");
		else if(Full()) printf("Draw");
		else printf("Game has not completed");
		printf("\n");
	}
}
