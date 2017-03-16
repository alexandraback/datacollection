#include <cstdio>

#define DATASET "A-small-attempt0"

int main()
{
    FILE* fin=fopen(DATASET ".in","r");
    FILE* fout=fopen(DATASET ".out","w");

    int numCases;
    fscanf(fin,"%d",&numCases);
    for(int t=0;t<numCases;++t)
    {
        int charsTyped,numChars;
        fscanf(fin,"%d %d",&charsTyped,&numChars);

#define MAX 100000
        double probs[MAX]; // prob of typing all correctly up to character[i]
        probs[0]=1;
        for(int i=0;i<charsTyped;++i)
        {
            double probCorrect;
            fscanf(fin,"%lf",&probCorrect);

            probs[i+1]=probs[i]*probCorrect;
        }

        double minExpected=1 + numChars + 1; // E[give up] = enter + all + enter
        printf("E[give up]= %.6lf\n",minExpected);

        for(int i=0;i<=charsTyped;++i) // backspace i times
        {
            /*double expected=
                // E[correct up to (charsTyped-i)] = i backspaces + i retypes + remaining + enter
                probs[charsTyped-i]*(2*i + numChars-charsTyped + 1)
                // E[wrong before (charsTyped-i)] = i backspaces + i retypes + remaining + enter + all + enter
                +(1-probs[charsTyped-i])*(2*i + numChars-charsTyped + 1 + numChars + 1);
                ;*/
            double expected=
                // Always: i BSPs + i retypes + remaining + enter
                2*i + numChars-charsTyped + 1
                // If incorrect: + all + enter
                +(1-probs[charsTyped-i])*(numChars+1);

            printf("E[%d bsp]= %.6lf\n",i,expected);
            if(expected<minExpected) minExpected=expected;
        }

        fprintf(fout,"Case #%d: %.6lf\n",t+1,minExpected);
    }

    fclose(fin);
    fclose(fout);
}