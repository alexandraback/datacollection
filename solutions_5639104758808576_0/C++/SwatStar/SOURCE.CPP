#include <iostream.h>
#include <fstream.h>
#include <conio.h>

void main()
{
	clrscr();
	int i, j, out[100], count, Sm, T, S[1000], c_score;
	char junk, S_1[1000];
	ifstream filin;
	filin.open("googin.in", ios::in);
	filin >> T;
	filin.get(junk);
	cout << T;
	getch ();
	for (j = 0; j < T; j++)
	{
		filin >> Sm;
		filin.get(junk);
		cout << "\n" << Sm;
		for (i = 0; i <= Sm; i++)
		{
			filin >> S_1[i];
			S[i] = S_1[i] - 48;
			cout << S[i] << " ";
		}
		c_score = 0;
		count = 0;
		for (i = 0; i <= Sm; i++)
		{
			if (c_score >= i)
			{
				c_score += S[i];
			}
			else
			{
				count += (i - c_score);
				c_score += (i - c_score + S[i]);
			}
		}
		out[j] = count;
		cout << j << out[j];
	}
	filin.close();
	ofstream filout;
	filout.open("googout.txt", ios::out);
	for (j = 0; j < T; j++)
	{
		filout << "Case #" << j + 1 << ": " << out[j] << "\n";
	}
	filout.close();
	getch();
}