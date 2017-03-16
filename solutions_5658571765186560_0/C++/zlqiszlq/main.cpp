#include <iostream>
#include <cstdio>
using namespace std;

int T,X,R,C;

int main()
{
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
	{
		bool ans = false;
		scanf("%d%d%d",&X,&R,&C);
		if (X >= 7)
		{
			goto PRINT;
		}
		if (R*C % X != 0)
		{
			goto PRINT;
		}
		if (R < X && C < X)
		{
			goto PRINT;
		}
		if (X >= 3 && (R <= X/2 || C <= X/2))
		{
			goto PRINT;
		}
		ans = true;
	PRINT:
		printf("Case #%d: ",cases);
		if (ans)
		{
			printf("GABRIEL");
		}
		else
		{
			printf("RICHARD");
		}
		printf("\n");
	}
    return 0;
}
