#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int t,n, cont, skip;
double naomi[1001], ken[1001];

int main()
{
    FILE *f, *g;
    f = fopen("Din.txt","r");
    g = fopen("Dout.txt","w");

    fscanf(f,"%d",&t);
    for (int test=1; test<=t;test++)
    {
        fscanf(f,"%d",&n);
        for (int i =0;i<n;i++)
        {
            fscanf(f,"%lf",&naomi[i]);
        }
        sort(naomi,naomi+n);

        for (int i=0;i<n;i++)
        {
            fscanf(f,"%lf",&ken[i]);
        }
        sort(ken,ken+n);


        fprintf(g,"Case #%d: ",test);
        cont = 0;
        skip = 0;
        while(naomi[skip]<ken[0])
        {
            skip++;
        }

        for (int i = skip;i<n;i++)
        {
            if (naomi[i]>ken[i-skip]) cont++;
            else skip++;
        }

        fprintf(g,"%d ",cont);

        skip = n-1;
        cont = 0;
        for (int i=n-1;i>=0;i--)
        {
            if (naomi[i]>ken[skip]) cont++;
            else skip--;
        }

        fprintf(g,"%d\n",cont);
    }


    fclose(f);
    fclose(g);
    return 0;
}
