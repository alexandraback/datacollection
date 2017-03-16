#include<iostream>
using namespace std;

char board[4][4];
int check_winner()
{
		int count1=0;
		int count2=0;
		for(int j=0;j<4;j++)
		{

			for(int k=0;k<4;k++)
			{
				if(board[j][k] == 'X' || board[j][k] == 'T')
					count1++;
				if(board[j][k] == 'O' || board[j][k] == 'T')
					count2++;

			}
			if(count1 == 4)
				return 1;
			if(count2 == 4)
				return 2;
			count1 = 0;
			count2 = 0;
		}
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(board[k][j] == 'X' || board[k][j] == 'T')
					count1++;
				if(board[k][j] == 'O' || board[k][j] == 'T')
					count2++;
			}
			if(count1 == 4)
				return 1;
			if(count2 == 4)
				return 2;

			count1 = 0;
			count2 = 0;
		}
		for(int j=0;j<4;j++)
		{
			if(board[j][j] == 'X' || board[j][j] == 'T')
				count1++;
			if(board[j][j] == 'O' || board[j][j] == 'T')
				count2++;
		}
			if(count1 == 4)
				return 1;
			if(count2 == 4)
				return 2;

			count1 = 0;
			count2 = 0;
		for(int j=0;j<4;j++)
		{
			if(board[j][3-j] == 'X' || board[j][3-j] == 'T')
				count1++;
			if(board[j][3-j] == 'O' || board[j][3-j] == 'T')
				count2++;
			if(count1 == 4)
				return 1;
			if(count2 == 4)
				return 2;
		}		
			
			count1 = 0;
			count2 = 0;
	
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(board[j][k] =='.')
					return 0;
			}
		}
		return -1;
}

int main() {
	int winner = -1;
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<4;j++)
		{
			string row;
			cin >> row;
			for(int k=0;k<4;k++)
			{
				board[j][k]=row[k];
			}
		}
		int w = check_winner();
	switch(w)
	{
		case -1:
			 cout << "Case #"<< (i+1) << ": Draw"<< endl;
			 break;
		case 0:
			 cout << "Case #"<<(i+1)<<": Game has not completed"<<endl;
			 break;
		case 1:
			 cout << "Case #"<<(i+1)<<": X won"<< endl;
			 break;
		case 2:
			 cout << "Case #"<<(i+1)<<": O won"<< endl;
			 break;
	}	
		//cout << check_winner() << endl;
		
	}
	return 0;
}
