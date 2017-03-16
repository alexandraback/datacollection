#include "stdio.h"

int T,ca=1;
char s[20][20];

int get_st(char a)
{
	int p = 0;
	if( 'O' == a ) p = 1;
	else if( 'X' == a ) p = 2;
	else if( '.' == a ) p = 4;
	return p;
}

bool end(int st)
{
	if( 1 == st || 2 == st)
	{
		printf("Case #%d: %s\n",ca++,((1==st)?"O won":"X won"));
		return true;
	}
	return false;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		bool empty = false;
		int i,j;
		for(i=0;i<4;i++)
		{
			scanf("%s",s[i]);
			for(j=0;j<4;j++)
			{
				if( '.' == s[i][j] ) 
					empty = true;
			}
		}
		for(i=0;i<4;i++)
		{
			int p = 0,q = 0,r = 0,t = 0;
			for(j=0;j<4;j++)
			{
				p |= get_st(s[i][j]);
				q |= get_st(s[j][i]);
				r |= get_st(s[j][j]);
				t |= get_st(s[j][3-j]);
			}
			if( end(p) ) break;
			if( end(q) ) break;
			if( end(r) ) break;
			if( end(t) ) break;
		}
		if( 4 <= i )
		{
			printf("Case #%d: %s\n",ca++,(empty?"Game has not completed":"Draw"));
		}
	}
	return 0;
}

