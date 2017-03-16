#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *input,*output;
    int x,y,z,k,T=0,N=0,K=0,test,result,level,stars,found,out,num1,num2,plays;
    int levels[3][1000];
    output=fopen("output.in", "w");
    input=fopen("input.in", "r");
    fscanf(input,"%i",&T);
    for(test=1;test<=T;test++)
    {
        stars=0;
        plays=0;
        for(x=0;x<3;x++)
        {
            for(y=0;y<1000;y++)
            {
                levels[x][y]=-1;
            }
        }
        fscanf(input,"%i",&N);
        for(x=0;x<N;x++)
        {
            fscanf(input,"%i",&num1);
            fscanf(input,"%i",&num2);
            out=0;
            for(y=0;y<=x&&out==0;y++)
            {
                if(num2>levels[1][y])
                {
                    for(z=N-1;z>y;z--)
                    {
                        levels[1][z]=levels[1][z-1];
                        levels[0][z]=levels[0][z-1];
                    }
                    levels[1][y]=num2;
                    levels[0][y]=num1;
                    out=1;
                }
            }
        }
        /*Empieza el juego*/
        Evaluate2:
        for(x=0;x<N;x++)
        {
            if((stars>=levels[1][x])&&(levels[2][x]!=1))
            {
                if(levels[2][x]==-1)
                {
                    stars=stars+2;
                }
                if(levels[2][x]==0)
                {
                    stars=stars+1;
                }
                levels[2][x]=1;
                plays++;
                goto Evaluate2;
            }
        }
        Evaluate1:
        for(x=0;x<N;x++)
        {
            if(stars>=levels[0][x]&&levels[2][x]==-1)
            {
                stars++;
                plays++;
                levels[2][x]=0;
                goto Evaluate2;
            }
        }
        if(stars==N*2)
        {
            fprintf(output,"Case #%i: %i",test,plays);
        }
        else
        {
            fprintf(output,"Case #%i: %c%c%c %c%c%c",test,'T','o','o','B','a','d');
        }
        if(test!=T)
        {
            fprintf(output,"\n");
        }
    }
    fclose(input);
    fclose(output);
    printf("DONE");
    return 0;
}
