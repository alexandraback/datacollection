#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <xfunctional>

using namespace std;

ifstream fin;
ofstream fout;
int T;
int mode = 0;

//data
int X,Y;
string path[201][201];
int flag[201][201];

void readdata()
{
	fin >> X >> Y;
}

string solve()
{
	stringstream str;
	str << path[X+100][Y+100];
	return str.str();
}
//fixed
void process(int id)
{
	readdata();
	string result = solve();
	fout << "Case #" << id << ": " << result << endl;
}
void preprocess()
{
	int i,j;
	for (i = 0; i < 201; i++)
		for (j = 0; j < 201; j++)
		{
			path[i][j] = "";
			flag[i][j] = -1;
		}
	flag[100][100] = 0;
	for (int move = 1; move <= 500; move++)
	{
		for (i = 0; i < 201; i++)
			for (j = 0; j < 201; j++)
				if(flag[i][j] == move-1)
				{
					if (i+move < 201 && flag[i+move][j] == -1 )
					{
						flag[i+move][j] = move;
						path[i+move][j] = path[i][j] + "E";
					}
					if (i-move >= 0 && flag[i-move][j] == -1 )
					{
						flag[i-move][j] = move;
						path[i-move][j] = path[i][j] + "W";
					}
					if (j+move < 201 && flag[i][j+move] == -1 )
					{
						flag[i][j+move] = move;
						path[i][j+move] = path[i][j] + "N";
					}
					if (j-move >= 0 && flag[i][j-move] == -1 )
					{
						flag[i][j-move] = move;
						path[i][j-move] = path[i][j] + "S";
					}
				}
	}
}
void main()
{
	if(mode == 0)
	{
		fin.open("B-small.in");
		fout.open("B-small.txt");
	}
	else
	{
		fin.open("B-large.in");
		fout.open("B-large.txt");
	}
	preprocess();
	fin >> T;
	for (int i = 1; i <= T; i++)
		process(i);
	fin.close();
	fout.close();
}