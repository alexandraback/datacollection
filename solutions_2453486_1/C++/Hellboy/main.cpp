#include<iostream>

namespace codejam
{
	bool checkrow(char**arr,int row, char& start)
	{
		if(arr[row][0] == '.' || arr[row][1] == '.')
			return false;
		start = arr[row][0];
		if(start == 'T')
			start = arr[row][1];
		for(int k = 1; k < 4; k++)
		{
			if(arr[row][k] != 'T' && arr[row][k] != start)
			{
				return false;
			}
		}
		return true;
	}
	bool checkcol(char**arr,int col, char& start)
	{
		if(arr[0][col] == '.' || arr[1][col] == '.')
			return false;
		start = arr[0][col];
		if(start == 'T')
			start = arr[1][col];
		for(int k = 1; k < 4; k++)
		{
			if(arr[k][col] != 'T' && arr[k][col] != start)
			{
				return false;
			}
		}
		return true;
	}
	bool checkdiagonal(char**arr, char& start)
	{
		if(arr[0][0] == '.' || arr[1][1] == '.')
			return false;
		start = arr[0][0];
		if(start == 'T')
			start = arr[1][1];
		for(int k = 1; k < 4; k++)
		{
			if(arr[k][k] != 'T' && arr[k][k] != start)
			{
				return false;
			}
		}
		return true;
	}
	bool checkinversediagonal(char**arr, char& start)
	{
		if(arr[0][3] == '.' || arr[1][2] == '.')
			return false;
		start = arr[0][3];
		if(start == 'T')
			start = arr[1][2];
		for(int k = 1; k < 4; k++)
		{
			if(arr[k][3-k] != 'T' && arr[k][3-k] != start)
			{
				return false;
			}
		}
		return true;
	}
	void tictactoe()
	{
		int cases;
		std::cin>>cases;
		char** arr = new char*[4];
		for(int j = 0 ; j < 4; j++)
			arr[j] = new char[4];
		for(int i = 1; i <= cases; i++)
		{
			bool gamenotcompleted = false;
			for(int j = 0; j < 4; j++)
			{
				for(int k = 0; k < 4; k++)
				{
					std::cin>>arr[j][k];
					if(!gamenotcompleted && arr[j][k] == '.')
						gamenotcompleted = true;
				}
			}
			//check every row
			bool found = false;
			char start;
			for(int j = 0 ; j < 4;j++)
			{
				if(checkrow(arr,j,start))
				{
					found = true;
					break;
				}
			}
			if(found)
			{
				std::cout<<"Case #"<<i<<": "<<start<<" won"<<std::endl;
				continue;
			}
			//check every column
			for(int j = 0; j < 4; j++)
			{
				if(checkcol(arr,j,start))
				{
					found = true;
					break;
				}
			}
			if(found)
			{
				std::cout<<"Case #"<<i<<": "<<start<<" won"<<std::endl;
				continue;
			}
			//check either diagonal
			if(checkdiagonal(arr,start))
			{
				std::cout<<"Case #"<<i<<": "<<start<<" won"<<std::endl;
				continue;
			}
			if(checkinversediagonal(arr,start))
			{
				std::cout<<"Case #"<<i<<": "<<start<<" won"<<std::endl;
				continue;
			}
			if(gamenotcompleted)
			{
				std::cout<<"Case #"<<i<<": "<<"Game has not completed"<<std::endl;
				continue;
			}
			else
			{
				std::cout<<"Case #"<<i<<": "<<"Draw"<<std::endl;
				continue;
			}
		} 
	}
}

int main()
{

	

	codejam::tictactoe();

	return 0;
}
