#include <iostream>
#include <math.h>
#include <map>

using namespace std;

char matrix[50][50];
int row;
int col;
int neiCount[50][50];
map<int, int> possiblePositions;

int neighborCount(int r, int c)
{
        int count = 0;
        for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                        if (i == 0 && j == 0) continue;
                        else if ((r + i >= 0) && (r + i < row) && (c + j >= 0) && (c + j < col) && matrix[r + i][c + j] == '.')
                                count++;
        return count;
}

void updateNeigborCount(int r, int c)
{
        for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                        if ((r + i >= 0) && (r + i < row) && (c + j >= 0) && (c + j < col))
                                neiCount[r + i][c + j] = neighborCount(r + i, c + j);
}

void addPossiblePosition(int r, int c)
{
        for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                {
                        if (i == 0 && j == 0) continue;
                        int r2 = r + i, c2 = c + j;
                        if (r2 >= 0 && r2 < row && c2 >= 0 && c2 < col)
                        {
                                if (matrix[r2][c2] == '.') continue;
				if (possiblePositions.count(r2 * 1000 + c2) > 0) continue;
                                if ((((r2 == 0) || (c2 == 0)) && neiCount[r2][c2] == 2) ||
                                        (r2 > 0 && c2 > 0 && neiCount[r2][c2] > 2 && matrix[r2 - 1][c2] == '.' && matrix[r2][c2 - 1] == '.'))
                                        possiblePositions[r2 * 1000 + c2] = 0;
                        }
                }
}

int draw(int emptyNum, int current, int forceRow, int forceCol)
{
        if (current > emptyNum) return 1;

	if (forceRow >= 0 && forceCol >= 0 && forceRow < row && 
		forceCol < col && matrix[forceRow][forceCol] != '.' && 
		(possiblePositions.count(forceRow * 1000 + forceCol) == 0 || possiblePositions[forceRow * 1000 + forceCol] == 0))
	{
			int r = forceRow, c = forceCol;
			matrix[r][c] = '.';
                        if (possiblePositions.count(r * 1000 + c) > 0) possiblePositions[r * 1000 + c] = 1;
                        updateNeigborCount(r, c);

                        addPossiblePosition(r, c);

                        forceRow = (neiCount[r][c] >=3 && r != 0 && c != 0 && matrix[r - 1][c] == '.' && matrix[r][c - 1] == '.') ? -1 : (r == 0) ? r + 1 : r;
                        forceCol = (neiCount[r][c] >=3 && r != 0 && c != 0 && matrix[r - 1][c] == '.' && matrix[r][c - 1] == '.') ? -1 : (c == 0) ? c + 1 : c;
                        if (draw(emptyNum, current + 1, forceRow, forceCol))
                        {
                                return 1;
                        }

                        matrix[r][c] = '*';
                        updateNeigborCount(r, c);	
	}
	else
	{
		for (map<int, int>::iterator it = possiblePositions.begin(); it != possiblePositions.end(); ++it)
		{
			if (it->second) continue;

        	        int r = it->first / 1000, c = it->first % 1000;
	                if (current == emptyNum && (neiCount[r][c] < 3 || r == 0 || c == 0 || matrix[r - 1][c] != '.' || matrix[r][c - 1] != '.')) continue;
        	        matrix[r][c] = '.';
			possiblePositions[it->first] = 1;
                	updateNeigborCount(r, c);

                	addPossiblePosition(r, c);

			forceRow = (neiCount[r][c] >=3 && r != 0 && c != 0 && matrix[r - 1][c] == '.' && matrix[r][c - 1] == '.') ? -1 : (r == 0) ? r + 1 : r;
			forceCol = (neiCount[r][c] >=3 && r != 0 && c != 0 && matrix[r - 1][c] == '.' && matrix[r][c - 1] == '.') ? -1 : (c == 0) ? c + 1 : c;
	                if (draw(emptyNum, current + 1, forceRow, forceCol)) 
			{
				return 1;
			}
                

                	matrix[r][c] = '*';
                	updateNeigborCount(r, c);
		}
        }

        return 0;
}

int main()
{
	unsigned long int repeat;
	cin >> repeat;
	for (int i = 0; i < repeat; i++)
	{
	        int mine, empty;
                cin >> row >> col >> mine;
                cout << "Case #" << (i + 1) << ":" << endl;

                empty = row * col - mine;

                if (empty != 1 && empty < 4 && mine > 0 && row > 1 && col > 1)
                {
                        cout << "Impossible" << endl;
                        continue;
                }

                if ((row == 2 || col == 2) && empty != 1 && (empty % 2 == 1))
                {
                        cout << "Impossible" << endl;
                        continue;
                }

                if (mine == 0)
                {
                        for (int j = 0; j < row; j++)
                                for (int k = 0; k < col; k++)
                                        matrix[j][k] = '.';
                }
		else if (empty == 1)
		{
			for (int j = 0; j < row; j++)
                                for (int k = 0; k < col; k++)
                                        matrix[j][k] = '*';
			matrix[0][0] = '.';
		} 
                else if (row == 1)
                {
                        for (int j = 0; j < col; j++)
                                matrix[0][j] = (j < empty) ? '.' : '*';
                } 
                else if (col == 1)
                {
                        for (int j = 0; j < row; j++)
                                matrix[j][0] = (j < empty) ? '.' : '*';
                } 
                else
                {
                        for (int j = 0; j < row; j++)
                                for (int k = 0; k < col; k++)
                                        matrix[j][k] = (j <= 1 && k <= 1) ? '.' : '*';
                        for (int j = 0; j < row; j++)
                                for (int k = 0; k < col; k++)
                                        neiCount[j][k] = neighborCount(j, k);

			possiblePositions.clear();
                        if (col > 2) 
				possiblePositions[2] = 0;
                        if (row > 2)
				possiblePositions[2000] = 0;
                        if(!draw(empty, 5, -1, -1))
			{
                                cout << "Impossible" << endl;
                                continue;
                        }
                }

                for (int j = 0; j < row; j++)
                {
                        for (int k = 0; k < col; k++)
                        {
                                if (j == 0 && k == 0) cout << 'c';
                                else cout << matrix[j][k];
                        }

                        cout << endl;
                }
	}

	return 0;
}
