

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	FILE* f;
	FILE* g;
	int r,c,w,tests;
		
	f = fopen("input.txt","r");
	g = fopen("output.txt","w");
	
	fscanf(f,"%d",&tests);
	for (int t=1;t<=tests;t++) {
		fscanf(f,"%d%d%d",&r,&c,&w);
		
		int rowcost = (c/w)*r+w-1;
		
		if (c % w !=0) {
			rowcost++;
		}
		
		fprintf(g,"Case #%d: %d\n",t,rowcost);
	}
	return 0;
}

