#include<stdio.h>
#include<math.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int casesCount;
int N;
double points[200], X;

int main()
{
    FILE *fin;
    FILE *fout;

    fin=fopen(INPUT_FILE,"r");
    fout=fopen(OUTPUT_FILE,"w");

    fscanf(fin, "%d\n", &casesCount);

    for(int h=0; h<casesCount; h++)
    {
        fscanf(fin, "%d ", &N);

        X=0;
        for(int x=0; x<N; x++)
        {
            fscanf(fin, "%d ", &points[x]);
            X+=points[x];
        }

        fprintf(fout, "Case #%d:", h+1);
        printf("Case #%d\n", h+1);

        for(int x=0; x<N; x++)
        {

            double Plow=(points[x]/X);
            double Phigh=(points[x]/X)+1.0;
            double P;
            double total=0;
            double xxx;

            do
            {
                P=(Plow+Phigh)/2.0;
                total=0;

                for(int y=0; y<N; y++)
                {
                    if(P > (points[y]/X))
                        total+=P-(points[y]/X);
                }

                if(total > 1.0)
                {
                    Phigh=P;
                }else
                {
                    Plow=P;
                }
            }while(fabs(total-1.00000) > 0.0000001 && fabs(Phigh-Plow) > 0.0000001);


            fprintf(fout, " %lf", (P-(points[x]/X))*100);
        }

        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);
}
