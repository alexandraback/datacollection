#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n;
int fin[30],mij[30],perm[20],f[30];
char c[20][4],aux[110];

void init()
{
    memset(fin,0,sizeof(fin));
    memset(mij,0,sizeof(mij));
    memset(c,0,sizeof(c));
}

int verific()
{
    int i,ok=1;
    memset(f,0,sizeof(f));

    for(i=1;i<=n;++i)
    {
        if(c[perm[i]][0]!=c[perm[i-1]][1])
            ++f[c[perm[i]][0]-'a'];

        if(c[perm[i]][1]!=c[perm[i]][0])
            ++f[c[perm[i]][1]-'a'];
    }
    for(i=0;i<=26;++i)
        if(f[i]>1)
            ok=0;

    return ok;
}

int main()
{
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int test,t,i,j,lim,ok,sol;

    scanf("%d",&test);
    for(t=1;t<=test;++t)
    {
        ok=1;sol=0;
        init();

        scanf("%d\n",&n);
        for(i=1;i<=n;++i)
        {
            scanf("%s",&aux);
            lim=strlen(aux)-1;
            c[i][0]=aux[0];
            c[i][1]=aux[lim];
            fin[aux[0]-'a']=fin[aux[lim]-'a']=1;

            for(j=1;aux[j]==aux[j-1];++j);
            for(--lim;lim>=0&&aux[lim]==aux[lim+1];--lim);
            if(j<=lim&&c[i][0]==c[i][1])
                ok=0;
            for(;j<=lim;++j)
            {
                ++mij[aux[j]-'a'];
                while(aux[j+1]==aux[j])++j;
            }
            perm[i]=i;
        }

        for(i=0;i<=26;++i)
            if((fin[i]&&mij[i])||mij[i]>1)ok=0;

        if(ok)
        {
            do
            {
                sol+=verific();
            }while(next_permutation(perm+1,perm+1+n));
        }

        printf("Case #%d: %d\n",t,sol);
    }

    return 0;
}
