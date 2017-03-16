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
