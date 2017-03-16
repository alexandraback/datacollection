#include<stdio.h>
#include<string.h>

int main()
{

    int cas;
    int A,B;
    int res;
    char list[10],dest[10];
    int check[10];
    int checkNum;
    scanf("%d",&cas);
    for(int i=1;i<=cas;++i)
    {
        scanf("%d %d",&A,&B);
        res=0;
        sprintf(dest,"%d",B);
        for(int i=A;i<=B;++i)
        {
            sprintf(list,"%d",i);
            checkNum=0;
            for(int j=1;j<strlen(list);++j)
            {
                int flagB = 0;
                int flagS = 0;
                int num=0;
                int curID,lastID;
                for(int k=0;k<strlen(list);++k)
                {
                    curID=(k+j)%strlen(list);
                    lastID=k;
                    //printf("%c %c\n",list[curID],list[lastID]);
                    if(list[curID]>list[lastID] && flagB==0)
                        flagB=1;
                    else if(list[curID]<list[lastID] && flagB==0)
                        flagB=-1;
                    if(list[curID]>dest[lastID] && flagS==0)
                        flagS=1;
                    else if(list[curID]<dest[lastID] && flagS==0)
                        flagS=-1;
                    num=num*10+(list[curID]-'0');
                    if(flagB==-1 || flagS==1)
                        break;
                }
                if(flagB==1 && flagS!=1)
                {
                    bool flagNew=true;
                    for(int k=0;k<checkNum;++k)
                    {
                        if(check[k]==num)
                            flagNew=false;
                    }
                    if(flagNew)
                    {
                        check[checkNum++]=num;
                        res++;
                    }
                    //printf("%s %d %d\n",list,flagB,flagS);
                }

            }
        }

        printf("Case #%d: %d",i,res);
        if(i<cas)
            printf("\n");
    }
    return 0;
}
