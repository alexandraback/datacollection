#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(void* a, void*b)
{
    double* aa;
    double* bb;

    aa = (double*)a;
    bb = (double*)b;

    return aa[2] - bb[2];
}


int main()
{
    int m, n, p,s;
    int i,j,k;
    int ii;
    int x,y,z;
    int nc;
    int result;
    int a, b;
    char left;
    double car[100][3];
    char line[2048];
    double t;
    double mint;
    double cumt;
    int mini;
    int tt;
    int colide;
    int fff = 10000;

    scanf("%d", &tt);

    for(nc = 1; nc <= tt; nc++)
    {
        scanf("%d", &n);
        gets(line);
        cumt = 0;
        for(i = 0; i < n; i++)
        {
            gets(line);
            sscanf(line, "%c%d%d", &left, &s, &p);
            if(left == 'L')
                car[i][0] = 0;
            else
                car[i][0] = 1;
            car[i][1] = s;
            car[i][2] = p;
        }
        qsort(car, n, 3*sizeof(double), cmp);
        while(fff--)
        {
            mint = 999999999;
            for(i = 0; i < n; i++)
            { 
                for(j = i+1; j < n; j++)
                {
                    if(car[i][0] == car[j][0] && car[i][1] > car[j][1])
                    {
                        t = (double)(car[j][2] - car[i][2] - 5) / (car[i][1] - car[j][1]);
                        //printf("%lf\n", t);
                        if(t < mint)
                        {
                            mint = t;
                            mini = i;
                        }
                    }
                    //printf("%lf %lf %lf vs %lf %lf %lf\n", car[i][0], car[i][1], car[i][2], car[j][0], car[j][1], car[j][2]);
                }
            }
            if(mint == 999999999)
            {
                break;
            }
            else
            {
                for(i = 0; i < n; i++)
                {
                    car[i][2] += car[i][1] * mint;
                }
                colide = 0;
                for(i = 0; i < n; i++)
                {
                    for(j = i+1; j < n; j++)
                    {
                        if((car[i][0] == car[j][0]) && (car[j][2] - car[i][2] <= 5.0))
                        {
                            for(k = 0; k < n; k++)
                            {
                                if(k == i || k == j)
                                    continue;
                                if((car[i][0] != car[k][0]) && ((car[i][2] - car[k][2]) < 5.0 && (car[i][2] - car[k][2]) > -5.0))
                                {
                                    //printf("i:%d j:%d k:%d %lf %lf %lf vs %lf %lf %lf\n", i,j,k,car[i][0], car[i][1], car[i][2], car[k][0], car[k][1], car[k][2]);
                                    colide = 1;
                                    break;
                                }
                            }
                            if(colide == 1)
                                break;
                            else
                            {
                                if(car[i][0] == 0)
                                    car[i][0] = 1;
                                else
                                    car[i][0] = 0;
                                break;
                            }
                        }
                    }
                    if(colide == 1)
                        break;
                }
                if(colide == 1)
                    break;
            }
            cumt += mint;
            qsort(car, n, 3*sizeof(double), cmp);
#if 0
            for(i = 0; i < n; i++)
                printf("l:%lf s:%lf p:%lf\n", car[i][0], car[i][1], car[i][2]);
            printf("###################\n");
#endif
        }
#if 0
        for(i = 0; i < n; i++)
            printf("l:%lf s:%lf p:%lf\n", car[i][0], car[i][1], car[i][2]);
#endif
        if(mint == 999999999)
            printf("Case #%d: Possible\n",nc);
        else
            printf("Case #%d: %.05lf\n",nc,cumt+mint);
    }
}
