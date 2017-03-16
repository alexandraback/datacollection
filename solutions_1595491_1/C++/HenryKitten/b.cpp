#include <stdio.h>

int main()
{
	int ncas;
	scanf("%d",&ncas);
	for(int t=1;t<=ncas;t++)
	{
		int n,s,p;
		scanf("%d %d %d",&n,&s,&p);
		
		int y = 0;
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			int q = m/3 + (m%3 != 0); 
			if(q >= p) 
			{
				y++;
			}
			else if(s>0 && q+1 >= p)
			{
				int re = m - q - 1;
				if(re >= 0 && re/2 >= q-1)
				{
					y++;
					s--;
				}	
			}
		}
		printf("Csae #%d: %d\n",t,y);
	}
	return 0;
}
