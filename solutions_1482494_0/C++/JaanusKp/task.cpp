#include<stdio.h>

int level[1000][2];
int levels;
int completed[1000];
int completedCount;
int stars;
int bestResult;


void clearValues()
{
    bestResult=99999999;
    stars=0;
    for(int x=0; x<levels; x++)
        completed[x]=0;
}

int isCompleted()
{
    if(completedCount == levels)
        return 1;
    return 0;
}

int solve(int depth)
{
    if(depth==bestResult)
        return 0;
    //printf("depth=%d; stars=%d;  completedCount=%d; bestResult=%d\n", depth, stars, completedCount, bestResult);
    int prevStars, prevCompleted, prevcompletedCount;

    for(int x=0; x<levels; x++)
    {
        prevStars=stars;
        prevCompleted=completed[x];
        prevcompletedCount=completedCount;

        if(stars>=level[x][1] && completed[x]!=2)
        {
            //2stars
            if(completed[x]==0)
            {
                stars+=2;
            }
            if(completed[x]==1)
            {
                stars++;
            }
            completed[x]=2;
            completedCount++;
        }else
        {
            if(stars>=level[x][0] && completed[x]==0)
            {
                stars++;
                completed[x]=1;
            }
        }

        if(isCompleted())
        {
            if(depth<bestResult)
                bestResult=depth;
        }else
        {
            if(prevStars != stars && depth+(levels-completedCount)<bestResult)
                solve(depth+1);
        }

        completed[x]=prevCompleted;
        stars=prevStars;
        completedCount=prevcompletedCount;
    }

    return bestResult;
}

int main()
{
    //variables
    FILE *fin;
    FILE *fout;
    int count, h, result;

    //open files
    fin=fopen("input.txt", "r");
    fout=fopen("output.txt", "w");

    //loop trough test cases
    fscanf(fin, "%d\n", &count);
    for(h=0; h<count; h++)
    {
        clearValues();

        //Read values
        fscanf(fin, "%d\n", &levels);
        for(int x=0; x<levels; x++)
        {
            fscanf(fin, "%d %d\n", &level[x][0], &level[x][1]);
        }

        solve(1);
        if(bestResult!=99999999)
            fprintf(fout, "Case #%d: %d\n", h+1, bestResult);
        else
            fprintf(fout, "Case #%d: Too Bad\n", h+1);

        printf("DONE: %d\n", h);
    }

    //close files
    fclose(fin);
    fclose(fout);
}
