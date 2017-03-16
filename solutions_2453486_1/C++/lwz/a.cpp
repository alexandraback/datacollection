#include<cstdio>
using namespace std;
int test(char *b)
{
	int a,c1,c2;
	c1=0; c2=0;
	for(a=0;a<4;a++)
	{
		if( b[a]=='.' ) return 0;
		if( b[a]=='X' ) c1++;
		if( b[a]=='O' ) c2++;
	}
	if( c1>0 && c2>0 ) return 0;
	if( c1>0 ) return 1;
	if( c2>0 ) return 2;
	return 0;
}
int main()
{
int N,T; scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,s,n;
	bool win[3];
	char b[4][4],t[4];
	for(a=0;a<3;a++) win[a]=0;
	for(a=0;a<4;a++) for(s=0;s<4;s++) scanf(" %c",&b[a][s]);
	for(a=0;a<4;a++)
	{
		for(s=0;s<4;s++) t[s]=b[a][s];
		win[test(t)]++;
	}
	for(s=0;s<4;s++)
	{
		for(a=0;a<4;a++) t[a]=b[a][s];
		win[test(t)]++;
	}
	for(a=0;a<4;a++) t[a]=b[a][a];
	win[test(t)]++;
	for(a=0;a<4;a++) t[a]=b[a][3-a];
	win[test(t)]++;
	printf("Case #%d: ",T);
	if( win[1]>0 ) printf("X won");
	else if( win[2]>0 ) printf("O won");
	else
	{
		for(a=0;a<4;a++) for(s=0;s<4;s++) if( b[a][s]=='.' ) goto notcomplete;
		printf("Draw");
		if( false ) notcomplete: printf("Game has not completed");
	}
	printf("\n");
}
	return 0;
}
