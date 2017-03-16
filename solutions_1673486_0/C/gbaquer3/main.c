#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *input,*output;
    int x,y,z,k,T=0,N=0,K=0,test,result;
    int A,B;
    float strokes[5];

    float percentage[3];
    float correct, incorrect;
    float smallest;
    output=fopen("output.in", "w");
    input=fopen("input.in", "r");
    fscanf(input,"%i",&T);
    for(test=1;test<=T;test++)
    {
        for(x=0;x<5;x++)
    {
        strokes[x]=0;
    }
    for(x=0;x<3;x++)
    {
        percentage[x]=1;
    }
        fscanf(input,"%i",&A);
        fscanf(input,"%i",&B);
        for(y=0;y<A;y++)
        {
            fscanf(input,"%f",&percentage[y]);
        }

        y=B-A+1;
        x=B-A+B+2;
        correct=percentage[0]*percentage[1]*percentage[2];
        incorrect=1-correct;
        strokes[0]=y*correct+x*incorrect;
        strokes[1]=B+2;

        y=B-A+1+2;
        x=4+B+B-A;
        correct=percentage[0]*percentage[1];
        incorrect=1-correct;
        strokes[2]=y*correct+x*incorrect;

        y=B-A+1+4;
        x=6+B+B-A;
        correct=percentage[0];
        incorrect=1-correct;
        strokes[3]=y*correct+x*incorrect;

        y=B-A+1+6;
        x=8+B+B-A;
        correct=1;
        incorrect=0;
        strokes[4]=y*correct+x*incorrect;
        smallest=strokes[0];

        for(x=1;x<5;x++)
        {
            if(strokes[x]<smallest&& strokes[x]!=0)
            {
                smallest=strokes[x];
            }
        }
        fprintf(output,"Case #%i: %6f",test,smallest);
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

