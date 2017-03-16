// code_jam_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//#define DEBUG 1
using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i) << ", ";
	}
	str << "]";
	return str;
}

template<typename T>
ostream& operator<<(ostream& str, const vector<vector<T>> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			str << v[i][j];
		}
		str << endl;
	}
	return str;
}


template<typename T>
ostream& operator<<(ostream& str, const vector<pair<T,T>> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i).first << "-" << v.at(i).second << ", ";
	}
	str << "]";
	return str;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	ifstream ifs("C-large.in", ifstream::in);
	ofstream ofs("C-large.out", ifstream::out);
	ifs >> T;
	for (int i = 0; i < T; i++)
	{
		ofs << "Case #"<<i+1<<":" << endl;
		int R,C,M;
		ifs >> R >> C >> M;
#ifdef DEBUG
		ofs << "R: " << R << endl;
		ofs << "C: " << C << endl;
		ofs << "M: " << M << endl;
#endif
		vector<vector<char>> field(R, vector<char>(C, '.'));

		if (R == 1)
		{
			for (int x = 1; x <= M; x++)
			{
				field[0][C-x] = '*';
			}
			field[0][0]='c';
			ofs << field;
		} else if (C == 1)
		{
			for (int y = 1; y <= M; y++)
			{
				field[R-y][0] = '*';
			}
			field[0][0]='c';
			ofs << field;
		} else {
			int free = C*R-M;
			
			if (free == 2 ||
				free == 3 ||
				free == 5 ||
				free == 7) {
				ofs << "Impossible" << endl;
				continue;
			}

			if (free == 1)
			{
				field = vector<vector<char>>(R, vector<char>(C, '*'));
				field[0][0]='c';
				ofs << field;
				continue;
			} else if (free == 4)
			{
				field = vector<vector<char>>(R, vector<char>(C, '*'));
				field[0][0]='c';
				field[0][1] = '.';
				field[1][1] = '.';
				field[1][0] = '.';
				ofs << field;
				continue;
			}


			int row = field.size()-1;
			while (M >= C && row > 2)
			{
				for (int i = 0; i < C; i++)
				{
					field[row][i] = '*';
				}
				row--;
				M -= C;
			}

#ifdef DEBUG
			ofs << "after filling rows: M: " << M << "\n" << field << endl;
#endif 
			int col = field.at(0).size() -1;

#ifdef DEBUG			
			ofs << "col: " << col << " row: " << row << endl;
#endif

			while (M >= row+1 && col > 2)
			{
				for (int i = 0; i <= row; i++)
				{
					field[i][col] = '*';
				}
				col--;
				M -= (row+1);
			}

			
#ifdef DEBUG
			ofs << "after filling cols: \n" << field << endl;

		ofs << "todo: " << M << endl;
	ofs << "col: " << col << " row: " << row << endl;
#endif

			if (col == 2 && row == 2)
			{
				switch(M)
				{
				case 0:
					break;
				case 1:
					field[2][2]='*';
					break;
				case 3:
					field[2][0]='*';
					field[2][1]='*';
					field[2][2]='*';
					break;
				case 5:
					field[2][0]='*';
					field[2][1]='*';
					field[2][2]='*';
					field[1][2]='*';
					field[0][2]='*';
					break;
				case 8:
					field[0][1]='*';
					field[0][2]='*';
					field[1][0]='*';
					field[1][1]='*';
					field[1][2]='*';
					field[2][0]='*';
					field[2][1]='*';
					field[2][2]='*';
					break;
				default:
					//cout << "ERROR! " << "CASE: " << i+1 << " M: " << M << endl;
					ofs << "Impossible" << endl;
					goto end;
				};
				field[0][0] = 'c';
				ofs << field;
			} else {
				if (col == 1)
				{
					if (M % 2 == 0)
					{
						while (M != 0)
						{
							field[row][0] = '*';
							field[row][1] = '*';
							row--;
						}

						field[0][0] = 'c';
						ofs << field;
					} else {
						ofs << "Impossible" << endl;
					}
				} else if (row == 1)
				{
					if (M % 2 == 0)
					{
						while (M != 0)
						{
							field[col][0] = '*';
							field[col][1] = '*';
							col--;
						}
						field[0][0] = 'c';
						ofs << field;
					} else {
						ofs << "Impossible" << endl;
					}
				} else if (M <= (col+1)-2)
				{
					for (int i = col; M > 0; M--,i--)
					{
							field[row][i] = '*';
					}
					field[0][0] = 'c';

					ofs << field;
				} else if (M <= (row+1)-2)
				{
					for (int i = row; M > 0; M--,i--)
					{
							field[i][col] = '*';
					}
					field[0][0] = 'c';

					ofs << field;
				} else {
					for (int i = col; M> 0 && i > 1; i--,M--)
					{
						field[row][i] = '*';
					}
					row--;
					for (int i = row; M > 0 && i > 1; i--,M--)
					{
						field[i][col] = '*';
					}
					if (M == 0)
					{
						field[0][0] = 'c';
						ofs << field;
					} else ofs << "Impossible" << endl;
					
				}
			}
end:
			;
		}
	}

	system("pause");
	return 0;
}

