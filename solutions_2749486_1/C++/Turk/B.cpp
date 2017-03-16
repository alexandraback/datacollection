// 1Aa.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int solve(int x, int y, char* seq);

//#define TESTING
#define L 50000

int main()
{
	int T;
	char strBuff[L];
	int x, y;


	ifstream fin;
	fstream fout;
#ifdef TESTING
	fin.open("example.txt", ifstream::in);
#else
	fin.open("B.txt", ifstream::in);
#endif

	fout.open("Output.txt", fstream::out);

	fin.getline(strBuff, 10);

	sscanf(strBuff, "%d", &T);

	for (int i = 0; i < T; i++)
	{
		fout << "Case #" << (i+1) << ": ";


		fin.getline(strBuff, L);
		sscanf(strBuff, "%d %d", &x, &y);

		solve(x, y, strBuff);


		fout << strBuff << "\n";

	}
	fout.close();

#ifdef TESTING
	fout.open("Output.txt", fstream::in);
	char cmpStrBuff[L];

	fin.seekg(1, ios_base::cur);//go past the tab
	fout.flush();
	fout.seekg(ios_base::beg);

	for (int i = 0; i < T; i++)
	{
		fin.getline(strBuff, 50);
		fout.getline(cmpStrBuff, 50);
		if (strcmp(strBuff, cmpStrBuff))
		{
			printf("Test failed:\n%s\n%s\n", strBuff, cmpStrBuff);
		}
	}

	printf("All tests completed\n");
	cin.get();

#endif


	fout.close();
	
	fin.close();
}

int solve (int x, int y, char* seq)
{
	int posx = 0;
	int posy = 0;
	int jump = 1;

	while (x != posx || y != posy)
	{
		if (abs(x - posx) > jump / 2 || abs(y - posy) > jump / 2)
		{
			if (abs(x-posx) > abs(y-posy))
			{
				//travel x
				if (x > posx)
				{
					posx += jump;
					seq[jump-1] = 'E';
					jump++;
				}
				else
				{
					posx -= jump;
					seq[jump-1] = 'W';
					jump++;
				}
			} 
			else
			{
				//travel y
				if (y > posy)
				{
					posy += jump;
					seq[jump-1] = 'N';
					jump++;
				}
				else
				{
					posy -= jump;
					seq[jump-1] = 'S';
					jump++;
				}
			}

		}
		else 
		{
			//close in
			if ((abs(posx - x) > 1 && abs(posy-y) > 0) || (abs(posx - x) > 0 && abs(posy-y) > 1))
			{
				//move in a square
				if (x > posx && y > posy)
				{
					posx += 2; posy += 2;
					strcpy(&seq[jump-1], "WSEN");
					jump+=4;
				}
				else if (x < posx && y > posy)
				{
					posx -= 2; posy += 2;
					strcpy(&seq[jump-1], "ESWN");
					jump+=4;
				}
				else if (x > posx && y < posy)
				{
					posx += 2; posy -= 2;
					strcpy(&seq[jump-1], "WNES");
					jump+=4;
				}
				else
				{
					posx -= 2; posy -= 2;
					strcpy(&seq[jump-1], "ENWS");
					jump+=4;
				}
			}
			else
			{
				//move 1 square
				if (posx > x)
				{
					posx--;
					strcpy(&seq[jump-1], "EW");
					jump+=2;
				}
				else if (x > posx)
				{
					posx++;
					strcpy(&seq[jump-1], "WE");
					jump+=2;
				}
				if (posy > y)
				{
					posy--;
					strcpy(&seq[jump-1], "NS");
					jump+=2;
				}
				else if (y > posy)
				{
					posy++;
					strcpy(&seq[jump-1], "SN");
					jump+=2;
				}
			}
		}
		if (jump > L-5) {
			printf("Error: too long\n");
			cin.get();
			break;
		}
	}

	seq[jump-1] = '\0';
	return jump-1;
}