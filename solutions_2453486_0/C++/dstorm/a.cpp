#include<iostream>
#define N 4
using namespace std;
char board[N][N+1];
char get_status();
int main()
{	int i=1,t,j,k;
	char stat;
	cin>>t;
	while(i<=t)
	{	for(j=0;j<N;j++)
			cin>>board[j];
		cout<<"Case #"<<i<<": ";
		char stat=get_status();
		if(stat=='X')
			cout<<"X won"<<endl;
		else if(stat=='O')
			cout<<"O won"<<endl;
		else if(stat=='D')
			cout<<"Draw"<<endl;
		else if(stat=='N')
			cout<<"Game has not completed"<<endl;
		i++;
	}
	return 0;
}
char get_status()
{	int i,j,dia[2][2]={0,0,0,0},dot=0,x=0,o=0,x_wins=0,o_wins=0;
	for(i=0;i<N;i++)
	{	int row[2]={0,0},col[2]={0,0};
		for(j=0;j<N;j++)
		{	// Who made Last Move
			if(board[i][j]=='X')
				x++;
			else if(board[i][j]=='O')
				o++;
			// Row Wise
			if(board[i][j]=='X')
				row[0]++;
			else if(board[i][j]=='O')
				row[1]++;
			else if(board[i][j]=='T')
			{	row[0]++;
				row[1]++;
			}
			// Col Wise
			if(board[j][i]=='X')
				col[0]++;
			else if(board[j][i]=='O')
				col[1]++;
			else if(board[j][i]=='T')
			{	col[0]++;
				col[1]++;
			}
			// Main Diagonal
			if(i==j && board[i][j]=='X')
				dia[0][0]++;
			else if(i==j && board[i][j]=='O')
				dia[0][1]++;
			else if(i==j && board[i][j]=='T')
			{	dia[0][0]++;
				dia[0][1]++;
			}
			// Other Diagonal
			if((i+j)==3 && board[i][j]=='X')
				dia[1][0]++;
			else if((i+j)==3 && board[i][j]=='O')
				dia[1][1]++;	
			else if((i+j)==3 && board[i][j]=='T')
			{	dia[1][0]++;
				dia[1][1]++;
			}
			// Count Dots
			if(board[i][j]=='.')
				dot++;
		}
		if(row[0]==4|| col[0]==4)
		{	x_wins=1;
		}
		if(row[1]==4 || col[1]==4)
		{	o_wins=1;
		}
	}
	if(dia[0][0]==4 || dia[1][0]==4)
	{	x_wins=1;
	}
	if(dia[0][1]==4 || dia[1][1]==4)
	{	o_wins=1;
	}
	if(x_wins && o_wins)
	{	if(x==o)
			return 'O';
		else
			return 'X';
	}
	else if(x_wins)
		return 'X';
	else if(o_wins)
		return 'O';
	if(dot==0)
		return 'D';
	return 'N';
}