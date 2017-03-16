#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define file_in "A-large.in"
#define file_out "Q1.out"

int test;          /* # of test case */
FILE *fi;
FILE *fo;

char a[10][10];

int checkresult(char c) //1: c won, 0=draw, 2=incompleted
{
	int j, k;
	bool ok;
	char x, y;
	
	for (j=0; j<4; j++)
	{
		//check 4 rows
		x = a[j][0];
		if (x=='T') x=c;
		if (x!=c) continue;
		
		ok = true;
		for (k=1; k<4; k++)
		{
			y = a[j][k];
			if (y=='T') y=c;
			if (x!=y)
			{
				ok = false;
				break;
			}
		}
		if (ok) return 1;
	}
	
	for (j=0; j<4; j++)
	{
		//check 4 columns
		x = a[0][j];
		if (x=='T') x=c;
		if (x!=c) continue;

		ok = true;
		for (k=1; k<4; k++)
		{
			y = a[k][j];
			if (y=='T') y=c;
			if (x!=y)
			{
				ok = false;
				break;
			}
		}
		if (ok) return 1;
	}
	
	//duong cheo chinh
	x = a[0][0]; if (x=='T') x=c; if (x!=c) goto abc;
	y = a[1][1]; if (y=='T') y=c; if (x!=y) goto abc;
	y = a[2][2]; if (y=='T') y=c; if (x!=y) goto abc;
	y = a[3][3]; if (y=='T') y=c; if (x!=y) goto abc;
	return 1;
	
abc://duong cheo phu
	x = a[0][3]; if (x=='T') x=c; if (x!=c) goto def;
	y = a[1][2]; if (y=='T') y=c; if (x!=y) goto def;
	y = a[2][1]; if (y=='T') y=c; if (x!=y) goto def;
	y = a[3][0]; if (y=='T') y=c; if (x!=y) goto def;
	return 1;
	
def://draw or incompleted?
	//if found any . then incomplete
	for (j=0; j<4; j++)
		for (k=0; k<4; k++)
		    if (a[j][k]=='.') return 2; //incompleted

	return 0;   //draw
}

int main() {
    int i, j, k;

    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);

    for (i=1; i<=test; i++)
    {
		for (j=0; j<4; j++)
            fscanf(fi, "%s", a[j]);

		k = checkresult('X');
        //fprintf(fo, "Case #%d %d: \n", i, k);

		if (k==1)
		{
            fprintf(fo, "Case #%d: X won\n", i);
		}
		else
		{
			k = checkresult('O');
			switch (k)
			{
				case 0: fprintf(fo, "Case #%d: Draw\n", i); break;
				case 1: fprintf(fo, "Case #%d: O won\n", i); break;
				case 2: fprintf(fo, "Case #%d: Game has not completed\n", i); break;
			}
   	 	}
	}

    fclose(fi);
    fclose(fo);
}

