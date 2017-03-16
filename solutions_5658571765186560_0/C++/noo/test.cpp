#include <stdio.h>

FILE *input = fopen("c://input.txt", "r");
FILE *output = fopen("c://output.txt", "w");

int x, r, c;

void pro(int a);

int main()
{	
	int t;
	fscanf (input, "%d", &t);
	for (int i = 0; i < t; i++)
		pro(i + 1);
	return 0;
}

void pro(int a)
{
	fscanf (input, "%d %d %d", &x, &r, &c);
	fprintf (output, "Case #%d: ", a);
	if (r * c % x != 0)
	{
		fprintf (output, "RICHARD\n");
		return;
	}
	if (x == 1)
	{
		fprintf (output, "GABRIEL\n");
		return;
	}
	if (x == 2)
	{
		fprintf (output, "GABRIEL\n");
		return;
	}
	if (x == 3)
	{
		if (c == 1 || r == 1)
		{
			fprintf (output, "RICHARD\n");
			return;
		}
		else
		{
			fprintf (output, "GABRIEL\n");
			return;
		}
	}
	if (x == 4)
	{
		if (c <= 2 || r <= 2)
		{
			fprintf (output, "RICHARD\n");
			return;
		}
		else
		{
			fprintf (output, "GABRIEL\n");
			return;
		}
	}
}
