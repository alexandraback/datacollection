#include <stdio.h>

int main()
{
	int size;
	int x, c, r, i, ans;

	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);


	scanf("%d", &size);
	for (i=0; i<size ; i++)
	{
		scanf("%d %d %d", &x, &r, &c);
		if((r*c)%x==0)
		{
			if (2>=x)
				ans=1;
			else if (2<x && x<7)
			{
				if(r>x/2 && c>x/2)
				{
					if ((x==5 && r==3 && c==5) || (x==5 && r==5 && c==3))
						ans=0;
					else
						ans=1;

				}
				else
					ans=0;
			}
			else
				ans=0;
		}
		else
			ans=0;

		if (ans)
			printf("Case #%d: GABRIEL\n",i+1);
		else
			printf("Case #%d: RICHARD\n",i+1);
	}

}