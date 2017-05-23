#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

char map[55][55];
ofstream ofile;
ifstream ifile;

void construct(int R, int C, int M)
{
	int row = max(R,C);
	int col = min(R,C);
	int blank = (R*C-M);
	int dir = (row==R);

	if (col==1)
	{
		for (int i=1; i<=row; i++)
		{
			if (i==1)		{map[i][1] = 'c'; continue;}
			if (i<=blank)	{map[i][1] = '.'; continue;}
			map[i][1] = '*';
		}
	}
	if (col==2)
	{
		if (M%2==0 && blank>=4)
		{
			for (int i=1; i<=row; i++)
				for (int j=1; j<=col; j++)
				{
					if (i==1 && j==1)		{map[i][j] = 'c'; continue;};
					if (i<=(blank/2))  {map[i][j] = '.'; continue;};
					map[i][j] = '*';
				}
		}
		else
		{
			ofile<<"Impossible"<<endl;
			return;
		}
	}
	if (col>2)
	{
		if (blank<4) 
		{
			ofile<<"Impossible"<<endl;
			return;
		}
		int res = (col-2)*(row-2);
		if (M<=res)
		{
			int d = floor(1.0f*M/(col-2));
			int r = M%(col-2);

			for (int i=1; i<=row; i++)
				for (int j=1; j<=col; j++)
				{
					if (i==1 && j==1)		{map[i][j] = 'c'; continue;};
					if (i>(row-d) && j>=3)  {map[i][j] = '*'; continue;};
					if (i==(row-d) && j>(col-r))  {map[i][j] = '*'; continue;};
					map[i][j] = '.';
				}
		}
		else
		{
			int pad = M-res;
			int threshold = 2*(row-3)+2*(col-3);
			if (pad<=threshold)
			{
				for (int i=1; i<=row; i++)
					for (int j=1; j<=col; j++)
					{
						if (i==1 && j==1)		{map[i][j] = 'c'; continue;};
						if (i>2 && j>2)			{map[i][j] = '*'; continue;};
						map[i][j] = '.';
					}

				int pad_piece = ceil(1.0f*pad/2);
				int i=row, j=col;
				while (pad_piece>0 && i>=4)
				{
					map[i][1] = map[i][2] = '*';
					i--;
					pad_piece--;
				}
				while (pad_piece>0 && j>=4)
				{
					map[1][j] = map[2][j] = '*';
					j--;
					pad_piece--;
				}
				if (pad%2==0) {map[3][3] = '*'; }else{map[3][3] = '.';}
			}
			else
			{
				if(blank%2 != 0)
				{
					ofile<<"Impossible"<<endl;
					return;
				}
				for (int i=1; i<=row; i++)
					for (int j=1; j<=col; j++)
					{
						if (i==1 && j==1)		{map[i][j] = 'c'; continue;};
						if (i>2 && j>2)			{map[i][j] = '*'; continue;};
						map[i][j] = '.';
					}

				int pad_piece = ceil(1.0f*pad/2);
				int i=row, j=col;
				while (pad_piece>0 && i>=3)
				{
					map[i][1] = map[i][2] = '*';
					i--;
					pad_piece--;
				}
				while (pad_piece>0 && j>=3)
				{
					map[1][j] = map[2][j] = '*';
					j--;
					pad_piece--;
				}
			}
		}
	}
	for (int i=1; i<=R; i++)
	{
		for (int j=1; j<=C; j++)
		{
			if (dir==1) 
			{
				ofile<<map[i][j];
			}else
			{
				ofile<<map[j][i];
			}
		}
		ofile<<endl;
	}
}
int main()
{
	ofile.open("C-small-out.txt");		
	//ifile.open("B-small-attempt0.in");			
	ifile.open("C-small-attempt0.in");	

	long T;
	double C = 0, R = 0, M = 0;

	ifile>>T;
	for (int iT=1; iT<=T;iT++)
	{
		ifile>>R>>C>>M;
		ofile<<"Case #"<<iT<<":"<<endl;

		if (M==R*C-1)
		{
			for (int i=1; i<=R; i++)
			{
				for (int j=1; j<=C; j++)
					if (i==1 && j==1) {ofile<<'c';}
					else
						ofile<<'*';
				ofile<<endl;
			}
		}
		else
			construct(R,C,M);



	}
	ifile.close();
	ofile.close();
	system("pause");
}