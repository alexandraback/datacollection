#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    int T, N;
    fin >> T;
    
    char map[4][4];
    int XwinSumT = 'X' + 'X' + 'X' + 'T';
    int XwinSum = 'X' + 'X' + 'X' + 'X';
    int OwinSumT = 'O' + 'O' + 'O' + 'T';
    int OwinSum = 'O' + 'O' + 'O' + 'O';

    for (int t = 1 ; t <= T; t++)
    {  
		for (int i = 0 ; i < 4 ; i++)
			for (int j = 0 ; j < 4 ; j++)
				fin >> map[i][j];
		
		bool Xwin = false;
		bool Owin = false;

		int diagonal1 = 0;
		int diagonal2 = 0;
		for (int i = 0 ; i < 4 ; i++)
		{
			diagonal1 += map[i][i];
			diagonal2 += map[3-i][i];
			int rowSum = 0;
			int columnSum = 0;
			for (int j = 0 ; j < 4 ; j++)
			{
				rowSum += map[i][j];
				columnSum += map[j][i];
			}	
			if (rowSum == XwinSumT || rowSum == XwinSum)
				{Xwin = true; break;}
			if (columnSum == XwinSumT || columnSum == XwinSum)
				{Xwin = true; break;}
			if (rowSum == OwinSumT || rowSum == OwinSum)
				{Owin = true; break;}
			if (columnSum == OwinSumT || columnSum == OwinSum)
				{Owin = true; break;}				
		}	
		
		if (diagonal1 == XwinSumT || diagonal1 == XwinSum)
			Xwin = true; 
		if (diagonal2 == XwinSumT || diagonal2 == XwinSum)
			Xwin = true; 
		if (diagonal1 == OwinSumT || diagonal1 == OwinSum)
			Owin = true; 
		if (diagonal2 == OwinSumT || diagonal2 == OwinSum)
			Owin = true; 	
		
		fout << "Case #" << t << ": ";
		
		if (Xwin)
			fout << "X won" << endl;
		else if (Owin)
			fout << "O won" << endl;
		else
		{
			bool gameover = true;
			for (int i = 0 ; i < 4 ; i ++)
			{
				for (int j = 0 ; j < 4 ; j++)
					if (map[i][j] == '.')
					{gameover = false; break;}
				if (gameover == false) break;
			}
			if (gameover)
				fout << "Draw" << endl;
			else
				fout << "Game has not completed" << endl;
		}
    }
}
