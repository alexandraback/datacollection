#include"iostream"
#include"fstream"
#include "iomanip"
#define cin fin
#define cout fout
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");

int Get(int r, int c, int m,int grid[50][50])
{
	int r1, c1,blank,temp,max;
	for (int i = 0; i<r; i++)
		for (int j = 0; j < c; j++)
			grid[i][j] = -1;
	if (r*c == m + 1)//只剩一个空格
	{
		grid[0][0] = 1;
		return 1;
	}
	
	if (m == 0)//没有一个地雷
	{
		
		for (int i = 0; i<r; i++)
			for (int j = 0; j < c; j++)
				grid[i][j] = 0;//初始化为无雷区
		grid[0][0] = 1;
		return 1;
	}
	if (r == 1)
	{
		grid[0][0] = 1;
		for (int i = 1; i <= c - m - 1; i++)
			grid[0][i] = 0;
		return 1;
	}
	if (c == 1)
	{
		grid[0][0] = 1;
		for (int i = 1; i <= r - m - 1; i++)
			grid[i][0] = 0;
		return 1;
	}
	blank = r*c - m;
	int flag;
	flag = 0;
	for (r1 = 2; r1 <= r; r1++)
	{
		for (c1 = blank/r1; c1 <= c; c1++)
		{
			if (c1 == 1)
				continue;
			if (r1*c1 == blank)
			{
				
				for (int i = 0; i<r1; i++)
					for (int j = 0; j < c1; j++)
						grid[i][j] = 0;//初始化为无雷区
				grid[0][0] = 1;
				return 1;
			}
			temp = m - (r*c - r1*c1);
			if ((r1 == 2 || c1 == 2)&& temp%2!=0)
			{
				continue;
			}
			if (r1*c1 < blank)
				continue;
			
			if (r1*c1>blank)
			{
				
				max = r1 + c1 - 4 - 1;
				if (temp <= max)
				{
					for (int i = 0; i<r1; i++)
						for (int j = 0; j < c1; j++)
							grid[i][j] = 0;//初始化为无雷区
					grid[0][0] = 1;
					for (int i = c1 - 1; i >= 2 && temp>0; i--)
					{
						grid[r1 - 1][i] = -1; temp--;
					}
					for (int i = r1-2; i >= 2 && temp>0; i--)
					{
						grid[i][c1-1] = -1; temp--;
					}
					return 1;
				}
				break;
			}
		}
	}
	return -1;
}

int main()
{
	int grid[50][50];
	int num,r,c,m,type;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> r >> c >> m;
		cout << "Case #" << i + 1 << ":" << endl;
		//cout << r << " " << c << " " << m<<endl;
		type=Get(r, c, m,grid);
		if (type == 1)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (grid[i][j] == 1)
						cout << "c";
					if (grid[i][j] == 0)
						cout << ".";
					if (grid[i][j] == -1)
						cout << "*";
				}
				cout << endl;
			}
				
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}