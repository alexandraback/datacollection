#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	fstream output_file;
	output_file.open("output.txt");

	int T;
	cin >> T;
	for(int i=0; i<T;i++)
	{
		int R, C, M;
		cin>>R>>C>>M;

		vector<string> field(R, string(C, '*'));

		int safe = R*C - M;

		if(R==1)
		{
			for(int j=0; j < safe;j++)
				field[0][j] = '.';
		}
		else if(C==1)
		{
			for(int j=0; j < safe;j++)
				field[j][0] = '.';
		}
		else if(R==2)
		{
			if((M%2 == 1 || safe == 2) && safe != 1)
			{
				field[0][0] = 'i';
			}
			else
			{
				for(int j=0; j<safe;j++)
				{
					field[j%2][j/2]='.';
				}
			}
		}
		else if(C==2)
		{
			if((M%2 == 1 || safe == 2) && safe != 1)
			{
				field[0][0] = 'i';
			}
			else
			{
				for(int j=0; j<safe;j++)
				{
					field[j/2][j%2]='.';
				}
			}
		}
		else
		{
			if(safe != 1)
			{

				if(safe%2 == 1)
				{
					if(safe < 9)
					{
						field[0][0] = 'i';
					}
					else
					{
						if(safe < 3*C)
						{
							for(int j=0; j<C*3;j++)
							{
								field[j%3][j/3]='.';
								safe--;
								if(safe == 0)
								{
									if(j%3 == 0)
									{
										j--;
										field[j%3][j/3]='*';
										j+=2;
										field[j%3][j/3]='.';
									}
									break;
								}
							}
						}
						else
						{
							int row=0, col=0;
							while(safe > 0)
							{
								field[row][col]='.';
								col++;
								safe--;
								if(col == C)
								{
									col=0;
									row++;
								}
							}

							if(col==1)
							{
								field[row-1][C-1] = '*';
								field[row][col] = '.';
							}
						}
					}
				}
				else
				{
					if(safe == 2)
					{
						field[0][0] = 'i';
					}
					else
					{
						//2x2
						if(safe < 2*C)
						{
							for(int j=0; j<C*2;j++)
							{
								field[j%2][j/2]='.';
								safe--;
								if(safe == 0)
								{
									break;
								}
							}
						}
						else
						{
							int row=0, col=0;
							while(safe > 0)
							{
								field[row][col]='.';
								col++;
								safe--;
								if(col == C)
								{
									col=0;
									row++;
								}
							}

							if(col==1)
							{
								field[row-1][C-1] = '*';
								field[row][col] = '.';
							}
						}
					}
				}
			}
		}

		if(field[0][0] != 'i')
			field[0][0]='c';

		output_file << "Case #" << i+1 << ":\n";

		if(field[0][0]=='i')
		{
			output_file << "Impossible\n";
		}
		else
		{
			for(int j=0; j < R; j++)
			{
				output_file << field[j] << endl;
			}
		}

	}

	output_file.close();
	return 0;
}