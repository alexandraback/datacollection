#include <stdio.h>

#define MAX_CLASS 1000
#define MAX_PARENT 10

int parents [MAX_CLASS][MAX_PARENT+1]; // parent[i][j] == 1 iff i is j's parent
int nchild [MAX_CLASS];
int mark [MAX_CLASS];
int q[MAX_CLASS];
int qh, qt;
int n_class;
int found;

void do_case(FILE * fin, FILE* fout, int case_no)
{
	int i, j, k, l, nparents;
	

	fscanf(fin, "%i", &n_class);
	for(i=0; i<n_class; i++)
		nchild[i] = 0;
	for(i=0; i<n_class; i++)
	{
		fscanf(fin, "%i", &nparents);
		for(j=0; j<nparents; j++)
		{
			fscanf(fin, "%i", &k);
			k--;
			nchild[k]++;
			parents[i][j] = k;
		}
		parents[i][nparents] = -1;
	}
	
	found =0;	
	for(i=0; i<n_class; i++)
	{
		if(nchild[i])	//Don't bother searching on nodes that have children,
						//They're children will show what we need.
			continue;
		
		printf("Search\t%i\n", i);
		for(j=0; j<n_class; j++)
			mark[j] = 0;
			
		q[0]=i; mark[i] =1;
		qt=0; qh=1;
		
		while(qt<qh)
		{
			j = q[qt]; qt++;
			printf("Search %i %i\n", i, j);
			for(k=0; parents[j][k]>=0; k++)
			{
				l = parents[j][k];
				if(mark[l])	//K already marked (i.e. 2nd visit this search)
				{	//Have a diamond path
					printf("Found\t%i %i %i\n", i,j,l);
					found =1;
					break;
				}
				//No diamond found, post k to search.
				printf("Mark\t%i %i %i\n", i,j,l);
				mark[l] = 1;
				q[qh] = l; qh++;
			}
			if(found)
				break;
		}
		if(found)
			break;
	}
	
	fprintf(fout, "Case #%i: ", case_no);
	if(found)
		fprintf(fout, "Yes");
	else
		fprintf(fout, "No");
	fprintf(fout, "\n");
	return;
}

int main (void)
{
	FILE* fin;
	FILE* fout;
	int i, num_cases;
	
	fin  = fopen("in.txt", "r");
	fout = fopen("out.txt", "w");
	
	fscanf(fin, "%i", &num_cases);
	
	for(i=1; i<=num_cases; i++)
	{
		do_case(fin, fout, i);
	}
}
