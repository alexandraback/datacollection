#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


struct Set {
    int r;
    int c;
    int w;
    int output; // yes / no
};

struct DataSet {
    struct Set * sets;
    int nb_sets;
};


struct DataSet * load_input(char * fileName)
{
    // open file
    FILE* f = fopen(fileName, "r");
    assert(f != NULL);
    
    // allocate data
    struct DataSet * ds = malloc(sizeof(struct DataSet));
    
    // get nb of entries in input file and allocate them
    fscanf(f, "%d\n", &(ds->nb_sets));
    ds->sets = malloc(ds->nb_sets * sizeof(struct Set));
    
    // read each entry
    for(int e = 0; e < ds->nb_sets; e++)
    {
	ds->sets[e].output = -1; // init

	fscanf(f, "%d %d %d\n", &(ds->sets[e].r), &(ds->sets[e].c), &(ds->sets[e].w));
	/*
	ds->sets[e]. = malloc( * sizeof(int));
	for(int s = 0; s < l; s++)
	{
	    
	    fscanf(f, "", );
	    }
	    fscanf(f, "\n");*/
    }
    
    fclose(f);

    return ds;
}
/*
void debug_print(struct DataSet * ds)
{
    printf("\n\n==================================\n");
    printf("Nb tests : %d\n", ds->nb_sets);
    printf("==================================\n");    
    for(int o = 0; o < ds->nb_sets; o++)
    {
	printf("-----------------------------------\n");
	printf("Set no %d :\n", o);
	printf("nb_chars : %d\n", ds->sets[o].size_chars);
	printf("chars : ");
	for(int s = 0; s < ds->sets[o].size_chars; s++)
	{
	    if(ds->sets[o].chars[s] == I)
		printf("i");
	    else if(ds->sets[o].chars[s] == J)
		printf("j");
	    else if(ds->sets[o].chars[s] == K)
		printf("k");
	    else
		printf("?");
	}
	printf("\n");
    }
}
*/

void write_output(char * fileName, struct DataSet * ds)
{
    FILE * f = fopen(fileName, "w");
    for(int o = 0; o < ds->nb_sets; o++)
    {
	fprintf(f, "Case #%d: %d\n", o+1, ds->sets[o].output);
    }
    fclose(f);
}


void solve(struct DataSet * ds)
{
    for(int s = 0; s < ds->nb_sets; s++)
    {
	struct Set * set = &(ds->sets[s]);
	set->output = (set->c / set->w)*set->r;
	if(set->c % set->w == 0)
	    set->output += set->w-1;
	else
	    set->output += set->w;
    }
}


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
	fprintf(stderr, "usage: %s <input file> <output file>\n", argv[0]);
	return EXIT_FAILURE;
    }
    
    struct DataSet * ds = load_input(argv[1]);
    
    //debug_print(ds);
    solve(ds);
    
    write_output(argv[2], ds);
    return EXIT_SUCCESS;
}
