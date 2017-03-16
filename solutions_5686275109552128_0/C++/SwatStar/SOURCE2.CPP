#include <iostream.h>
#include <fstream.h>
#include <conio.h>

void sort (int P[])
{
	int i, j, temp;
	for (i = 0; i < 1999; i++)
	{
		for (j = 0; j < 1999 - i; j++)
		{
			if (P[j] < P[j + 1])
			{
				temp = P[j];
				P[j] = P[j + 1];
				P[j + 1] = temp;
			}
		}
	}
}

void insert (int k, int P[])
{
	int i, j;
	for (i = 0; P[i] > k; i++);
	for (j = 1998; j >= i; j--)
		P[j + 1] = P[j];
	P[i] = k;
}

void split (int P[])
{
	int i, k1, k2;
	if (P[0] % 2)
	{
		k1 = P[0] / 2;
		k2 = k1 + 1;
	}
	else
	{
		k1 = P[0] / 2;
		k2 = k1;
	}
	insert (k2, P);
	insert (k1, P);
	for (i = 0; P[i] != 0; i++)
	{
		P[i] = P[i + 1];
	}
}

void main()
{
	clrscr();
	int T, i, count, counter[100], P[2000], j, k, diff, D;
	char junk;
	ifstream filin;
	filin.open("googin.in", ios::in);
	filin >> T;
	filin.get(junk);
	for (j = 0; j < T; j++)
	{
		count = 0;
		filin >> D;
		filin.get (junk);
		for (i = 0; i < 2000; i++)
			P[i] = 0;
		for (i = 0; i < D; i++)
		{
			filin >> P[i];
			filin.get(junk);
		}
		sort (P);
		for (i = 0; P[i] != 0; i++)
		{
			diff = P[0] - P[i + 1];
			if (diff >= (i + 1))
				if (P[0] >= 2 * (i + 1))
				{
					split (P);
					count++;
					i = 0;
				}
		}
		count += P[0];
		counter[j] = count;
	}
	filin.close ();
	ofstream filout;
	filout.open ("googout.txt", ios::out);
	for (i = 0; i < T; i++)
		filout << "Case #" << i + 1 << ": " << counter[i] << "\n";
	filout.close ();
}