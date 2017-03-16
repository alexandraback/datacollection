#include <stdio.h>

int main()
{
	int numCase, cases, i, j, count;
	char maze[4][5], current, winner;
	bool win;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i", &cases);

	for(numCase = 1; numCase <= cases; numCase++)
	{
		for(i = 0; i < 4; i++)
			scanf("%s\n", maze[i]);

		win = false;

		// check if there is a winner	
		// check horizontal
		for(i = 0; i < 4; i++)
		{			
			current = maze[i][0];
			if(current != '.')
			{				
				for(j = 1; j < 4; j++)
				{
					if(maze[i][j] == '.')
						break;
					else if(current == 'T')
						current = maze[i][j];
					else
					{
						if(maze[i][j] != current && maze[i][j] != 'T')
							break;
					}
				}

				if(j == 4) // complete
				{
					win = true;
					winner = current;
					break;
				}				
			}
		}

		if(!win)
		{
			// check vertical
			for(i = 0; i < 4; i++)
			{
				current = maze[0][i];
				if(current != '.')
				{				
					for(j = 1; j < 4; j++)
					{
						if(maze[j][i] == '.')
							break;
						else if(current == 'T')
							current = maze[j][i];
						else
						{
							if(maze[j][i] != current && maze[j][i] != 'T')
								break;
						}
					}

					if(j == 4) // complete
					{
						win = true;
						winner = current;
						break;
					}				
				}
			}
		}

		if(!win)
		{
			// check diagonal 1
			if(maze[0][0] != '.')
			{
				current = maze[0][0];
				if(current != '.')
				{				
					for(j = 1; j < 4; j++)
					{
						if(maze[j][j] == '.')
							break;
						else if(current == 'T')
							current = maze[j][j];
						else
						{
							if(maze[j][j] != current && maze[j][j] != 'T')
								break;
						}
					}

					if(j == 4) // complete
					{
						win = true;
						winner = current;
					}				
				}
			}
		}

		if(!win)
		{
			// check diagonal 2
			if(maze[0][3] != '.')
			{
				current = maze[0][3];
				if(current != '.')
				{				
					for(j = 2; j >= 0; j--)
					{
						if(maze[3-j][j] == '.')
							break;
						else if(current == 'T')
							current = maze[3-j][j];
						else
						{
							if(maze[3-j][j] != current && maze[3-j][j] != 'T')
								break;
						}
					}

					if(j == -1) // complete
					{
						win = true;
						winner = current;
					}				
				}
			}
		}

		if(!win)
		{
			count = 0;
			// check if all boards is filled in
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(maze[i][j] != '.')
						count++;
				}
			}
		}

		printf("Case #%i: ", numCase);

		if(win)
			printf("%c won\n", winner);
		else
		{
			if(count == 16)
				printf("Draw\n");
			else
				printf("Game has not completed\n");
		}

	}

	return 0;
}