#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define MAXNBPIECES 1000

void parse_number_of_tests(FILE * file, int * number)
{
	fscanf(file, "%d", number);
}

void parse_one_test(FILE * inputFile, int * nbPieces ,double naomi[], double ken[])
{
	fscanf(inputFile, "%d", nbPieces);
	for (int i=0; i < *nbPieces; ++i)
		fscanf(inputFile, "%lf", &naomi[i]);
	for (int i=0; i < *nbPieces; ++i)
		fscanf(inputFile, "%lf", &ken[i]);
}

int find_min(double deck[], int nbPieces)
{
	int indiceDuMin;
	double lastMinFound = 1;
	for(int i=0; i<nbPieces; i++)
	{
		if (deck[i]< lastMinFound)
		{
			indiceDuMin = i;
			lastMinFound = deck[i];
		}
	}
	return indiceDuMin;
}

int find_max(double deck[], int nbPieces)
{
	int indiceDuMax;
	double lastMaxFound = 0;
	for(int i=0; i<nbPieces; i++)
	{
		if (deck[i]> lastMaxFound)
		{
			indiceDuMax = i;
			lastMaxFound = deck[i];
		}
	}
	return indiceDuMax;
}

int min_over(double deck[], int nbPieces, double value)
{
	int index=-1;
	double bestCandidate=1;
	for (int i=0; i< nbPieces; i++)
	{
		if (deck[i]> value && deck[i]<bestCandidate)
		{
			bestCandidate = deck[i];
			index = i;
		}
	}
	return index;
}

void burn(double ken[], double naomi[], int * nbPiece, int indexOfPieceToBurnKen, int indexOfPieceToBurnNaomi)
{
	double tmp;
	(*nbPiece) --;
	tmp = ken[*nbPiece];
	ken[*nbPiece]= ken[indexOfPieceToBurnKen];
	ken[indexOfPieceToBurnKen]= tmp;

	tmp = naomi[*nbPiece];
	naomi[*nbPiece]= naomi[indexOfPieceToBurnNaomi];
	naomi[indexOfPieceToBurnNaomi]= tmp;
}


int one_war_turn(double ken[], double naomi[], int *nbPiece)
{
	int retval = -1;
	int iKen = min_over(ken, *nbPiece, naomi[0]);
	if(iKen == -1)
	{
		iKen = find_min(ken, *nbPiece);
		retval = 1;
	}
	else retval = 0;
	burn(ken, naomi, nbPiece, iKen, 0);
	return retval;
}

int one_deceitful_war_turn(double ken[], double naomi[], int *nbPiece)
{
	int retval;
	int minKen = find_min(ken, *nbPiece), minNaomi = find_min(naomi, *nbPiece);

	if(ken[minKen] < naomi[minNaomi])
	{
		retval = 1;
		burn(ken, naomi, nbPiece, minKen, minNaomi);

	}
	else
	{
		retval = 0;
		burn(ken, naomi, nbPiece, find_max(ken, *nbPiece), minNaomi);
	}
	return retval;
}

int one_war_game(double ken[], double naomi[], int nbPiece) // returns Naomi's maximum score
{
	int score = 0;
	while(nbPiece > 0)
	{
		score += one_war_turn(ken, naomi, &nbPiece);
	}
	return score;
}

int one_deceitful_war_game(double ken[], double naomi[], int nbPiece)
{
	int score = 0;
	while(nbPiece > 0)
	{
		score += one_deceitful_war_turn(ken, naomi, &nbPiece);
	}
	return score;
}

void print_deck(double deck[], int nbPieces)
{
	for(int i= 0; i< nbPieces; i++)
	{
		std::cout <<deck[i] << " " ;
	}
	std::cout << std::endl;
}



void solve_one_test(FILE * inputFile)
{
	int	a;
	int nbPieces;
	double naomi[MAXNBPIECES], ken[MAXNBPIECES];
	parse_one_test(inputFile, &nbPieces, naomi, ken);
	std::cout << one_deceitful_war_game(ken, naomi, nbPieces) << " ";
	std::cout << one_war_game(ken, naomi, nbPieces) << std::endl;

}

void solve_input_file()
{
	int numberOfTests;
	FILE * inputFile= fopen ("input.in", "r");
	parse_number_of_tests(inputFile, &numberOfTests);

	for(int i =0; i< numberOfTests; i++)
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_one_test(inputFile);
	}
}

int main(int argc, char * argv[])
{
	solve_input_file();
	return EXIT_SUCCESS;
}