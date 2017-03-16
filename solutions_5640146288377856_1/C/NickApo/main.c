#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, r, c, w;
    FILE * fpin, *fpout;

    fpin=fopen ("A-large.in", "r");
    fpout=fopen ("outlarge.txt", "w");

    fscanf (fpin, "%d", &n);

    for (k=1 ; k<=n; k++)
    {
        int reply;
        fscanf (fpin, "%d %d %d", &r, &c, &w);
        reply = (c/w)*r+w;
        if (c%w==0)
            reply--;
        fprintf (fpout,"Case #%d: %d\n", k,reply);

    }

    fclose(fpin);
    fclose(fpout);

    return 0;
}


