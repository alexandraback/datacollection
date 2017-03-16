#include <iostream>
using namespace std;

int T, R, C, M, emp;
bool flipped;
char grid[50][50];

void print()
{
	if (!flipped)
		for (int i=0; i<R; i++)
		{
			for (int j=0; j<C; j++)
				cout << grid[i][j];
			cout << endl;
		}
	else
		for (int i=0; i<C; i++)
		{
			for (int j=0; j<R; j++)
				cout << grid[j][i];
			cout << endl;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		cout << "Case #" << t << ":" << endl;
		cin >> R >> C >> M;
		emp = R*C - M;
		
		flipped = false;
		if (R < C)
		{
			swap(R, C);
			flipped = true;
		}
		for (int i=0; i<R; i++)
			for (int j=0; j<C; j++)
				grid[i][j] = '*';
		//R >= C >= 1
		
		if (M == 0)
		{
			for (int i=0; i<R; i++)
				for (int j=0; j<C; j++)
					grid[i][j] = '.';
			grid[0][0] = 'c';
			print();
			continue;
		}
		
		if (emp == 1)
		{
			grid[0][0] = 'c';
			print();
			continue;
		}
		//0 < M < R*C - 1, R > 1
		
		if (C == 1) //R > C = 1
		{
			grid[0][0] = 'c';
			for (int i=1; i<(R-M); i++)
				grid[i][0] = '.';
			print();
			continue;
		}
		//R >= C >= 2
		
		if (emp < 4)
		{
			cout << "Impossible" << endl;
			continue;
		}
		//emp >= 4, R > 2
		
		if (C == 2) //R > C = 2
		{
			if (emp % 2 == 1)
				cout << "Impossible" << endl;
			else
			{
				for (int i=0; i<emp/2; i++)
				{
					grid[i][0] = '.'; grid[i][1] = '.';
				}
				grid[0][0] = 'c';
				print();
			}
			continue;
		}
		//R >= C > 2
		
		if (emp == 4 || emp == 6)
		{
			for (int i=0; i<emp/2; i++)
			{
				grid[i][0] = '.'; grid[i][1] = '.';
			}
			grid[0][0] = 'c';
			print();
			continue;
		}
		
		if (emp < 8)
		{
			cout << "Impossible" << endl;
			continue;
		}
		
		int c, r;
		bool flag = false; 
		for (c=3; c<=C; c++)
		{
			for (r=c; r<=R; r++)
				if (2*(c+r) - 4 <= emp && emp <= c*r)
					{
						flag = true; break;
					}
			if (flag)
					break;
		}
		
		for (int i=0; i<c; i++)
		{
			grid[0][i] = '.'; grid[1][i] = '.';
		}
		for(int i=2; i<r; i++)
		{
			grid[i][0] = '.'; grid[i][1] = '.';
		}
		int count = 2*(c+r) - 4;
		for (int i=2; i<r; i++)
		{
			if (count == emp) break;
			for (int j=2; j<c; j++)
			{
				if (count == emp) break;
				grid[i][j] = '.';
				count++;
			}
		}
		grid[0][0] = 'c';
		print();
	}
	
	return 0;
}
