#include <stdio.h>

FILE *input = fopen("c://input.txt", "r");
FILE *output = fopen("c://output.txt", "w");

int d, p[1100];

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
	int low = 1, high = 0, mid; 
	fscanf (input, "%d", &d);
	for (int i = 0; i < d; i++)
	{
		fscanf (input, "%d", &p[i]);
		high = high < p[i] ? p[i] : high;
	}
	fprintf (output, "Case #%d: ", a);
	while (low < high)
	{
		mid = (low + high) / 2;
		for (int i = mid; i >= 0; i--)
		{
			if (i == 0)
			{
				low = mid + 1;
				break;
			}
			int sum = i;
			for (int j = 0; j < d; j++)
				sum += ((p[j] - 1) / i);
			if (sum <= mid)
			{
				high = mid;
				break;
			}
		}
	}
	fprintf (output, "%d\n", high);
}
