#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, r, c, m;
int mini, maxi;
int gut;
bool moszna;

int main()
{
	scanf("%d", &t);
	for (int h=1; h<=t; h++)
	{
		printf("Case #%d", h);
		printf(":\n");
		moszna=0;
		scanf("%d%d%d", &r, &c, &m);
		mini=min(r, c);
		maxi=max(r, c);
		gut=(r*c)-m;
		if (gut==1)
		{
			moszna=true;
			for (int i=1; i<=r; i++)
			{
				for (int j=1; j<=c; j++)
				{
					if (i==1 && j==1)
					printf("c");
					else
					printf("*");
				}
				printf("\n");
			}
		}
		if (moszna)
		continue;
		if (r==1)
		{
			moszna=true;
			if (gut)
			printf("c");
			for (int i=1; i<gut; i++)
			printf(".");
			for (int i=1; i<=c-gut; i++)
			printf("*");
			printf("\n");
		}
		if (moszna)
		continue;
		if (c==1)
		{
			moszna=true;
			if (gut)
			printf("c\n");
			for (int i=1; i<gut; i++)
			printf(".\n");
			for (int i=1; i<=r-gut; i++)
			printf("*\n");
		}
		if (moszna)
		continue;
		for (int i=2; i<=r; i++)
		{
			if (moszna)
			break;
			if ((gut/i)<=c && (gut/i)>1 && ((gut%i)!=1 || ( i>2 && (gut/i)>2)))
			{
				if ((gut%i)!=1)
				{
					for (int j=1; j<=r; j++)
					{
						for (int k=1; k<=c; k++)
						{
							if (j==1 && k==1)
							{
								printf("c");
								continue;
							}
							if ((j<=i && k<=(gut/i)) || (i<r && j==i+1 && k<=(gut%i)) || (i==r && k==(gut/i)+1 && j<=(gut%i)))
							printf(".");
							else
							printf("*");
						}
						printf("\n");
					}
				}
				else
				{
					for (int j=1; j<=r; j++)
					{
						for (int k=1; k<=c; k++)
						{
							if (j==1 && k==1)
							{
								printf("c");
								continue;
							}
							if ((j<=i && k<=(gut/i) && (j!=i || k!=(gut/i))) || (i<r && j==i+1 && k<=2) || (i==r && k==(gut/i)+1 && j<=2))
							printf(".");
							else
							printf("*");
						}
						printf("\n");
					}
				}
				moszna=true;
			}
		}
		if (!moszna)
		printf("Impossible\n");
	}
	return 0;
}
