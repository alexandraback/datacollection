#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>

 void calculate(int X,int Y,char S[501])
 {
    int i,j,k;
    int cx=0,cy=0,cn=1,fl=0,cd,d,cp=0;
    while(fl==0)
    {
       // printf("\nX - %d cx - %d %d",X,cx,cn);
       d = X - cx;
       if(d>0)
       {
         //  printf("\nabs(next) %d, abs %d",abs(X-cx+cn),abs(X-cx));
           if(abs(X-(cx+cn))<abs(X-cx))
           {
                S[cp++]='E';
                cx = cn + cx;
                cn++;
           //     printf("\ncx %d",cx);
           }
           else
           {
               fl=1;
           }
       }
       else
       {
           if(abs(X-(cx-cn))<abs(X-cx))
           {
                S[cp++]='W';
                cx = cx  - cn;
                cn++;
           }
           else
           {
               fl=1;
           }
       }
    }

    fl=0;

    while(fl==0)
    {
       d = Y - cy;
       if(d>0)
       {
           if(abs(Y-(cy+cn))<abs(Y-cy))
           {
                S[cp++]='N';
                cy = cn + cy;
                cn++;

           }
           else
           {
               fl=1;
           }
       }
       else
       {
           if(abs(Y-(cy-cn))<abs(Y-cy))
           {
                S[cp++]='S';
                cy = cy - cn;
                cn++;
           }
           else
           {
               fl=1;
           }
       }
    }

    d = X - cx;
    //printf("\nX - %d cx -  %d",X,cx);
    if(d>0)
    {
        for(i=0;i<d;i++)
        {
            S[cp++]='W';
            S[cp++]='E';
        }
    }
    else
    {
        for(i=0;i<abs(d);i++)
        {
            S[cp++]='E';
            S[cp++]='W';
        }
    }

     d = Y - cy;
    if(d>0)
    {
        for(i=0;i<d;i++)
        {
            S[cp++]='S';
            S[cp++]='N';
        }
    }
    else
    {
        for(i=0;i<abs(d);i++)
        {
            S[cp++]='N';
            S[cp++]='S';
        }
    }
    S[cp]='\0';
 }

void clear(char x[501])
{
    int i;
    for(i=0;i<101;i++)
    x[i]='\0';
}


void solve(int T,FILE *fp1)
{
    char S[501];
    int i;
    int X,Y;
    FILE *fp2;
    fp2 = fopen("p.out","w");
    //int S = 0,N = 0;

    for(i=0;i<T;i++)
    {
        clear (S);
        fscanf(fp1,"%d %d ",&X,&Y);
        fprintf(fp2,"Case #%d: ",i+1);
        calculate(X,Y,S);
        fprintf(fp2,"%s\n",S);
        //printf("H = %d, W = %d\n",H,W);
    }
}




int main()
{
    FILE *fp1;
    int T = 0;
    fp1 = fopen("A-small-practice.in","r");
    fscanf(fp1,"%d",&T);
    solve(T,fp1);
    printf("T = %d\n",T);
    return 0;
}

