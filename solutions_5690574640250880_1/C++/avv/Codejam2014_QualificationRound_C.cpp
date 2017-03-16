#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F_S(vec, index, start) for (int index = start; index  < vec.size(); ++index)


 vector<vector<bool>> was;
int pos[8][2] = { {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}, {1, 1}, {1, 0}, {1, -1} }; 

int play(int x, int y, vector<vector<int>>& currMines)
{
	
	if (was[x][y])
	{
		return 0;
	}
	was[x][y] = true;

	if (currMines[x][y] == 1)
	{
		return 0;
	}
	int res = 0;
	if (currMines[x][y] == 0)
	{
		res++;
	}
	bool isBombNear = false;
	for (int i = 0; i < 8; ++i)
	{
		int newX = x + pos[i][0];
		int newY = y + pos[i][1];
		if (!(newX < 0 || newY < 0 || newX >= currMines.size() || newY >= currMines[0].size() ))
		{
			if (currMines[newX][newY] == 1)
			{
				isBombNear = true;
				break;
			}
		}
		
	}
	if (!isBombNear)
	{
		for (int i = 0; i < 8; ++i)
		{
			int newX = x + pos[i][0];
			int newY = y + pos[i][1];
			if (!(newX < 0 || newY < 0 || newX >= currMines.size() || newY >= currMines[0].size() ))
			{
				res += play(newX, newY, currMines);
			}
		}
	}
	
	return res;
}

bool found;
vector<vector<int>> res;

void recMain(int fromI, int fromJ, int R, int C, vector<vector<int>>& currMines, int M, int originM)
{

	if (M == 0)
	{
		
		F(currMines, x)
		{
			F(currMines[0], y)
			{
				F(currMines, x2)
				{
					F(currMines[0], y2)
					{
						was[x2][y2] = false;
					}
				}
				int score = play(x, y, currMines);
				if (score == R * C - originM)
				{
					res = currMines;
					res[x][y] = 2;
					found = true;
				}

			}
		}
		return;
		//currMines;
	}
	M--;
	for (int i = fromI; i < R; ++i)
	{
		int j = fromJ;
		if (i != fromI)
		{
			j = 0; 
		}
		for (; j < C; ++j)
		{
			assert(currMines[i][j] == 0);
			currMines[i][j] = 1;
			if (fromJ == C - 1)
			{
				recMain(i + 1, 0, R, C, currMines, M, originM);
			}
			else
			{
				recMain(i, j + 1, R, C, currMines, M, originM);
			}
			assert(currMines[i][j] == 1);
			currMines[i][j] = 0;
			if (found)
			{
				return;
			}
		}
		
	}
}
/*
int main(int argc, char* argv[])
{

	ofstream cout ("output.txt");
	ifstream cin("input.txt");

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;
		int R, C, M;
		cin >> R >> C >> M;

	
		vector<vector<int>> currMines(R, vector<int>(C, 0));
		was = vector<vector<bool>>(R, vector<bool>(C, 0));
		found = false;
		recMain(0, 0, R, C, currMines, M, M);
	
	
		


		cout << "Case #" << t + 1 << ":" << endl;
		if (!found)
		{
			cout << "Impossible" << endl;
		}
		else
		{
			F(res, i)
			{
				F(res[0], j)
				{
					if (res[i][j] == 0)
					{
						cout << ".";
					}
					if (res[i][j] == 1)
					{
						cout << "*";
					}
					if (res[i][j] == 2)
					{
						cout << "c";
					}
				}
				cout << endl;
			}
		}
	
		

	}




	return 0;
}
*/

void output(ofstream& cout, vector<vector<int>>& res)
{
	F(res, i)
	{
		F(res[0], j)
		{
			if (res[i][j] == 0)
			{
				cout << ".";
			}
			if (res[i][j] == 1)
			{
				cout << "*";
			}
			if (res[i][j] == 2)
			{
				cout << "c";
			}
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{

	ofstream cout ("output.txt");
	ifstream cin("input.txt");

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		std::cout << t << endl;
		int R, C, M;
		cin >> R >> C >> M;
		if (M == R * C - 1 )
		{

			res = vector<vector<int>>(R, vector<int>(C, 1));
			res[0][0] =  2;
			cout << "Case #" << t + 1 << ":" << endl;
			output(cout, res);
			continue;
		}

		bool needRow = false;
		bool needCol = false;
		int needElementsRow = 0;
		int needElementsCol = 0;
		bool found = false;
		int sX, sY;
		for (int x = 0; x <= max(R - 2, 0); ++x)
		for (int y = 0; y <= max(C - 2, 0); ++y)
		{
			if (y * R > M) continue;
			
			assert(C - y >= 0);
			int D = M - y * R - (C - y) * x;
			
			//if (D >= R) continue;
			if (D >= (C - y)) continue;
			if (D >= (R - x)) continue;
			if (D < 0) continue;

			int minDRow = 2;
			if (y == 0)
			{
				minDRow = 2;
			}
			int minDCol = 2;
			if (x == 0)
			{
				minDCol = 2;
			}

			if ((R - x) - minDRow  >= D && (C - y) - minDCol >= 1 )
			{
				needElementsRow = D ;
				needRow = true;
			}
			else if ((C - y) - minDCol >= D && (R - x) - minDRow >= 1)
			{
				needElementsCol = D ;
				needCol = true;
			}
			else if ( (C - y) - minDCol >= 1 && (R - x) - minDRow >= 1)
			{
				assert(D - ((R - x) - minDRow) > 0);
				D -= (R - x) - minDRow;
				assert(D >= 0);
				if ((C - y - 1) - D >= minDCol)
				{
					needElementsRow = (R - x) - minDRow;
					needRow = true;
					needElementsCol = D ;
					needCol = true;
					
				}
			}
			

			if (needElementsCol + needElementsRow + y * R + (C - y) * x == M)
			{
				found = true;
				sX = x;
				sY = y;
				x = 999999999;
				break;
			}
		}

		
		
		cout << "Case #" << t + 1 << ":" << endl;
		if (!found)
		{
			cout << "Impossible" << endl;
			continue;
		}

		res = vector<vector<int>>(R, vector<int>(C, 0));
		F(res, i)
		F(res[0], j)
		{
			if (i < sX || j < sY)
			{
				res[i][j] = 1;
			}
		}

		for (int i = 0; i < needElementsRow; ++i)
		{
			res[sX + i][sY] = 1;	
		}
		if (needRow && needCol)
		{
			needElementsCol++;
			assert(res[sX][sY + 0] == 1 );
		}
		for (int i = 0; i < needElementsCol; ++i)
		{
			res[sX][sY + i] = 1;
		}

		bool ok = false;
		F(res, i)
		F(res[0], j)
		{	
			was=  vector<vector<bool>>(R, vector<bool>(C, false));
			int score = play(i, j, res);
			if (score + M == R * C)
			{
				res[i][j] = 2;
				i = 999999999999;
				ok = true;
				break;
			}
		}
		if (!ok)
		{
			cout << "Impossible" << endl;
			continue;
		}
		output(cout, res);
		
		
	}
	
		

	




	return 0;
}
