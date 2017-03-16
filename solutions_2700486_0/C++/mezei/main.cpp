#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int n;
int x, y;
double sol;

double c(int m, int h);

int main()
{
    FILE* reader = fopen("B.in", "r");
    FILE* printer = fopen("B.out", "w");

    fscanf(reader, "%d", &T);

    //printf("%d", T);
    for(int T_id=1; T_id<=T; T_id++)
    {
        fscanf(reader, "%d %d %d", &n, &x, &y);
        int k=1;
        for(int i=0; i<=n; i++)
        {
            if(2*i*i-i<=n)
                k=i;
            else
                break;
        }

        //printf("K: %d X+Y: %d M: %d \n", k, x+y, n-(2*k*k-k));


        if(x+y<=2*k-2)
            sol=1;
        else if(x+y>=2*5+2)
            sol=0;
        else
        {
            //printf("ELSE!");
            int h=y+1;
            int m=n-(2*k*k-k); //maradék
            if(x==0)
                sol=0;
            else if(2*k+h<=m)
                sol=1;
            else
            {
                //printf("M: %d\n", m);
                double tmp=0;
                for(int j=0; j<=y; j++) //ennyi megy jobbra
                {
                    if(m-j<=2*k) //beférnek balra a cuccosok
                    {
                        tmp+=c(m, j);
         //               printf("%d %d => %f\n", m, j, tmp);
                    }
                }
                sol=1-tmp;
            }
        }


        //printf("Case #%d: %f\n", T_id, sol);
        fprintf(printer, "Case #%d: %llf\n", T_id, sol);
    }



    fclose(printer);
}

double c(int m, int h)
{
    double re=1;
    for(int j=1; j<=h; j++)
    {
        re=re*(m-j+1)/(j*2);
    }
    for(int j=h+1; j<=m; j++)
        re=re/2;

    //printf("%d %d %f ::", m, h, re);
    return re;
}

