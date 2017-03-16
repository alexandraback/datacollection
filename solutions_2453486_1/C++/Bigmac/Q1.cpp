#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
	char *filename_in = "input.txt";
	if(argc > 1)
	{
		filename_in = argv[1];
	}
	string filename_out(filename_in);
	filename_out.append("_output.txt");
	FILE *fi = fopen(filename_in, "rt");
	if(fi == NULL)
	{
		return -1;
	}
	FILE *fo = fopen(filename_out.c_str(), "wt");
	int in_t;
	fscanf(fi, "%d", &in_t);
	for(int it_t = 1; it_t <= in_t; it_t++)
	{
		char chessboard[4][100];
		for(int y=0;y < 4; y++)
		{
			chessboard[y][0] = 0;
			fscanf(fi, "%s", &chessboard[y]);
			if(chessboard[y][0] == 0x0d || chessboard[y][0] == 0x0a || chessboard[y][0] == 0x00)
			{
				continue;
			}
		}
		string status;
		bool unsure = false;
		for(int y=0;y < 4; y++)
		{
			int count_o = 0;
			int count_x = 0;
			for(int x=0;x < 4; x++)
			{
				if(chessboard[y][x] == 'O')
				{
					count_o++;
				}
				if(chessboard[y][x] == 'X')
				{
					count_x++;
				}
				if(chessboard[y][x] == 'T')
				{
					count_o++;
					count_x++;
				}
			}
			if(count_o == 4)
			{
				status = "O won";
				break;
			}
			if(count_x == 4)
			{
				status = "X won";
				break;
			}
			if(count_o == 0 || count_x == 0)
			{
				unsure = true;
			}
		}
		if(status.empty())
		{
			for(int x=0;x < 4; x++)
			{
				int count_o = 0;
				int count_x = 0;
				for(int y=0;y < 4; y++)
				{
					if(chessboard[y][x] == 'O')
					{
						count_o++;
					}
					if(chessboard[y][x] == 'X')
					{
						count_x++;
					}
					if(chessboard[y][x] == 'T')
					{
						count_o++;
						count_x++;
					}
				}
				if(count_o == 4)
				{
					status = "O won";
					break;
				}
				if(count_x == 4)
				{
					status = "X won";
					break;
				}
				if(count_o == 0 || count_x == 0)
				{
					unsure = true;
				}
			}
		}
		if(status.empty())
		{
			int count_o = 0;
			int count_x = 0;
			for(int y=0;y < 4; y++)
			{
				if(chessboard[y][y] == 'O')
				{
					count_o++;
				}
				if(chessboard[y][y] == 'X')
				{
					count_x++;
				}
				if(chessboard[y][y] == 'T')
				{
					count_o++;
					count_x++;
				}
			}
			if(count_o == 4)
			{
				status = "O won";
			}
			if(count_x == 4)
			{
				status = "X won";
			}
			if(count_o == 0 || count_x == 0)
			{
				unsure = true;
			}
		}
		if(status.empty())
		{
			int count_o = 0;
			int count_x = 0;
			for(int y=0;y < 4; y++)
			{
				if(chessboard[y][3-y] == 'O')
				{
					count_o++;
				}
				if(chessboard[y][3-y] == 'X')
				{
					count_x++;
				}
				if(chessboard[y][3-y] == 'T')
				{
					count_o++;
					count_x++;
				}
			}
			if(count_o == 4)
			{
				status = "O won";
			}
			if(count_x == 4)
			{
				status = "X won";
			}
			if(count_o == 0 || count_x == 0)
			{
				unsure = true;
			}
		}
		if(status.empty())
		{
			if(unsure)
			{
				status = "Game has not completed";
			}
		}
		if(status.empty())
		{
			status = "Draw";
		}
		fprintf(fo, "Case #%d: %s", it_t, status.c_str());
		fprintf(fo, "\n");
	}
	fclose(fi);
	fclose(fo);
}