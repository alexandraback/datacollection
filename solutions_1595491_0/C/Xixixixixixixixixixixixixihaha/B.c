#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE* in;
    FILE* out;
    int t;      // testcase个数。。
    int n;      // Googler个数。。 
    int sn;     // surprising的Googler个数。。 
    int p;      // 最好score至少是p。。 
    int score;  // score。。 
    int i, j;
    int div, mod;
    int tmp;
    
    int chunge;         // 不管是否surprising都能过分数线的Googler个数。。
    int xixihaha;       // surprising才能过分数线的Googler个数。。
    int ibmTCLcoder;    // 不管是否surprising都过不了分数线的Googler个数。。 
    int louge;          // 过了分数线，但是不能surprising的Googler个数，原因在于surprising后超过10分。。 
    int laji;           // 过不了分数线，也不能surprising的Googler个数，原因在于surprising后小于0分。。 
    /* 最终结果就是 chunge + louge + MIN(sn, xixihaha) */ 
    
    in = fopen("B-small-attempt0.in", "r");
    out = fopen("out.txt", "w");
    fscanf(in, "%d", &t);
    for (i = 1; i <= t; i++)
    {
        fscanf(in, "%d%d%d", &n, &sn, &p);
        chunge = 0;
        xixihaha = 0;
        ibmTCLcoder = 0;
        louge = 0;
        laji = 0; 
        for (j = 0; j < n; j++)
        {
            fscanf(in, "%d", &score);
            div = score / 3;
            mod = score % 3;
            switch (mod)
            {
                case 0:
                    if (div >= p && div + 1 <= 10)
                    {
                        chunge++;
                    }
                    else if (div >= p && div + 1 > 10)
                    {
                        louge++;
                    }
                    else if (div + 1 == p && div - 1 >= 0)
                    {
                        xixihaha++;
                    }
                    else if (div + 1 < p && div - 1 >= 0)
                    {
                        ibmTCLcoder++;
                    }
                    else
                    {
                        laji++;
                    }
                    break;
                case 1:
                    if (div + 1 >= p && div - 1 >= 0)
                    {
                        chunge++;
                    }
                    else if (div + 1 >= p && div - 1 < 0)
                    {
                        louge++;
                    }
                    else if (div + 1 < p && div - 1 < 0)
                    {
                        laji++;
                    }
                    else
                    {
                        ibmTCLcoder++;
                    }
                    break;
                case 2:
                    if (div + 1 >= p && div + 2 <= 10)
                    {
                        chunge++;
                    }
                    else if (div + 1 >= p && div + 2 > 10)
                    {
                        louge++;
                    }
                    else if (div + 2 == p)
                    {
                        xixihaha++;
                    }
                    else
                    {
                        ibmTCLcoder++;
                    }
                    break;
                default:
                    break;
            } // end of switch (mod)..
        }
        tmp = sn > xixihaha ? xixihaha : sn;
        fprintf(out, "Case #%d: %d\n", i, chunge + louge + tmp);
    }
    fclose(out);
    fclose(in);
    return 0;
}
