#include <stdio.h>

int main()
{
	int ile, X, Y;
	scanf("%d", &ile);
	for(int i = 1 ; i <= ile ; ++i)
	{
		scanf("%d %d", &X, &Y);

		int indeks = 0;
		char out[500] = {};

		if(Y > 0)
		{
			for(int i = Y ; i > 0 ; --i)
			{
				out[indeks] = 'S';
				out[indeks+1] = 'N';
				indeks += 2;
			}
		}
		else
		{
			for(int i = Y ; i < 0 ; ++i)
			{
				out[indeks] = 'N';
				out[indeks+1] = 'S';
				indeks += 2;
			}
		}

		if(X > 0)
		{
			for(int i = X ; i > 0 ; --i)
			{
				out[indeks] = 'W';
				out[indeks+1] = 'E';
				indeks += 2;
			}
		}
		else
		{
			for(int i = X ; i < 0 ; ++i)
			{
				out[indeks] = 'E';
				out[indeks+1] = 'W';
				indeks += 2;
			}
		}

		printf("Case #%d: %s\n", i, out);
	}
	return 0;
}
