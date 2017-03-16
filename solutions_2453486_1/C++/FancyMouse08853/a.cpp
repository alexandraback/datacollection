#include<iostream>
using namespace std;

char board[4][5];
bool Judge(char ch)
{
	int counter;
	for(int i=0;i<4;i++)
	{
		counter = 0;
		for(int j=0;j<4;j++)
			if(board[i][j] == ch || board[i][j] == 'T')
				counter++;
		if(counter == 4)
			return true;
	}
	for(int i=0;i<4;i++)
	{
		counter = 0;
		for(int j=0;j<4;j++)
			if(board[j][i] == ch || board[j][i] == 'T')
				counter++;
		if(counter == 4)
			return true;
	}
	counter = 0;
	for(int i=0;i<4;i++)
		if(board[i][i] == ch || board[i][i] == 'T')
			counter++;
	if(counter == 4)
		return true;
	counter = 0;
	for(int i=0;i<4;i++)
		if(board[i][3-i] == ch || board[i][3-i] == 'T')
			counter++;
	if(counter == 4)
		return true;
	return false;
}
int main()
{
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		for(int i=0;i<4;i++)
			cin>>board[i];
		bool notcompleted = false;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(board[i][j] == '.')
					notcompleted = true;
		bool x = Judge('X');
		bool o = Judge('O');
		cout<<"Case #"<<_<<": ";
		if(x)
			cout<<"X won";
		else if(o)
			cout<<"O won";
		else if(notcompleted)
			cout<<"Game has not completed";
		else
			cout<<"Draw";
		cout<<endl;
	}
	return 0;
}
