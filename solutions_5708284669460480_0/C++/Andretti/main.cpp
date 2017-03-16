#include <stdio.h>
#include <algorithm>
#define maxn 10
#define eps 0.000001
using namespace std;

int T,K,L,S;
int nr,Max;

char key[maxn],target[maxn];
char dif[maxn],cnt[maxn];
int f[maxn],ind[30];
double sol;

int check()
{
    int nrc=0,ok;
    for(int i=1;i<=S-L+1;i++)
    {
        ok=1;
        for(int j=1;j<=L;j++)
         if(cnt[i+j-1]!=target[j]) ok=0;

        if(ok) nrc++;
    }
    return nrc;
}

void back(int k,double p)
{
   // printf("%d %f\n",k,p);
    if(k>S)
    {
        int aux=check();
        //printf("%d ",aux);
        if(aux)
        {
            Max=max(Max,aux);
            sol=sol+aux*p;
        }
        return;
    }

    for(int i=1;i<=nr;i++)
    {
        cnt[k]=dif[i];
        back(k+1,p*f[i]/K);
    }
}

void solve()
{
    for(int i=0;i<=25;i++) ind[i]=0;

    nr=0;
    for(int i=1;i<=K;i++)
    {
        if(ind[key[i]-'A']==0) ind[key[i]-'A']=++nr,f[nr]=1,dif[nr]=key[i];
        else f[ ind[key[i]-'A'] ]++;
    }


    sol=0; Max=0;
    back(1,1);
}

int main()
{

    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        scanf("%d %d %d\n",&K,&L,&S);

        scanf("%s\n",key+1);
        scanf("%s\n",target+1);

        solve();
        printf("Case #%d: %f\n",it,Max-sol);
    }

    return 0;
}
