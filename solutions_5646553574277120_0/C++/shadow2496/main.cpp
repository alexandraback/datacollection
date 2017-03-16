#include<stdio.h>

int T;
int C,D,V;

int Num[10];
bool Numc[110];

bool Check[110];
bool Copy[110];
int Rest;

int Max;
int Print;
int Count;

int copy_COPY()
{
    int i;
    for(i=1;i<=V;i++){
        if(Copy[i]==false) continue;

        Check[i]=true;
        Copy[i]=false;
    }
    return 0;
}

int reset_CHECK()
{
    int i;
    for(i=1;i<=V;i++){
        Check[i]=false;
    }

    Check[0]=true;
    return 0;
}

int reset_NUMC()
{
    int i;
    for(i=1;i<=V;i++){
        Numc[i]=false;
    }
    return 0;
}

int Output(int c)
{
    printf("Case #%d: %d\n",c,Count);
    return 0;
}

int Process()
{
    reset_CHECK();
    Count=0;
    Rest=V;

    int i,j;
    for(i=1;i<=D;i++){
        for(j=0;j<=V-Num[i];j++){
            if(Check[j]==false) continue;
            if(Check[j+Num[i]]==true) continue;

            Copy[j+Num[i]]=true;
            Rest--;
        }

        copy_COPY();
   }


    int a;
    while(Rest!=0){
        Count++;
        Max=0;

        for(i=1;i<=V;i++){
            if(Numc[i]==true) continue;

            a=0;

            for(j=i;j<=V;j++){
                if(Check[j]==true) continue;
                if(Check[j-i]==false) continue;

                a++;
            }

            if(a>Max){
                Max=a;
                Print=i;
            }
        }

        for(i=Print;i<=V;i++){
            if(Check[i]==true) continue;
            if(Check[i-Print]==false) continue;

            Copy[i]=true;
            Rest--;
        }

        copy_COPY();
    }
    return 0;
}

int Input()
{
    scanf("%d %d %d",&C,&D,&V);

    reset_NUMC();

    int i;
    for(i=1;i<=D;i++){
        scanf("%d",&Num[i]);

        Numc[Num[i]]=true;
    }
    return 0;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);

    scanf("%d",&T);

    int i;
    for(i=1;i<=T;i++){
        Input();
        Process();
        Output(i);
    }
}
