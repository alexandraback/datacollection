#include <stdio.h>

int main(int argc, const char * argv[])
{
    int cases;
    FILE *fp;
    fp=fopen("/Users/IndianaJones/Downloads/D-small-attempt0.in", "r");
    FILE *fpout;
    fpout=fopen("/Users/IndianaJones/Downloads/output.txt", "w");
    fscanf(fp, "%d\n", &cases);
    for (int i;i<cases;i++)
    {
        int finalDeceitful = 0;
        int finalFair = 0;
        int noOfBlocks;
        fscanf(fp, "%d\n", &noOfBlocks);
        double NaomiBlocks[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        double KenBlocks[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
        for(int i = 0;i<noOfBlocks;i++)
        {
            fscanf(fp, "%lf", &NaomiBlocks[i]);
        }
        fscanf(fp, "\n");
        for(int i = 0;i<noOfBlocks;i++)
        {
            fscanf(fp, "%lf", &KenBlocks[i]);
        }
        fscanf(fp, "\n");
        double DeceitfulNaomiBlocks[10];
        double DeceitfulKenBlocks[10];
        double TrueNaomiBlocks[10];
        double TrueKenBlocks[10];
        for (int i = 0; i < 10; i++)
        {
            DeceitfulNaomiBlocks [i] = NaomiBlocks[i];
        }
        for (int i = 0; i < 10; i++)
        {
            DeceitfulKenBlocks [i] = KenBlocks[i];
        }
        for (int i = 0; i < 10; i++)
        {
            TrueNaomiBlocks [i] = NaomiBlocks[i];
        }
        for (int i = 0; i < 10; i++)
        {
            TrueKenBlocks [i] = KenBlocks[i];
        }
        for(int i = 0;i<noOfBlocks;i++)
        {
            int LowNaomiNumber = 0;
            int LowKenNumber = 0;
            int HighNaomiNumber = 0;
            int HighKenNumber = 0;
            for (int ii = 0;ii<noOfBlocks;ii++)
            {
                if(DeceitfulNaomiBlocks[LowNaomiNumber] == -1)
                {
                    LowNaomiNumber = ii;
                }
                else if(DeceitfulNaomiBlocks[LowNaomiNumber]>DeceitfulNaomiBlocks[ii] && DeceitfulNaomiBlocks[ii] != -1)
                {
                    LowNaomiNumber=ii;
                }
                if(DeceitfulNaomiBlocks[HighNaomiNumber] == -1)
                {
                    HighNaomiNumber = ii;
                }
                else if(DeceitfulNaomiBlocks[HighNaomiNumber]<DeceitfulNaomiBlocks[ii] && DeceitfulNaomiBlocks[ii] != -1)
                {
                    HighNaomiNumber=ii;
                }
                if(DeceitfulKenBlocks[HighKenNumber] == -1)
                {
                    HighKenNumber = ii;
                }
                else if(DeceitfulKenBlocks[HighKenNumber]<DeceitfulKenBlocks[ii] && DeceitfulKenBlocks[ii] != -1)
                {
                    HighKenNumber=ii;
                }
                if(DeceitfulKenBlocks[LowKenNumber] == -1)
                {
                    LowKenNumber = ii;
                }
                else if(DeceitfulKenBlocks[LowKenNumber]>DeceitfulKenBlocks[ii] && DeceitfulKenBlocks[ii] != -1)
                {
                    LowKenNumber=ii;
                }
            }
            if(DeceitfulNaomiBlocks[LowNaomiNumber]<DeceitfulKenBlocks[LowKenNumber])
            {
                DeceitfulNaomiBlocks[LowNaomiNumber]=-1;
                DeceitfulKenBlocks[HighKenNumber]=-1;
            }
            else if(DeceitfulNaomiBlocks[HighNaomiNumber]>DeceitfulKenBlocks[HighKenNumber])
            {
                finalDeceitful++;
                DeceitfulNaomiBlocks[HighNaomiNumber]=-1;
                DeceitfulKenBlocks[HighKenNumber]=-1;
            }
            else
            {
                DeceitfulNaomiBlocks[LowNaomiNumber]=-1;
                DeceitfulKenBlocks[HighKenNumber]=-1;
            }
        }
        for(int i = 0;i<noOfBlocks;i++)
        {
            int LowNaomiNumber = 0;
            int LowKenNumber = 0;
            int HighNaomiNumber = 0;
            int HighKenNumber = 0;
            for (int ii = 0;ii<noOfBlocks;ii++)
            {
                if(TrueNaomiBlocks[LowNaomiNumber] == -1)
                {
                    LowNaomiNumber = ii;
                }
                else if(TrueNaomiBlocks[LowNaomiNumber]>TrueNaomiBlocks[ii] && TrueNaomiBlocks[ii] != -1)
                {
                    LowNaomiNumber=ii;
                }
                if(TrueNaomiBlocks[HighNaomiNumber] == -1)
                {
                    HighNaomiNumber = ii;
                }
                else if(TrueNaomiBlocks[HighNaomiNumber]<TrueNaomiBlocks[ii] && TrueNaomiBlocks[ii] != -1)
                {
                    HighNaomiNumber=ii;
                }
                if(TrueKenBlocks[HighKenNumber] == -1)
                {
                    HighKenNumber = ii;
                }
                else if(TrueKenBlocks[HighKenNumber]<TrueKenBlocks[ii] && TrueKenBlocks[ii] != -1)
                {
                    HighKenNumber=ii;
                }
                if(TrueKenBlocks[LowKenNumber] == -1)
                {
                    LowKenNumber = ii;
                }
                else if(TrueKenBlocks[LowKenNumber]>TrueKenBlocks[ii] && TrueKenBlocks[ii] != -1)
                {
                    LowKenNumber=ii;
                }
            }
            if(TrueNaomiBlocks[HighNaomiNumber]>TrueKenBlocks[HighKenNumber])
            {
                finalFair++;
                TrueNaomiBlocks[HighNaomiNumber]=-1;
                TrueKenBlocks[LowKenNumber]=-1;
            }
            else if(TrueNaomiBlocks[HighNaomiNumber]<TrueKenBlocks[HighKenNumber])
            {
                TrueNaomiBlocks[HighNaomiNumber]=-1;
                TrueKenBlocks[HighKenNumber]=-1;
            }
        }
        fprintf(fpout, "Case #%d: %d %d\n",i+1,finalDeceitful,finalFair);
    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

