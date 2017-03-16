#include <stdlib.h>
#include <stdio.h>

int stop = 0;
int v[51][51], v1[51][51];
int t,r,c,m;
int test;

void expand(int i, int j, int r1, int r2, int c1, int c2)
{
    if(v1[i][j]=='.' && i>=r1 && i<=r2 && j>=c1 && j<=c2)
    {

        if (v1[i-1][j]!='*'
                && v1[i-1][j-1]!='*'
                && v1[i][j-1]!='*'
                && v1[i+1][j-1]!='*'
                && v1[i+1][j]!='*'
                && v1[i+1][j+1]!='*'
                && v1[i][j+1]!='*'
                && v1[i-1][j+1]!='*')
        {
            v1[i][j]='-';
            expand(i-1,j,r1,r2,c1,c2);
            expand(i-1,j-1,r1,r2,c1,c2);
            expand(i,j-1,r1,r2,c1,c2);
            expand(i+1,j-1,r1,r2,c1,c2);
            expand(i+1,j,r1,r2,c1,c2);
            expand(i+1,j+1,r1,r2,c1,c2);
            expand(i,j+1,r1,r2,c1,c2);
            expand(i-1,j+1,r1,r2,c1,c2);
        }
        else v1[i][j]='-';
    }
}

int verifica(int r1, int r2, int c1, int c2)
{
    int ok;

    for (int i=r1;i<=r2;i++)
    {
        for (int j=c1;j<=c2;j++)
        {

            for (int ii=r1-1;ii<=r2+1;ii++)
                for (int jj=c1-1;jj<=c2+1;jj++)
                    v1[ii][jj]=v[ii][jj];

            if (v1[i][j]!='*')
                expand(i,j,r1,r2,c1,c2);


            ok = 1;
            for (int ii=r1;ii<=r2;ii++)
            {
                for (int jj=c1;jj<=c2;jj++)
                {
                    if (v1[ii][jj]=='.') ok = 0;
                }
            }

            if (ok==1)
            {
                v[i][j]='c';
                return 1;
            }
        }
    }

    return 0;
}

void tryfill(int r1, int r2, int c1, int c2, int m, int x, int y)
{
    int ii,jj;
    if (m>(r2-r1+1)*(c2-c1+1)) return;
    if (m>0)
    {
        for (int i = x; i<=r2 && stop==0; i++)
        {
            for (int j = y; j<=c2 && stop==0; j++)
            {
                if (v[i][j]!='*')
                {
                    v[i][j] = '*';
 //                   printf("%d-%d",i,j);
                    ii = i;
                    jj = j;
                    if (j==c2)
                    {
                        ii=i+1; jj=c1;
                    }
                    tryfill(r1,r2,c1,c2,m-1, ii, jj);
                    if (stop==0) v[i][j]='.';
                }
            }
        }
    }
    else
    {
        if (verifica(r1,r2,c1,c2))
        {
            stop = 1;
        }
    }
}

void backtrack(int r1, int r2, int c1, int c2, int m)
{
    int r = r2-r1+1;
    int c = c2-c1+1;
  /*  if (m>2*(r-2)+2*c && r>1 && c>1)
    {
        for (int i=r1;i<=r2;i++)
        {
            v[i][c1] = '*';
            v[i][c2] = '*';
        }
        for (int i=c1;i<=c2;i++)
        {
            v[r1][i] = '*';
            v[r2][i] = '*';
        }
        backtrack(r1+1,r2-1,c1+1,c2-1,m-(2*(r-2)+2*c));
    }
    else
    {*/
        tryfill(r1,r2,c1,c2,m,r1,c1);
    //}
}

int main()
{
    FILE *f, *g;
    f = fopen("Cin.txt","r");
    g = fopen("Cout.txt","w");

    fscanf(f,"%d",&t);
    for (test = 1;test<=t;test++)
    {
        stop = 0;

        fscanf(f,"%d%d%d",&r,&c,&m);
        for (int i=0;i<=r+1;i++)
            for(int j=0;j<=c+1;j++)v[i][j]='.';

        if (m<r*c) backtrack(1,r,1,c,m);



        fprintf(g,"Case #%d:\n",test);
        if (stop==1)
        {
            for (int i=1;i<=r;i++)
            {
                for (int j=1;j<=c;j++)
                    fprintf(g,"%c",v[i][j]);
                fprintf(g,"\n");
            }
        }
        else
            fprintf(g,"Impossible\n");
    }

    fclose(f);
    fclose(g);
    return 0;
}
