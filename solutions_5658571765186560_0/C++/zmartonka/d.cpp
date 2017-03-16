#include <stdio.h>
#include <vector>

using std::vector;

bool canWin(int X, int R, int C)
{
	if (R> C)
	{
		int tmp = R;
		R = C;
		C = tmp;
	}
	if(X>6) return true;
	switch(X)
	{
		case 1:
		{			
			return false;
		}
		case 2:
		{	
			if (R * C % 2)
			{
				return true;
			}
			return false;
		}		
		case 3:
		{	
			if (R * C % 3)
			{
				return true;
			}
			if (R<2)
			{
				return true;
			}
			return false;
		}		
		case 4:
		{	
			if (R * C % 4)
			{
				return true;
			}
			if (R<3)
			{
				return true;
			}
			return false;
		}		
		case 5:
		{	
			if (R * C % 5)
			{
				return true;
			}
			if (R<3)
			{
				return true;
			}
			return false;
		}		
		case 6:
		{	
			if (R * C % 6)
			{
				return true;
			}
			if (R<4)
			{
				return true;
			}
			return false;
		}		
	}
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int tn = 0; tn<T; ++tn)
	{
		int X,R,C;
		scanf("%d%d%d",&X,&R,&C);
		if (canWin(X,R,C))
		{
			printf("Case #%d: RICHARD\n",tn + 1);
		}
		else
		{
			printf("Case #%d: GABRIEL\n",tn + 1);			
		}
	}
	return 0;
}