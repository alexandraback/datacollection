#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ", ++TK);
		int X = 0;
		int R = 0;
		int C = 0;
		scanf("%d %d %d",&X,&R,&C);
		if(X == 1) puts("GABRIEL");
		else if(X == 2)
		{
			if(R % 2 == 0 || C % 2 == 0) puts("GABRIEL");
			else puts("RICHARD");
		}
		else if(X == 3)
		{
			if(R > C) swap(R, C);
			if((R != 3 && C != 3) || (R == 1 && C == 3)) puts("RICHARD");
			else puts("GABRIEL");
		}
		else if(X == 4)
		{
			if(R > C) swap(R, C);
			if( (R == 3 && C == 4) || (R == 4 && C == 4) ) puts("GABRIEL");
			else puts("RICHARD");
		}
		else assert(false);
	}
	return 0;
}