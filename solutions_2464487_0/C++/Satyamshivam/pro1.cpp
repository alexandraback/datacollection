#include <stdio.h>
#include <math.h>
int main()
{

freopen("test.in", "r", stdin);
freopen("out.txt", "w", stdout);
int i, j,  x, count, te;
long long int r, t;
scanf("%d", &te);
for(i=1; i<=te; i++)
{
	
	scanf("%d%d", &r, &t);
	count = 0;
	for(j=0; ; j+=2)
	{
		x = (( r+j+1)*(r+j+1) - (r+j)*(r+j));
		if(t>=x)
		{
			count ++;
			t = t -x;
		}
		else
		{
			break;
		}
		
	}
	printf("Case #%d: %d\n", i, count);
}

return 0;
}
