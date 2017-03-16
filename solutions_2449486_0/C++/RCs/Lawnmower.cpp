#include <stdio.h>
#include <string.h>

#include <algorithm>

using namespace std;

int main()
{
	int cases, numCase, maze[100][100], row, col, i, j, currentIndex, now, currentRow, currentCol;	
	int smaller, listNumber[101], countNumber;
	bool used[101], found, horizontalFail, verticalFail, impossible;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		scanf("%i %i", &row, &col);
		// init
		countNumber = 0;
		memset(used, 0, 101);
		
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				scanf("%i", &maze[i][j]);
				if(!used[maze[i][j]])
				{
					listNumber[countNumber++] = maze[i][j];
					used[maze[i][j]] = true;
				}
			}
		}

		sort(listNumber, listNumber + countNumber);

		impossible = false;
		currentIndex = 0;
		while(currentIndex < countNumber && !impossible)
		{
			now = listNumber[currentIndex];

			while(!impossible)
			{
				// get maze index that has this number
				found = false;
				for(i = 0; i < row; i++)
				{
					for(j = 0; j < col; j++)
					{
						if(maze[i][j] == now)
						{
							found = true;
							currentRow = i;
							currentCol = j;
							break;
						}
					}
					if(found)
						break;
				}

				if(!found)
					break;
				else
				{
					horizontalFail = false;
					verticalFail = false;

					// for this number, at least one row/column must be cleared
					// find horizontally if possible to clear
					for(j = 0; j < col; j++)
					{
						if(maze[currentRow][j] != 0 && maze[currentRow][j] != now)
						{
							horizontalFail = true;
							break;
						}
					}

					for(i = 0; i < row; i++)
					{
						if(maze[i][currentCol] != 0 && maze[i][currentCol] != now)
						{
							verticalFail = true;
							break;
						}
					}

					if(horizontalFail && verticalFail)
						impossible = true;
					else
					{
						if(!horizontalFail)
						{
							for(j = 0; j < col; j++)
								maze[currentRow][j] = 0;
						}
						if(!verticalFail)
						{
							for(i = 0; i < row; i++)
								maze[i][currentCol] = 0;
						}
					}
				}
			}
			currentIndex++;
		}

		if(!impossible)
			printf("Case #%i: YES\n", numCase);
		else
			printf("Case #%i: NO\n", numCase);
	}

	return 0;
}