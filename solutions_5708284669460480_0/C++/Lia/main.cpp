#include<stdio.h>
long long sol[20], i, put, xp, x, nrap, baz=30, nrmax, nrsol, sum;
char v[20], p[20];
int t, ii, l, s, k;
double rez, nrmaxd, nrsold, sumd;

void numarare()
{
    x=0;    nrap=0;
    for (int i=1;i<=l;i++)
        x=x*baz+sol[i];
    nrap+=(x==xp);
    for (i=l+1;i<=s;i++)
    {
        x=(x-(sol[i-l])*put)*baz+sol[i];
        nrap+=(x==xp);
    }
    if (nrap>nrmax)
        nrmax=nrap;
    sum+=nrap;
    nrsol++;
}

void gen(int poz)
{
    if (poz==s+1)
        numarare();
    else
    {
        for (int i=0;i<k;i++)
        {
            sol[poz]=v[i]-'A';
            gen(poz+1);
        }
    }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%ld %ld %ld",&k,&l,&s);
        gets(v);gets(v);
        gets(p);
        put=1;
        for (i=1;i<=l-1;i++)
            put=put*baz;
        xp=0;
        for (int i=1;i<=l;i++)
            xp=xp*baz+p[i-1]-'A';
        nrmax=sum=nrsol=0;
        gen(1);
        sumd=sum;   nrsold=nrsol;   nrmaxd=nrmax;
        rez=(nrmaxd-sumd/nrsold);
        printf("Case #%ld: %.7lf\n",ii,rez);
    }
    return 0;
}
