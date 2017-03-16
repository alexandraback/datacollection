#include <stdio.h>
int main()
{
    FILE* in;
    FILE* out;
    int t,n;
    int sn,p;    
    int score; 
    int div, mod,i,j;
    int tmp,D;    
    int B,A,louge,laji;          
    
    in = fopen("B-small-attempt0.in", "r");
    out = fopen("ou.txt", "w");
    fscanf(in, "%d", &t);
    for (i = 1; i <= t; i++)
    {
        fscanf(in, "%d%d%d", &n, &sn, &p);
        D = 0;
        B = 0;
        A = 0;
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
                        D++;
                    }
                    else if (div >= p && div + 1 > 10)
                    {
                        louge++;
                    }
                    else if (div + 1 == p && div - 1 >= 0)
                    {
                        B++;
                    }
                    else if (div + 1 < p && div - 1 >= 0)
                    {
                        A++;
                    }
                    else
                    {
                        laji++;
                    }
                    break;
                case 1:
                    if (div + 1 >= p && div - 1 >= 0)
                    {
                        D++;
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
                        A++;
                    }
                    break;
                case 2:
                    if (div + 1 >= p && div + 2 <= 10)
                    {
                        D++;
                    }
                    else if (div + 1 >= p && div + 2 > 10)
                    {
                        louge++;
                    }
                    else if (div + 2 == p)
                    {
                        B++;
                    }
                    else
                    {
                        A++;
                    }
                    break;
                default:
                    break;
            } 
        }
        tmp = sn > B ? B : sn;
        fprintf(out, "Case #%d: %d\n", i, D + louge + tmp);
    }
    fclose(out);
    fclose(in);
    return 0;
}
