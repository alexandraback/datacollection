#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define SQUARESIZE 4
#define BADMAGICIAN 0
#define VOLUNTEERCHEATED -1

#define MINE '*'
#define CLICK 'c'
#define BLANK '.'

#define GRIDSIZE 50

void parse_number_of_tests(FILE * file, int * number)
{
	fscanf(file, "%d", number);
}

void print_grid(char grid[][GRIDSIZE], int rows, int columns)
{
	for(int i= 0; i< rows; i++)
	{
		for(int j=0; j< columns; j++ )
		{
			std::cout <<grid[i][j];
		}
		std::cout << std::endl;
	}
}

void random_grid(char grid[][GRIDSIZE], int rows, int columns)
{
	char symbol[]={MINE, CLICK, BLANK}; 
    srand(time(NULL));  

	for(int i=0; i<rows; ++i)
    {
		for(int j =0 ; j< columns; j++)
		{
			grid[i][j] = symbol[rand() % 3];
		}
    }
}
void fill_grid(char grid[][GRIDSIZE], int rows, int columns)
{
	for(int i=0; i<rows; ++i)
		for(int j =0 ; j< columns; j++)
			grid[i][j] = MINE;
}


void parse_one_test(FILE * inputFile, int * rows, int * columns, int * nbMines)
{
	fscanf(inputFile, "%d %d %d", rows, columns, nbMines);
}
void impossible()
{
	std::cout << "Impossible" << std::endl;
}

void solve_one_test(FILE * inputFile)
{
	int rows, columns, nbMines, nbBlank;
	char grid[GRIDSIZE][GRIDSIZE];
	parse_one_test(inputFile,&rows,&columns,&nbMines);
	nbBlank = rows*columns - nbMines;
	fill_grid(grid, rows, columns);
	if(nbBlank ==1)
	{}
	else if(columns == 1)
	{
		for(int i= 0; i< nbBlank; i++)
			grid[i][0]= BLANK;
	}
	else if(rows == 1)
	{
		for(int i= 1; i< nbBlank; i++)
			grid[0][i]= BLANK;
	}
	else if (nbBlank==2)
	{
		impossible();
		return;
	}
	else if(columns == 2)
	{
		if(nbBlank % 2 == 1)
		{
			impossible();
			return;
		}
		else
		{
			for(int i= 0; i< nbBlank/2; i++)
				grid[i][0]= grid[i][1] = BLANK;
		}
	}
	else if(rows == 2)
	{
		if(nbBlank % 2 == 1)
		{
			impossible();
			return;
		}
		else
		{
			for(int i= 0; i< nbBlank/2; i++)
				grid[0][i]= grid[1][i] = BLANK;
		}
	}
	else if(((nbBlank % 2 == 1) && nbBlank < 9) || nbBlank == 2 )
	{
		impossible();
		return;
	}
	else if (rows < columns)
	{
		if(nbBlank < (2*rows +2))
		{
			if(nbBlank % 2 == 0)
			{
				for (int i = 0 ; i < nbBlank/2; i++)
					grid[i][0]= grid[i][1] = BLANK;
			}
			else
			{
				for (int i = 0 ; i < (nbBlank-3)/2; i++)
					grid[i][0]= grid[i][1] = BLANK;
				for(int i =0;  i<3; i++)
					grid[i][2]= BLANK;
			}
		}
		else
		{
			for(int i = 0; i*rows < nbBlank ; i++)
				for(int j= 0; i*rows+j < nbBlank && j < rows; j++ )
					grid[j][i] = BLANK;
			if(nbBlank % rows == 1)
			{
				grid[1][nbBlank/rows]= BLANK;
				grid[rows-1][nbBlank/rows -1]= MINE;
			}
		}
	}
	else
	{
		if(nbBlank < (2*columns +2))
		{
			if(nbBlank % 2 == 0)
			{
				for (int i = 0 ; i < nbBlank/2; i++)
					grid[0][i]= grid[1][i] = BLANK;
			}
			else
			{
				for (int i = 0 ; i < (nbBlank-3)/2; i++)
					grid[0][i]= grid[1][i] = BLANK;
				for(int i =0;  i<3; i++)
					grid[2][i]= BLANK;
			}
		}
		else
		{
			for(int i = 0; i*columns < nbBlank ; i++)
				for(int j= 0; i*columns+j < nbBlank && j < columns; j++ )
					grid[i][j] = BLANK;
			if(nbBlank % columns == 1)
			{
				grid[nbBlank/columns][1]= BLANK;
				grid[nbBlank/columns -1][columns-1]= MINE;
			}
		}
	}

	grid[0][0] = CLICK;
	print_grid(grid, rows, columns);
}



void solve_input_file()
{
	int numberOfTests;
	FILE * inputFile= fopen ("input.in", "r");
	parse_number_of_tests(inputFile, &numberOfTests);

	for(int i =0; i< numberOfTests; i++)
	{
		std::cout << "Case #" << i+1 << ": " << std::endl;
		solve_one_test(inputFile);
	}
}

int main(int argc, char * argv[])
{
	solve_input_file();
	return EXIT_SUCCESS;
}