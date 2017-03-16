#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

int mg[5][5];

void G()
{
    mg[1][1]=1;
    mg[1][2]=2;
    mg[1][3]=3;
    mg[1][4]=4;
    mg[2][1]=2;
    mg[2][2]=-1;
    mg[2][3]=4;
    mg[2][4]=-3;
    mg[3][1]=3;
    mg[3][2]=-4;
    mg[3][3]=-1;
    mg[3][4]=2;
    mg[4][1]=4;
    mg[4][2]=3;
    mg[4][3]=-2;
    mg[4][4]=-1;
    return;
}

int multi(int a,int b)
{
    if (a<0 && b>0)
    return -mg[-a][b];
    if (a>0 && b<0)
    return -mg[a][-b];
    if (a<0 && b<0)
    return mg[-a][-b];

    return mg[a][b];
}

char str[10011];
bool TFO[10011][10];
int OFFSET=4;

int I(char ch)
{
    if (ch=='i')
    return 2;
    else if (ch=='j')
    return 3;
    else
    return 4;
}

int FastPow(int x,Int p)
{
    if (p==1)
    return x;

    int ans=FastPow(x,p/2);

    ans=multi(ans,ans);

    if (p%2==1)
    ans=multi(ans,x);

    return ans;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-output.txt","w",stdout);

    Int T,L,X;
    int test;
    int i;
    int Num,Len;
    int LeftLen,RightLen;
    bool done;

    G();

    scanf("%lld",&T);

    for (test=1;test<=T;test++)
    {
        scanf("%lld %lld",&L,&X);

        scanf("%s",str+1);

        Num=1;

        for (i=1;i<=L;i++)
        {
            Num=multi(Num,I(str[i]));
        }

        Num=FastPow(Num,X);

        if (Num!=-1)
        {
            printf("Case #%d: NO\n",test);
            continue;
        }

        LeftLen=-1;
        RightLen=-1;

        ///

        memset(TFO,false,sizeof(TFO));

        Num=1;
        Len=0;
        done=false;

        while(!done)
        {
            for (i=1;i<=L;i++)
            {
                Len++;
                Num=multi(Num,I(str[i]));

                if (Num==2)
                {
                    done=true;
                    break;
                }

                if (TFO[i][Num+OFFSET])
                {
                    Len=-1;
                    done=true;
                    break;
                }
                else
                TFO[i][Num+OFFSET]=true;
            }
        }

        if (Len==-1)
        {
            printf("Case #%d: NO\n",test);
            continue;
        }

        LeftLen=Len;

        ///

        memset(TFO,false,sizeof(TFO));

        Num=1;
        Len=0;
        done=false;

        while(!done)
        {
            for (i=L;i>=1;i--)
            {
                Len++;
                Num=multi(I(str[i]),Num);

                if (Num==4)
                {
                    done=true;
                    break;
                }

                if (TFO[i][Num+OFFSET])
                {
                    Len=-1;
                    done=true;
                    break;
                }
                else
                TFO[i][Num+OFFSET]=true;
            }
        }

        if (Len==-1)
        {
            printf("Case #%d: NO\n",test);
            continue;
        }

        RightLen=Len;

        ///

        if ((Int)LeftLen+(Int)RightLen>=L*X)
        {
            printf("Case #%d: NO\n",test);
            continue;
        }

        printf("Case #%d: YES\n",test);
    }

    return 0;
}
