#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>

#define MAXA 50000000
#define MOD 1000000007

using namespace std;

char arr[MAXA],*ptr;
long long ret;
string board[5];
string str;

inline long long get_int()
{
    ret =0;
	while ( !(*ptr >= '0' && *ptr <= '9'))
		ptr++;
	while (*ptr >= '0' && *ptr<= '9') {
		ret = ret*10 + (*ptr - '0');
		ptr++;
	}
	return ret;
}

string get_str()
{
    str = "";
	while (!(*ptr == 'O' || *ptr == 'X' || *ptr == '.' || *ptr == 'T'))
		ptr++;
    while (*ptr == 'O' || *ptr == 'X' || *ptr == '.' || *ptr == 'T')
    {
		str += (char(*ptr));
		ptr++;
	}
    return str;
}

#define OWIN 0
#define XWIN 1
#define DRAW 2
#define INCOMPLETE 3

int get_sate(){
	int countO[2][4],countX[2][4];
	memset(countO,0,sizeof(countO));
	memset(countX,0,sizeof(countX));
	int dotCount = 0;
	for(int xx =0;xx<4;xx++)
	{
		for(int yy =0;yy<4;yy++)
		{
			if(board[xx][yy] == '.')
				dotCount++;
			if(board[xx][yy] == 'O' || board[xx][yy] == 'T')
			{
				countO[0][xx]++;
				countO[1][yy]++;
				if(countO[0][xx] == 4 || countO[1][yy] == 4)
					return OWIN;
			}
			if(board[xx][yy] == 'X' || board[xx][yy] == 'T')
			{
				countX[0][xx]++;
				countX[1][yy]++;
				if(countX[0][xx] == 4 || countX[1][yy] == 4)
					return XWIN;
				
			}
			
		}
	}
	memset(countO,0,sizeof(countO));
	memset(countX,0,sizeof(countX));
	for(int xx =0;xx<4;xx++)
	{
		if(board[xx][xx] == 'O' || board[xx][xx] == 'T')
			countO[0][0]++;
		if(board[3-xx][xx] == 'O' || board[3-xx][xx] == 'T')
			countO[0][1]++;
		if(board[xx][xx] == 'X' || board[xx][xx] == 'T')
			countX[0][0]++;
		if(board[3-xx][xx] == 'X' || board[3-xx][xx] == 'T')
			countX[0][1]++;
		if(countX[0][1] == 4 || countX[0][0] == 4)
			return XWIN;
		if(countO[0][1] == 4 || countO[0][0] == 4)
			return OWIN;
	}
	if(dotCount == 0)
		return DRAW;
	else
		return INCOMPLETE;
}

int main()
{
	fread(arr,sizeof(char),MAXA,stdin);
	ptr = arr;
	register int t;
	t = get_int();
	int caseID = 1;
	while(t--)
	{
		for(int xx =0;xx<4;xx++)
			board[xx] = get_str();
		switch (get_sate()) {
			case 0:cout << "Case #"<< caseID << ": O won" << endl;break;
			case 1:cout << "Case #"<< caseID << ": X won" << endl;break;
			case 2:cout << "Case #"<< caseID << ": Draw" << endl;break;
			case 3:cout << "Case #"<< caseID << ": Game has not completed" << endl;break;
			default:
				break;
		}
		caseID++;
	}
	return 0;
}