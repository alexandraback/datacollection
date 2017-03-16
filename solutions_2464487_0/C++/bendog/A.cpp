#include<stdio.h>
int area(int x)
{
	return x*x;
}
int main()
{
		int r,t;
		int q = 1;
		int cas;
		scanf("%d",&cas);
		for(q = 1; q<=cas ; q++)
		{
			scanf("%d %d",&r,&t);
			int cnt = 0;
			int i = 1;
			while(true)
			{
				int a = area(r+i) - area(r+i-1);
				//printf("A : %d\n",a);
				if( t >= a){cnt++;t-=a;}
				else break;
				i+=2;
			}
			printf("Case #%d: %d\n",q,cnt);
		}
	return 0;
}
