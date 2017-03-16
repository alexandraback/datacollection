#include <iostream>

using namespace std;

char board[4][4];

int caseNumber;

bool check(char c)
{
	int result=0;
	for(int i=0;i<4;++i)
	{
		result=0;
		for(int j=0;j<4;++j)
		{
			if(board[i][j]!=c && board[i][j]!='T')
			{
				result|=1;
			}
			if(board[j][i]!=c && board[j][i]!='T')
			{
				result|=2;
			}
			if(board[j][j]!=c && board[j][j]!='T')
			{
				result|=4;
			}
			if(board[3-j][j]!=c && board[3-j][j]!='T')
			{
				result|=8;
			}
		}
		if(result!=15)
			return true;
	}
	return false;
}
void solve()
{
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			cin>>board[i][j];
		}
	}

	if(check('X'))
	{
		cout<<"X won"<<endl;
		return;
	}
	if(check('O'))
	{
		cout<<"O won"<<endl;
		return;
	}
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			if(board[i][j]=='.')
			{
				cout<<"Game has not completed"<<endl;
				return;
			}
		}
	}

	cout<<"Draw"<<endl;
}
int main()
{
	cin>>caseNumber;
	for(int caseId=1;caseId<=caseNumber;++caseId)
	{
		cout<<"Case #"<<caseId<<": ";
		solve();
	}
	return 0;
}