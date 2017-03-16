#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin,*fout;
    fin=fopen("C-small-attempt0.in","r");
    fout=fopen("out.txt","w");
    int T,i;
    fscanf(fin,"%d",&T);
    for(i=0;i<T;i++){
            fprintf(fout,"Case #%d: gamw to xristo sas\n",i+1);

    }
    fclose(fin);
    fclose(fout);
    return 0;
}
