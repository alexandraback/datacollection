
#include <stdio.h>
int main ()
{
    FILE *fp1, *fp2;
    fp1 = fopen ("A-large.in", "r");
    fp2 = fopen ("output.txt", "w");

    int t;
    int count;
    double p, q;
    int twoCount;
    char matchFound;
    char maxFound;
    int ans[40];
    char ansCount;

    if (fp1 && fp2)
    {
        fscanf(fp1, "%d", &t);
        count = 0;

        while (count<t)
        {
            count++;
            fscanf(fp1, "%lf/%lf", &p, &q);
            twoCount = 0;
            matchFound = 0;
            maxFound = 0;
            ansCount = 0;
            while (twoCount<40)
            {
                twoCount++;

                if (p<q)
                    p*=2;
                else if (p>q)
                {
                    ans[ansCount++] = twoCount-1;
                    maxFound = 1;
                    p-=q;
                    p*=2;
                }
                if (p==q)
                {
                    matchFound = 1;
                    break;
                }

            }
            if (matchFound == 1 && maxFound == 1)
                fprintf(fp2, "Case #%d: %d\n", count, ans[0]);
            else if (matchFound == 1)
                fprintf(fp2, "Case #%d: %d\n", count, twoCount);
            else
                fprintf(fp2, "Case #%d: impossible\n", count);
        }



        fclose(fp1);
        fclose(fp2);
    }
    else
        printf("error while opening files");
    return 0;
}
