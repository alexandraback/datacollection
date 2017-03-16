#include <cstdio>
#include <cstring>

void Open()
{
	freopen("P2.in", "r", stdin);
	freopen("P2.out", "w", stdout);
}

void Close()
{
	fclose(stdin);
	fclose(stdout);
}

void Work()
{
	int X, Y, T;
	scanf ("%d", &T);
	for (int k = 0; k < T; k++)
	{
		scanf ("%d %d\n",&X, &Y);
		printf ("Case #%d: ", k+1);
		bool state = true;
		if (X > 0)
			state = true;
		else
			state = false, X = -X;
		for (int i = 0; i < X; i++)
			if (state) printf ("WE");
			else printf ("EW");
		if (Y > 0)
			state = true;
		else
			state = false, Y = -Y;
		for (int i = 0; i < Y; i++)
			if (state) printf ("SN");
			else printf ("NS");
		printf ("\n");
	}
}

int main()
{
	Open();
	Work();
	Close();
	return 0;
}