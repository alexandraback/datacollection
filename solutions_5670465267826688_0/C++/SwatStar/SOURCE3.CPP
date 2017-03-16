#include <iostream.h>
#include <fstream.h>
#include <conio.h>

char scalar (char current, char temp)
{
	switch (current)
	{
		case 'a':
			switch (temp)
			{
				case 'I':
					return 'I';
				case 'J':
					return 'J';
				case 'K':
					return 'K';
				case 'A':
					return 'A';
				case 'i':
					return 'i';
				case 'j':
					return 'j';
				case 'k':
					return 'k';
				case 'a':
					return 'a';
			}
		case 'i':
			switch (temp)
			{
				case 'I':
					return 'a';
				case 'J':
					return 'K';
				case 'K':
					return 'j';
				case 'A':
					return 'I';
				case 'i':
					return 'A';
				case 'j':
					return 'k';
				case 'k':
					return 'J';
				case 'a':
					return 'i';
			}
		case 'j':
			switch (temp)
			{
				case 'I':
					return 'k';
				case 'J':
					return 'a';
				case 'K':
					return 'I';
				case 'A':
					return 'J';
				case 'i':
					return 'K';
				case 'j':
					return 'A';
				case 'k':
					return 'i';
				case 'a':
					return 'j';
			}
		case 'k':
			switch (temp)
			{
				case 'I':
					return 'J';
				case 'J':
					return 'i';
				case 'K':
					return 'a';
				case 'A':
					return 'K';
				case 'i':
					return 'j';
				case 'j':
					return 'I';
				case 'k':
					return 'A';
				case 'a':
					return 'k';
			}
		case 'A':
			switch (temp)
			{
				case 'I':
					return 'i';
				case 'J':
					return 'j';
				case 'K':
					return 'k';
				case 'A':
					return 'a';
				case 'i':
					return 'I';
				case 'j':
					return 'J';
				case 'k':
					return 'K';
				case 'a':
					return 'A';
			}
		case 'I':
			switch (temp)
			{
				case 'I':
					return 'A';
				case 'J':
					return 'k';
				case 'K':
					return 'J';
				case 'A':
					return 'i';
				case 'i':
					return 'a';
				case 'j':
					return 'K';
				case 'k':
					return 'j';
				case 'a':
					return 'I';
			}
		case 'J':
			switch (temp)
			{
				case 'I':
					return 'K';
				case 'J':
					return 'A';
				case 'K':
					return 'i';
				case 'A':
					return 'j';
				case 'i':
					return 'k';
				case 'j':
					return 'a';
				case 'k':
					return 'I';
				case 'a':
					return 'J';
			}
		case 'K':
			switch (temp)
			{
				case 'I':
					return 'j';
				case 'J':
					return 'I';
				case 'K':
					return 'A';
				case 'A':
					return 'k';
				case 'i':
					return 'J';
				case 'j':
					return 'i';
				case 'k':
					return 'a';
				case 'a':
					return 'K';
			}
	}
	return 'a';
}

void main ()
{
	clrscr ();
	char junk, current = 'a', temp, info[60000], temp_current;
	int T, i, L, j, X, can, temp_j, temp_j_2;
	ifstream filin;
	filin.open ("googin.in", ios::in);
	ofstream filout;
	filout.open ("googout.txt", ios::out);
	filin >> T;
	filin.get (junk);
	for (i = 0; i < T; i++)
	{
		current = 'a';
		filin >> L;
		filin.get (junk);
		filin >> X;
		filin.get (junk);
		for (j = 0; j < L; j++)
			filin >> info[j];
		for (j = 0; j < L; j++)
			cout << info[j] << " ";
		filin.get(junk);
		for (j = 0; j < 4 * L; j++)
		{
			current = scalar (current, info[j % L]);
			cout << current << " ";
			if (current == 'i')
				break;
		}
		if (j == 4 * L)
			can = 0;
		else
		{
			temp_j = j + 1;
				cout << temp_j << " ";
			current = 'a';
			for (j = 4 * L - 1; j >= 0; j--)
			{
				cout << info[j % L];
				current = scalar (info[j % L], current);
				cout << current << " ";
				if (current == 'k')
					break;
			}
			if (j == -1)
				can = 0;
			else
			{
				temp_j_2 = j;
				if (temp_j + (4 * L - temp_j_2) >= L * X)
					can = 0;
				else
				{
					temp_current = 'a';
					for (j = 0; j < L; j++)
					{
						temp_current = scalar (temp_current, info[j]);
					}
					switch (temp_current)
					{
						case 'a':
							can = 0;
							break;
						case 'A':
							if (X % 2)
								can = 1;
							else
								can = 0;
							break;
						case 'i':
							if (X % 4 == 2)
								can = 1;
							else
								can = 0;
							break;
						case 'I':
							if (X % 4 == 2)
								can = 1;
							else
								can = 0;
							break;
						case 'j':
							if (X % 4 == 2)
								can = 1;
							else
								can = 0;
							break;
						case 'J':
							if (X % 4 == 2)
								can = 1;
							else
								can = 0;
							break;
						case 'k':
							if (X % 4 == 2)
								can = 1;
							else
								can = 0;
							break;
						case 'K':
							if (X % 4 == 2)
								can = 1;
							else
								can = 0;
							break;
					}
				}
			}
		}
		filout << "Case #" << i + 1 << ": ";
		if (can)
			filout << "YES\n";
		else
			filout << "NO\n";
	}
	filin.close ();
	filout.close ();
	cout << "Done";
	getch ();
}