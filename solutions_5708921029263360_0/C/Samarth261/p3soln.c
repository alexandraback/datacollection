#include<stdio.h>

FILE *qf;
FILE *af;

int sets[10][10][10]={0};
int j;
int p;
int s;
int k;


int main()
{
    int ntc;
    int i;
    int jc,pc,sc;
    int jcc,pcc,scc;
    int n;
    int counter;//used in magic
    qf=fopen("question3.txt","r");
    af=fopen("answer3.txt","w");
    fscanf(qf,"%d",&ntc);

    for(i=1;i<=ntc;i++)
    {
        fscanf(qf,"%d%d%d%d",&j,&p,&s,&k);
        n=0;
        for(jc=0;jc<j;jc++)//setting to 1
        {
            for(pc=0;pc<p;pc++)
            {
                for(sc=0;sc<s;sc++)
                {
                    sets[jc][pc][sc]=1;
                }
            }
        }
        //printf("%d\n",k);
        fprintf(af,"Case #%d: ",i);
        if(k>=s)
        {
            n=j*p*s;
            //fprintf(af,"%d",(j*p*s));
        }

        else
        {
            for(jc=0;jc<j;jc++)
            {
                for(pc=0;pc<p;pc++)
                {
                    for(sc=0;sc<s;sc++)
                    {
                        if(sets[jc][pc][sc]==0)
                        {
                            continue;
                        }

                        counter=1;
                        for(scc=sc+1;scc<s;scc++)//fix j p
                        {

                            if(sets[jc][pc][scc]==1)
                            {
                                if(counter==k)
                                {
                                    sets[jc][pc][scc]=0;
                                }
                                else
                                {
                                    counter++;
                                }
                            }
                            //printf("%d\n",sets[jc][pc][scc]);
                        }

                        counter=1;
                        for(pcc=pc+1;pcc<p;pcc++)//fix j s
                        {
                            if(sets[jc][pcc][sc]==1)
                            {
                                if(counter==k)
                                {
                                    sets[jc][pcc][sc]=0;
                                }
                                else
                                {
                                    counter++;
                                }
                            }
                        }
                        counter=1;
                        for(jcc=jc+1;jcc<j;jcc++)//fix p s
                        {
                            if(sets[jcc][pc][sc]==1)
                            {
                                if(counter==k)
                                {
                                    sets[jcc][pc][sc]=0;
                                }
                                else
                                {
                                    counter++;
                                }
                            }
                        }
                    }
                }
            }
        }

        //counting n
        n=0;
        for(jc=0;jc<j;jc++)
        {
            for(pc=0;pc<p;pc++)
            {
                for(sc=0;sc<s;sc++)
                {
                    if(sets[jc][pc][sc]==1)
                    {
                        n++;
                    }
                //    printf("%d\n",sets[jc][pc][sc]);
                }
              //  printf("\n");
            }
            //printf("\n-------------\n");
        }

        fprintf(af,"%d",n);

        for(jc=0;jc<j;jc++)//printing
        {
            for(pc=0;pc<p;pc++)
            {
                for(sc=0;sc<s;sc++)
                {
                    if(sets[jc][pc][sc]==1)
                    {
                        fprintf(af,"\n%d %d %d",(jc+1),(pc+1),(sc+1));
                    }
                }
            }
        }
        fprintf(af,"\n");
    }
}
