#include <stdio.h>
using namespace std;
#define nmax 10005
int i, j, smn['z']['z'], sm, t, ii, l, x, lx, poz, sm1, sm2, sm3, semn;
char a['z']['z'], rap['z']['z'], c1, c2, pr, s[nmax], v, pr1, pr2, pr3;
bool rez;

void init()
{
    a[1][1]=1;      a[1]['i']='i';      a[1]['j']='j';      a[1]['k']='k';
    a['i'][1]='i';  a['i']['i']=1;      a['i']['j']='k';    a['i']['k']='j';
    a['j'][1]='j';  a['j']['i']='k';    a['j']['j']=1;      a['j']['k']='i';
    a['k'][1]='k';  a['k']['i']='j';    a['k']['j']='i';    a['k']['k']=1;
    smn[1][1]=1;    smn[1]['i']=1;      smn[1]['j']=1;      smn[1]['k']=1;
    smn['i'][1]=1;  smn['i']['i']=-1;   smn['i']['j']=1;    smn['i']['k']=-1;
    smn['j'][1]=1;  smn['j']['i']=-1;   smn['j']['j']=-1;   smn['j']['k']=1;
    smn['k'][1]=1;  smn['k']['i']=1;    smn['k']['j']=-1;   smn['k']['k']=-1;

    for (c1=1;c1<='z';c1++)
        for (c2=1;c2<='z';c2++)
            if (a[c1][c2]!=0)
                rap[a[c1][c2]][c2]=c1;
    /*rap[1][1]=1;    rap[1]['i']=1;      rap[1]['j']=1;      rap[1]['k']=1;
    rap['i'][1]=1;  rap['i']['i']=-1;   rap['i']['j']=1;    rap['i']['k']=-1;
    rap['j'][1]=1;  rap['j']['i']=-1;   rap['j']['j']=-1;   rap['j']['k']=1;
    rap['k'][1]=1;  rap['k']['i']=1;    rap['k']['j']=-1;   rap['k']['k']=-1;*/

}

bool rezolvare()
{
    pr=sm=1;
    for (i=1;i<=l;i++)
    {
        sm*=smn[pr][s[i]];
        pr=a[pr][s[i]];
    }
  /*  for (i=1;i<=x;i++)
    {
        sm*=smn[pr][pr];
        pr=a[pr][pr];
    }
    if ((pr!=1) || (sm!=-1))
        return 0;*/
    int ok=0, pa, ps;
    lx=l*x;
    if (pr!=1)
    {
        if (x<2)
            return 0;
        if (x%2)
            return 0;
        if ((x/2)%2==0)
            return 0;
    }
    if ((pr==1) && (sm==1))
        return 0;
    if ((pr==1) && (sm==-1) && (x%2==0))
        return 0;
    if (x>15)
        x=15;
    poz=0;  pr=1;   semn=1;
    for (j=1;j<=x;j++)
        for (i=1;i<=l;i++)
        {
            v=a[pr][s[i]];
            semn=semn*smn[pr][s[i]];
            pr=v;
            if ((v=='i')&&(semn==1)&&(ok==0))
                ok=1;
            if ((v=='k')&&(semn==1)&&(ok==1))
            {
                ok=2;
            //    printf("AAAAA:   j=%ld l=%ld\n",j,l);
            //v[++poz]=s[i];
            }
        }
    return (ok==2);
    //return ((ok==2)&&(semn==-1)&&(v==1));
    //return (semn[lx]==-1)&&(v[lx]==1);
   /* for (i=1;i<lx;i++)
        for (j=i+1;j<lx;j++)
        {
            pr1=v[i];   sm1=semn[i];
            pr2=rap[v[j]][v[i]];    sm2=semn[j]/semn[i];
            pr3=rap[v[lx]][v[j]];   sm3=semn[lx]/semn[j];
            if ((pr1=='i')&&(pr2=='j')&&(pr3=='k'))
                if ((sm1==1) && (sm2==1) && (sm3==-1))
                    return 1;
        }*/
/*
    for (i=1;((i<=lx)&&(ok<2));i++)
    {

    }*/
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    init();
    while (t--)
    {
        ii++;
        scanf("%ld %ld",&l,&x);
        scanf("%s",s+1);
        rez=rezolvare();
        if (rez)
            printf("Case #%ld: YES\n",ii);
        else
            printf("Case #%ld: NO\n",ii);
    }
    return 0;
}
