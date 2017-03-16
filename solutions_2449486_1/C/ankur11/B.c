#include<stdio.h>
#include<string.h>
int n, m;
int main ()
{
    int flag1,flag2 =1;
    FILE *fp1, *fp2;
	fp1=fopen("bl.in", "r");
	fp2=fopen("ans2bl.txt", "w");
	int i, j, k, l, T;
	fscanf(fp1, "%d", &T);
	for (k=1; k<T+1; k++)
	{
	 fscanf(fp1, "%d %d", &n, &m);
	 int a[n][m];
	 
	 for (i=0; i<n; i++)
     for (j=0; j<m; j++)
	     fscanf(fp1, "%d", &a[i][j]);
	 int flag =1;
	 for (i=0; i<n; i++)
	 for (j=0; j<m; j++)
	 {	 
         flag1=1;flag2=1;
         for (l=0;l<m;l++)
             if (a[i][l]> a[i][j]) flag1 = 0;
         for (l=0;l<n;l++)    
             if (a[l][j]> a[i][j]) flag2 = 0;
             
         if (flag1==0 && flag2==0) flag = 0;
     }       
         
	 if (k>1) fprintf(fp2, "\n");
	 if (flag) fprintf(fp2, "Case #%d: YES", k);
     else  fprintf(fp2, "Case #%d: NO", k);
     
     
    }
	fclose(fp1);
	fclose(fp2);
}
