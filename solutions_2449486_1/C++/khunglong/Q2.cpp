#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define file_in "B-large.in"
//#define file_in "Q2.in"
#define file_out "Q2.out"

int test;          /* # of test case */
FILE *fi;
FILE *fo;

int a[102][102];
//int b[102][102];
//int r[101], c[101];
int n, m;
//int m_h; //max_height

int cut()
{
	int i, j, k;
	int u, d, l, r;
	int x;

	for (j=1; j<=n; j++)
	{
		for (k=1; k<=m; k++)
		{
            x = a[j][k];
            
            //check up, left
            u = 0; d = 0; l = 0; r = 0;
            //check up
            for (i=0; i<j; i++)
                if (a[i][k] > x)
				{
					u = 1;  break;
				}
			//check down
            for (i=j+1; i<=n+1; i++)
                if (a[i][k] > x)
				{
					d = 1;  break;
				}
			//check left
            for (i=0; i<k; i++)
                if (a[j][i] > x)
				{
					l = 1;  break;
				}
			//check right
            for (i=k+1; i<=m+1; i++)
                if (a[j][i] > x)
				{
					r = 1;  break;
				}
				
			if ((u==1) && (l==1)) return 0;
			if ((u==1) && (r==1)) return 0;
			if ((d==1) && (l==1)) return 0;
			if ((d==1) && (r==1)) return 0;
			
		}
	}
	return 1;
}

int main() {
    int i, j, k;

    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);

    for (i=1; i<=test; i++)
    {
		fscanf(fi, "%d %d", &n, &m);

		for (j=0; j<=n+1; j++)
		    for (k=0; k<=m+1; k++) a[j][k]=0; //boundary
		    
		//m_h = 0;
		for (j=1; j<=n; j++)
		    for (k=1; k<=m; k++)
		    {
				fscanf(fi, "%d", &a[j][k]);
				//if (a[j][k]>m_h) m_h = a[j][k];
		    }

		if (cut()==1)
		{
            fprintf(fo, "Case #%d: YES\n", i);
            /*
            for (j=0; j<=n+1; j++)
            {
                for (k=0; k<=m+1; k++) fprintf(fo, "%d ", a[j][k]);
                fprintf(fo, "\n");
            }*/
		}
       else
       {
			fprintf(fo, "Case #%d: NO\n", i);
			/*
			for (j=0; j<=n+1; j++)
            {
                for (k=0; k<=m+1; k++) fprintf(fo, "%d ", a[j][k]);
                fprintf(fo, "\n");
            }*/
		}
	}

    fclose(fi);
    fclose(fo);
}

