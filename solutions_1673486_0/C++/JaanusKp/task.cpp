#include<stdio.h>

float characters[100000];
int charactersCount, typed;

float bestResult;


float getProb(int len)
{
    float prob=1.0;
    for(int h=0; h<len; h++)
    {
        prob=prob*characters[h];
    }
    return prob;
}

float calculate()
{
    float prob, newResult;

    //enter right away
    bestResult=2+charactersCount;

    //keep typing
    prob=getProb(typed);
    newResult=prob*(charactersCount-typed+1)+(1-prob)*(charactersCount-typed+1+charactersCount);

    if(newResult<bestResult)
        bestResult=newResult;


    //Backspaces
    for(int h=1; h<=typed; h++)
    {
        prob=getProb(typed-h);
        newResult=prob*(h*2+charactersCount-typed+1)+(1-prob)*(h*2+charactersCount-typed+1+charactersCount+1);
        if(newResult<bestResult)
            bestResult=newResult;
    }

    return bestResult;
}

int main()
{
    //variables
    FILE *fin;
    FILE *fout;
    int count, h;

    //open files
    fin=fopen("input.txt", "r");
    fout=fopen("output.txt", "w");

    //loop trough test cases
    fscanf(fin, "%d", &count);
    for(h=0; h<count; h++)
    {
        fscanf(fin, "%d %d\n", &typed, &charactersCount);
        for(int x=0; x<typed; x++)
        {
            fscanf(fin, "%f ", &characters[x]);
        }

        fprintf(fout, "Case #%d: %f\n", h+1, calculate());
    }

    //close files
    fclose(fin);
    fclose(fout);
}
