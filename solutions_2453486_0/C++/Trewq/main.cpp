#include<iostream>
#include<algorithm>
#include<memory.h>
#include<stack>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int nc;
	char board[4][4];
	bool notfin;
	char inits;
	char winner;
	bool won;
	cin>>nc;
	for(int tc=1;tc<=nc;tc++)
	{
		notfin=0;
		winner='d';
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				cin>>board[i][j];
				if(board[i][j]=='.')
					notfin=1;
			}
		for(int i=0;i<4;i++)
		{
			if(board[i][0]!='.')
				inits=board[i][0];
			else
				continue;
			won=1;
			for(int j=1;j<4;j++)
			{
				if(inits!=board[i][j])
				{
					if(board[i][j]!='T' && inits!='T')
					{
						won=0;
						break;
					}
					if(board[i][j]=='.')
					{
						won=0;
						break;
					}
					if(inits=='T')
						inits=board[i][j];
				}
			}
			if(won)
			{
				winner=inits;
				break;
			}
		}
		if(!won)
		{
			for(int j=0;j<4;j++)
			{
				if(board[0][j]!='.')
					inits=board[0][j];
				else
					continue;
				won=1;
				for(int i=1;i<4;i++)
				{
					if(inits!=board[i][j])
					{
						if(board[i][j]!='T' && inits!='T')
						{
							won=0;
							break;
						}
						if(board[i][j]=='.')
						{
							won=0;
							break;
						}
						if(inits=='T')
							inits=board[i][j];
					}
				}
				if(won)
				{
					winner=inits;
					break;
				}
			}
		}
		if(!won)
		{
			if(board[0][0]!='.')
			{
				inits=board[0][0];
				won=1;
				for(int i=1;i<4;i++)
				{
					if(inits!=board[i][i])
					{
						if(board[i][i]!='T' && inits!='T')
						{
							won=0;
							break;
						}
						if(board[i][i]=='.')
						{
							won=0;
							break;
						}
						if(inits=='T')
							inits=board[i][i];
					}
				}
				if(won)
				{
					winner=inits;
				}
			}
		}
		if(!won)
		{
			if(board[0][3]!='.')
			{
				inits=board[0][3];
				won=1;
				for(int i=1;i<4;i++)
				{
					if(inits!=board[i][3-i])
					{
						if(board[i][3-i]!='T' && inits!='T')
						{
							won=0;
							break;
						}
						if(board[i][3-i]=='.')
						{
							won=0;
							break;
						}
						if(inits=='T')
							inits=board[i][3-i];
					}
				}
				if(won)
				{
					winner=inits;
				}
			}
		}
		cout<<"Case #"<<tc<<": ";
		if(won)
		{
			if(winner=='X')
				cout<<"X won"<<endl;
			if(winner=='O')
				cout<<"O won"<<endl;
		}
		else
		{
			if(notfin)
				cout<<"Game has not completed"<<endl;
			else
				cout<<"Draw"<<endl;
		}
	}
    return 0;
}                                 