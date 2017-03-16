
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int cases;
    FILE *fp;
    fp=fopen("/Users/IndianaJones/Downloads/B-large.in", "r");
    FILE *fpout;
    fpout=fopen("/Users/IndianaJones/Downloads/output.txt", "w");
    fscanf(fp, "%d\n", &cases);
    for (int i;i<cases;i++)
    {
        double finalNumber = 0.000000;
        double secsUntilEnd;
        double secsUntilNext;
        double nextSecsUntilNext;
        double rate = 2.000000;
        double c;
        double f;
        double x;
        fscanf(fp, "%lf %lf %lf\n", &c, &f, &x);
        secsUntilEnd = x/rate;
        secsUntilNext = c/rate;
        nextSecsUntilNext = (c/rate) + (x/(rate + f));
        while(secsUntilEnd>nextSecsUntilNext)
        {
            finalNumber = finalNumber + secsUntilNext;
            rate = rate + f;
            secsUntilEnd = x/rate;
            secsUntilNext = c/rate;
            nextSecsUntilNext = (c/rate) + (x/(rate + f));
        }
        finalNumber = finalNumber + secsUntilEnd;
        fprintf(fpout, "Case #%d: %0.7lf\n",i+1,finalNumber);
    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

