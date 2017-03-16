#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
string fName = argv[1];

fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;

for(int h=0; h<tests; h++)
{
	vector<string> board(4);
	for(int i=0; i<4; i++)
		In >> board[i];

	string s = "Game has not completed";
	int flag = false;
	for(int i=0; i<4; i++)
	{
		int x = 0, o = 0;
		for(int j=0; j<4; j++)
			if(board[i][j]=='X')
				x++;
			else if(board[i][j]=='O')
				o++;
			else if(board[i][j]=='T')
			{
				x++; o++;
			}
			else
				flag = true;
		if(x==4)
			s = "X won";
		else if(o==4)
			s = "O won";
	}
	for(int j=0; j<4; j++)
	{
		int x = 0, o = 0;
		for(int i=0; i<4; i++)
			if(board[i][j]=='X')
				x++;
			else if(board[i][j]=='O')
				o++;
			else if(board[i][j]=='T')
			{
				x++; o++;
			}
			else
				flag = true;
		if(x==4)
			s = "X won";
		else if(o==4)
			s = "O won";
	}
	int x = 0, o = 0;
	for(int i=0; i<4; i++)
		if(board[i][i]=='X')
			x++;
		else if(board[i][i]=='O')
			o++;
		else if(board[i][i]=='T')
		{
			x++; o++;
		}
		else
			flag = true;
	if(x==4)
		s = "X won";
	else if(o==4)
		s = "O won";

	x = 0, o = 0;
	for(int i=0; i<4; i++)
		if(board[i][3-i]=='X')
			x++;
		else if(board[i][3-i]=='O')
			o++;
		else if(board[i][3-i]=='T')
		{
			x++; o++;
		}
		else
			flag = true;
	if(x==4)
		s = "X won";
	else if(o==4)
		s = "O won";	
	if(s == "Game has not completed" && !flag)
		s = "Draw";

	Out << "Case #" << h+1 << ": " << s << endl;

}

In.close();

Out.close();

return 0;

}
 
