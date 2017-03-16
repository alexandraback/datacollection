#include <stdio.h>

#define MAX_LEVELS 1000

int level_1star[MAX_LEVELS];
int level_2star[MAX_LEVELS];
int level_solved[MAX_LEVELS];
int num_levels;
int cur_stars, max_stars;
int plays;

int iterate()	//1 if new level finished, 0 if stuck
{
	int i, found_2star, best_i, best_cost;
	
	//Any levels we can get two stars on, get them (increases our score, will
	// have to play for 2 stars eventually anyway).
	found_2star = 0;
	for(i=0; i<num_levels; i++)	
	{
		if(level_solved[i] == 2)
			continue;
		
		if(level_2star[i] > cur_stars)
			continue;

		found_2star = 1;
		if(level_solved[i] ==1)
			cur_stars ++;
		else
			cur_stars += 2;
		level_solved[i] = 2;
		plays++;
	}
	if(found_2star)	//If said exists, get the stars
	{
		return 1;
	}
	
	//Find the level we can get 1 star on that it would be hardest to get 2
	// stars on (in hope this star lets us solve the easiest level for 2.
	best_i = num_levels, best_cost = -1;
	for (i=0; i<num_levels; i++)
	{
		if (level_solved[i] > 0)
			continue;
		
		if(level_1star[i] > cur_stars)
			continue;
		
		if (level_2star[i] > best_cost)
		{
			best_i = i; best_cost = level_2star[i];
		}
	}
	if(best_i < num_levels)
	{
		cur_stars++;
		level_solved[best_i] = 1;		
		plays++;
		return 1;
	}

	return 0;
}

int do_case (FILE* fin, FILE* fout, int case_no)
{
	int i;
	int result;
	
	// Get Input
	fscanf(fin, "%i", &num_levels);
	for(i=0; i<num_levels; i++)
	{
		fscanf(fin, "%i %i", &(level_1star[i]), &(level_2star[i]));
		level_solved[i] = 0;
	}

	max_stars = 2*num_levels;
	cur_stars = 0;
	plays = 0;
	
	while(cur_stars < 2*num_levels)
	{
		result = iterate();
		if(!result) break;		
	}
	
	//Present Output
	if(cur_stars == 2*num_levels)
	{
		fprintf(fout, "Case #%i: %i\n", case_no, plays);
	}
	else
	{
		fprintf(fout, "Case #%i: Too Bad\n", case_no);
	}
}

int main (void)
{
	FILE * fin;
	FILE * fout;
	int no_cases, i;
	
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	
	fscanf(fin, "%i", &no_cases);
	for(i=1; i<=no_cases; i++)
	{
		do_case(fin, fout, i);
	}	
	
	fclose(fin);
	fclose(fout);
	return 0;
}

