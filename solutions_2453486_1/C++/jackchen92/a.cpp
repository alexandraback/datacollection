#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max();

char board[9][9];

bool match(char val, char player)
{
	return val == player || val == 'T';
}

bool win(char player)
{
	for(int i=0;i<4;i++)
	{
		bool w = true;
		for(int j=0;j<4;j++)
			if(!match(board[i][j], player))
			{
				w = false;
				break;
			}
		if(w)
			return true;
	}
	for(int j=0;j<4;j++)
	{
		bool w = true;
		for(int i=0;i<4;i++)
			if(!match(board[i][j], player))
			{
				w = false;
				break;
			}
		if(w)
			return true;
	}
	bool w = true;
	for(int i=0;i<4;i++)
		if(!match(board[i][i], player))
		{
			w = false;
			break;
		}
	if(w)
		return true;
	w = true;
	for(int i=0;i<4;i++)
		if(!match(board[i][3-i], player))
		{
			w = false;
			break;
		}
	if(w)
		return true;
	return false;
}

bool complete()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(board[i][j] == '.')
				return false;
	return true;
}

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		for(int i=0;i<4;i++)
			scanf("%s", board[i]);
		printf("Case #%d: ",test_case);
		if(win('X'))
			printf("X won\n");
		else if(win('O'))
			printf("O won\n");
		else if(complete())
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}
