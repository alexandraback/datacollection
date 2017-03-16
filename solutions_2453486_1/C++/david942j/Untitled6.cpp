//by david942j
#include <cstdio>
const int N=4;
char s[N+1][N+2];
int tx,ty;
bool checkemp()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(s[i][j]=='.')
				return true;
	return false;
}
bool check(char c)
{
	s[tx][ty]=c;
	bool ok=false;
	for(int i=0;i<N;i++)
		if(s[i][0]==c && s[i][1]==c && s[i][2]==c && s[i][3]==c)
			ok=true;
	for(int j=0;j<N;j++)
		if(s[0][j]==c && s[1][j]==c && s[2][j]==c && s[3][j]==c)
			ok=true;
	if(s[0][0]==c && s[1][1]==c && s[2][2]==c && s[3][3]==c)
		ok=true;
	if(s[0][3]==c && s[1][2]==c && s[2][1]==c && s[3][0]==c)
		ok=true;
	return ok;
}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<N;i++)
			scanf("%s",s[i]);
		tx=4;ty=4;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(s[i][j]=='T')
					tx=i,ty=j;
		printf("Case #%d: ",w++);
		bool emp=checkemp(),X=check('X'),O=check('O');
		if(X)puts("X won");
		else if(O)puts("O won");
		else if(emp)puts("Game has not completed");
		else puts("Draw");
	}
	scanf(" ");
}
/*
XOXX
.O.O
.O.O
XOXX
*/
