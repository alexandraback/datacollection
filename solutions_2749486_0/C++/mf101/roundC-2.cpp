#include <iostream>
#include<algorithm>


using namespace std;

int main()
{

	int test;
	scanf("%d",&test);

	int X,Y;
	for(int t = 1 ; t <= test; t++)
	{
		scanf("%d %d",&X,&Y);

		printf("Case #%d: ",t);
		if(X > 0)
		{
			printf("E");
			X--;
			while(X--)printf("WE");
		}
		else if(X < 0)
		{
			X = -X;
			printf("W");
			X--;
			while(X--)printf("EW");
		}

		if(Y > 0)
		{
			
			if(!X) printf("N");
			else printf("SN");

			Y--;
			while(Y--)printf("SN");
		}
		else if(Y < 0)
		{
			Y = -Y;

			if(!X) printf("S");
			else printf("NS");

			Y--;
			while(Y-- > 0)printf("NS");
		}
	
		printf("\n");
	}

	return 0;
}