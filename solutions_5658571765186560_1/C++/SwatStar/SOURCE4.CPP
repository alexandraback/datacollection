#include <iostream.h>
#include <conio.h>
#include <fstream.h>

struct grid{
	int X;
	int R;
	int C;
	int result;
}real[100];

void swap (int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void main ()
{
	clrscr ();
	char junk;
	int T, i;
	ifstream filin;
	ofstream filout;
	filout.open ("googout.txt", ios::out);
	filin.open ("googin.in", ios::in);
	filin >> T;
	filin.get(junk);
	for (i = 0; i < T; i++)
	{
		filin >> real[i].X;
		filin.get (junk);
		filin >> real[i].R;
		filin.get (junk);
		filin >> real[i].C;
		filin.get (junk);
		switch (real[i].X)
		{
			case 1:
				real[i].result = 0;
				break;
			case 2:
				if (real[i].R * real[i].C % 2)
					real[i].result = 1;
				else
					real[i].result = 0;
				break;
			case 3:
				if (real[i].R * real[i].C % 3)
					real[i].result = 1;
				else
				{
					if (real[i].R % 3)
						swap (real[i].R, real[i].C);
					if (real[i].C == 1)
						real[i].result = 1;
					else
						real[i].result = 0;
				}
				break;
			case 4:
				if (real[i].R * real[i].C % 4)
					real[i].result = 1;
				else
				{
					if (real[i].R >= 4 && real[i].C >= 4)
						real[i].result = 0;
					else
					{
						if (real[i].R > real[i].C)
							swap (real[i].R, real[i].C);
						switch (real[i].R)
						{
							case 1:
								real[i].result = 1;
								break;
							case 2:
								real[i].result = 1;
								break;
							case 3:
								real[i].result = 0;
								break;
						}
					}
				}
				break;
			case 5:
				if (real[i].R * real[i].C % 5)
					real[i].result = 1;
				else
				{
					if (real[i].R >= 5 && real[i].C >= 5)
						real[i].result = 0;
					else
					{
						if (real[i].R > real[i].C)
							swap (real[i].R, real[i].C);
						switch (real[i].R)
						{
							case 1:
								real[i].result = 1;
								break;
							case 2:
								real[i].result = 1;
								break;
							case 3:
								if (real[i].C == 5)
									real[i].result = 1;
								else
									real[i].result = 0;
								break;
							case 4:
								real[i].result = 0;
								break;
						}
					}
				}
				break;
			case 6:
				if (real[i].R * real[i].C % 6)
					real[i].result = 1;
				else
				{
					if (real[i].R >= 6 && real[i].C >= 6)
						real[i].result = 0;
					else
					{
						if (real[i].R > real[i].C)
							swap (real[i].R, real[i].C);
						switch (real[i].R)
						{
							case 1:
								real[i].result = 1;
								break;
							case 2:
								real[i].result = 1;
								break;
							case 3:
								real[i].result = 1;
								break;
							case 4:
								real[i].result = 0;
								break;
							case 5:
								real[i].result = 0;
								break;
						}
					}
				}
				break;
			default:
				real[i].result = 1;
				break;
		}
		filout << "Case #" << i + 1 << ": ";
		if (real[i].result == 1)
			filout << "RICHARD\n";
		else
			filout << "GABRIEL\n";
	}
	filin.close ();
	filout.close ();
}