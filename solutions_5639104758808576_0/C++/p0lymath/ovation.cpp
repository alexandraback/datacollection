#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	for (int t=1; t<=T; t++)
	{
		int smax;
		char shycounts[2000];
		scanf("%d%s", &smax, shycounts);

		int numstanding = shycounts[0]-'0';
		int numrequired = 0;

		for (int i=1; i<=smax; i++)
		{
			int n = shycounts[i]-'0';
			if (n>0 && numstanding<i)
			{
				numrequired += (i-numstanding);
				numstanding += (i-numstanding);
			}
			numstanding += n;
		}

		printf("Case #%d: %d\n", t, numrequired);
	}
	return 0;
}
