#include <cstdio>

int T, x, y;
char f, s;

int main()
{
	scanf("%d", &T);
	for(int tt = 1; tt <= T; ++tt)
	{
		scanf("%d%d", &x, &y);
		
		printf("Case #%d: ", tt);
		if(y > 0)
		{
			f = 'S';
			s = 'N';
		}
		else
		{
			f = 'N';
			s = 'S';
			y = -y;
		}
		for(int i = 0; i < y; ++i)
			printf("%c%c", f, s);
		
		if(x > 0)
		{
			f = 'W';
			s = 'E';
		}
		else
		{
			f = 'E';
			s = 'W';
			x = -x;
		}
		for(int i = 0; i < x; ++i)
			printf("%c%c", f, s);
		
		printf("\n");
	}
	
	return 0;
}
