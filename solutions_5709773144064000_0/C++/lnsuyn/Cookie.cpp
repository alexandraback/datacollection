#include <stdio.h>

int main(void)
{
	int t ,i;
	double c ,f ,x ,ans ,temp ,temp2;
	double up;
	
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		scanf("%lf %lf %lf" ,&c ,&f ,&x);
		up=2;
		ans=x/up;
		temp2=c/up;
		while (1)
		{
			up+=f;
			temp=(x/up)+temp2;
			if (temp>ans)
			{
				break;	
			}	
			else
			{
				ans=temp;
				temp2+=c/up;
			}
		}
		printf("Case #%d: %.7f\n" ,i ,ans);
	}
	
	return 0;
}
