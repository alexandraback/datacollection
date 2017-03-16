#include <iostream>

using namespace std;

struct Matrix
{
	int R, C;
	char mat[55][55];
	Matrix() { }
	Matrix(int r, int c)
	{
		R = r, C = c;
		for(int r = 1; r <= R; r++)
			for(int c = 1; c <= C; c++)
				mat[r][c] = '*';
	}
	void transpose()
	{
		char mat2[55][55];
		for(int r = 1; r <= R; r++)
			for(int c = 1; c <= C; c++)
				mat2[c][r] = mat[r][c];
		swap(R, C);
		for(int r = 1; r <= R; r++)
			for(int c = 1; c <= C; c++)
				mat[r][c] = mat2[r][c];
	}
	void disp()
	{
		for(int r = 1; r <= R; r++)
		{
			for(int c = 1; c <= C; c++)
				cout << mat[r][c];
			cout << endl;
		}
	}
};

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ":\n";
		int R, C, M;
		bool swapped = false;
		cin >> R >> C >> M;
		int F = R * C - M;
		if(R > C)
		{
			swap(R, C);
			swapped = true;
		}
		Matrix matrix(R, C);
		if(F == 1)
		{
			matrix.mat[1][1] = 'c';
			/*for(int r = 1; r <= R; r++)
				for(int c = 1; c <= C; c++)
					matrix.mat[r][c] = (r == 1 && c == 1 ? 'c' : '*');*/
		}
		else if(R == 1)
		{
			matrix.mat[1][1] = 'c';
			for(int c = 2; c <= F; c++) matrix.mat[1][c] = '.';
			//for(int c = F + 1; c <= C; c++) matrix.mat[1][c] = '*';
		}
		else if(R == 2)
		{
			if(F % 2 == 1 || F == 2)
			{
				cout << "Impossible\n";
				continue;
			}
			for(int r = 1; r <= R; r++)
				for(int c = 1; c <= C; c++)
				{
					if(r == 1 && c == 1) matrix.mat[r][c] = 'c';
					else if(c <= F) matrix.mat[r][c] = '.';
					//else matrix.mat[r][c] = '*';
				}
		}
		else
		{
			if(F == 2 || F == 3 || F == 5 || F == 7)
			{
				cout << "Impossible\n";
				continue;
			}
			matrix.mat[1][1] = 'c';
			matrix.mat[1][2] = matrix.mat[2][1] = matrix.mat[2][2] = '.';
			if(F > 4)
			{
				matrix.mat[3][1] = matrix.mat[3][2] = '.';
				if(F > 6)
				{
					matrix.mat[1][3] = matrix.mat[2][3] = '.';
					int nextrow = 4, nextcol = 4, inside_r = 3, inside_c = 3, cnt = 8;
					while(cnt < F)
					{
						if(cnt + 1 == F || (nextrow > R && nextcol > C))
						{
							matrix.mat[inside_r][inside_c] = '.';
							inside_c++;
							if(inside_c > C)
							{
								inside_r++;
								inside_c = 3;
							}
							cnt++;
						}
						else if(nextrow <= R)
						{
							matrix.mat[nextrow][1] = matrix.mat[nextrow][2] = '.';
							nextrow++;
							cnt += 2;
						}
						else if(nextcol <= C)
						{
							matrix.mat[1][nextcol] = matrix.mat[2][nextcol] = '.';
							nextcol++;
							cnt += 2;
						}
					}
				}
			}
		}
		if(swapped) matrix.transpose();
		matrix.disp();
	}
}
