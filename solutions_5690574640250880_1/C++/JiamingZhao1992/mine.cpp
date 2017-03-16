#include <iostream>
#include <fstream>

using namespace std;
char mat[50][50];
int R, C, M;
ifstream fin("C-large.in");
ofstream fout("mine.out");
void printmat()
{
	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			fout << mat[i][j];		
		}
		fout << endl;
	}
}


int main(int argc, char *argv[]) {
	
	int cases;
	fin >> cases;
	for(int cnt = 1; cnt <= cases; ++cnt)
	{
		fin >> R >> C >> M;
		fout << "Case #" << cnt << ":" << endl;
		cout << cnt << endl;
		if(R == 1 || C == 1)
		{
			int count = 0;
			for(int i = 0; i < R; ++i)
			{
				for(int j = 0; j < C; ++j)
				{
					if(i == 0 && j == 0)
						fout << "c";
					else if(count ++ < R * C - M - 1)
						fout << ".";
					else fout << "*";
				}
				fout << endl;
			}
			continue;
		}

		if(M == R * C - 1)
		{
			for(int i = 0; i < R; ++i)
			{
				for(int j = 0; j < C; ++j)
				{
					if(i == 0 && j == 0)
						fout << "c";
					else
						fout << "*";
				}
				fout << endl;
			}
			continue;
		}

		
		if(R == 2 || C == 2)
		{
			//cout << "here" << endl;
			if((R * C - M) <= 2 || (R * C - M) % 2 != 0)
				{
			fout << "Impossible" << endl;					continue;
				}
			int num = (R * C - M) / 2;
			if(R == 2)
			{
				for(int i = 0; i < C; ++i)
				{
					if(i == 0)
					{
						mat[0][0] = 'c';
						mat[1][0] = '.';
					}
					else if(i < num)
					{
						mat[0][i] = '.';
						mat[1][i] = '.';
					}
					else
					{
						mat[0][i] = '*';
						mat[1][i] = '*';
					}
				}
			}
			else if(C == 2)
			{
				for(int i = 0; i < R; ++i)
				{
					if(i == 0)
					{
						mat[0][0] = 'c';
						mat[0][1] = '.';
					}
					else if(i < num)
					{
						mat[i][0] = '.';
						mat[i][1] = '.';
					}
					else
					{
						mat[i][0] = '*';
						mat[i][1] = '*';
					}
				}
			}
			printmat();
			continue;
		}
		
		int blank = R * C - M;		
		if(M < R * C - 2 * C - 1)
		{
			int count = 0;
			for(int i = 0; i < R; ++i)
			{
				for(int j = 0; j < C; ++j)
				{
					if(i == 0 && j == 0)
						mat[i][j] = 'c';
					else if(count ++ < R * C - M - 1)
						mat[i][j] = '.';
					else mat[i][j] = '*';
				}
				//fout << endl;
			}
			if(M % C == C - 1)
			{
				cout << "here" << endl;
				mat[R - 1 - M / C][1] = '.';
				mat[R - 2 - M / C][C - 1] = '*';
			}
			printmat();
			continue;			
		}
		
		if(M < R * C - 2 * R - 1)
		{
			int count = 0;
			for(int i = 0; i < C; ++i)
			{
				for(int j = 0; j < R; ++j)
				{
					if(i == 0 && j == 0)
						mat[j][i] = 'c';
					else if(count ++ < R * C - M - 1)
						mat[j][i] = '.';
					else
						mat[j][i] = '*';
				}
			}
			if(M % R == R - 1)
			{
				cout << "here" << endl;
				mat[R - 2][C - 1 - M / R] = '.';
				mat[R - 1][C - 2 - M / R] = '*';
			}
			printmat();
			continue;			
		}
		

		if(blank >= 4 && (blank - 4) % 2 == 0)
		{
			int count = 0;
			int i, j; 
			for(i = 0; i < C; ++i)
			{
				if(i == 0)
				{
					mat[0][0] = 'c';
					mat[1][0] = '.';
					count += 2;
				}
				else
				{
					if(count < blank)
					{
					mat[0][i] = '.';
					mat[1][i] = '.';
					count += 2;
					}
					else
					{
						mat[0][i] = '*';
						mat[1][i] = '*';
					}
				}
			}
			for(i = 2; i < R; ++i)
			for(j = 0; j < C; ++j)
			{
				mat[i][j] = '*';
			}
			printmat();
			continue;
		}
		if(blank >= 6 && (blank - 6) % 3 == 0)
		{
		int count = 0;
		int i, j; 
		for(i = 0; i < C; ++i)
		{
			if(i == 0)
			{
				mat[0][0] = 'c';
				mat[1][0] = '.';
				mat[2][0] = '.';
				count += 3;
			}
			else
			{
				if(count < blank)
				{
				mat[0][i] = '.';
				mat[1][i] = '.';
				mat[2][i] = '.';
				count += 3;
				}
				else
				{
					mat[0][i] = '*';
					mat[1][i] = '*';
					mat[2][i] = '*';
				}
			}
		}
		for(i = 3; i < R; ++i)
		for(j = 0; j < C; ++j)
		{
			mat[i][j] = '*';
		}
		printmat();
		continue;			
		}
		
		if(blank >= 6)
		{
			int count = 0;
			int i, j;
			int num2, num3;
			bool flag = false;
			for(i = 1; i < blank / 3 + 1; ++i)
				for(j = 1; j < blank / 2 + 1; ++j)
				{
					if(blank == i * 3 + j * 2 && i >= 2)
					{
						if(3 + j)
						flag = true;
						num2 = j;
						num3 = i;
					}
				}
			cout << num2 << " " <<  num3 << endl;
			if(!flag)
				goto impossible;
			for(i = 0; i < C; ++i)
			{
				if(i == 0)
				{
				mat[0][0] = 'c';
				mat[1][0] = '.';
				mat[2][0] = '.';			
				}
				else if(i < num3)
				{
					mat[0][i] = '.';
					mat[1][i] = '.';
					mat[2][i] = '.';
				}
				else
				{
					mat[0][i] = '*';
					mat[1][i] = '*';
					mat[2][i] = '*';
				}
			}
			//printmat();
			for(i = 3; i < R; ++i)
			{
				if(i < num2 + 3)
				{
					mat[i][0] = '.';
					mat[i][1] = '.';
				}
				else
				{
					mat[i][0] = '*';
					mat[i][1] = '*';
				}
			}
			for(i = 3; i < R; ++i)
				for(j = 2; j < C; ++j)
					mat[i][j] = '*';
			printmat();
			continue;
		}

impossible:
		fout << "Impossible" << endl;
	}
}