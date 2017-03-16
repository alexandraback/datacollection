#include <stdio.h>

#define MAX 110

int v[MAX];
int n;

char sol[MAX*11];
int len;

char s[MAX][MAX];
int ls[MAX];


int valid()
{
    int i;
    int oc[256];
    char prev=0;
    for(i=0; i<256; ++i) oc[i]=0;
    for(i=0; i<len; ++i)
    {
        if(sol[i] != prev)
        {
            if(oc[sol[i]])
                break;
            prev=sol[i];
            oc[sol[i]]=1;
        }
    }
    return i>=len;
}

void cptosol(int now)
{
    for(int i=0; i<ls[now]; ++i)
        sol[len+i]=s[now][i];
    len+=ls[now];
}

int dfs(int now)
{
    int i;
    int resp=0;
    int ov=1;

    v[now] = 1;
    cptosol(now);
    for(i=0; i<n; ++i)
        if(!v[i])
        {
            ov=0;
            resp+=dfs(i);
        }
    if(ov && valid())
        resp=1;
    len -= ls[now];
    v[now]=0;
    return resp;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ccnt=1; ccnt<=t; ++ccnt)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf(" ");
            scanf("%s%n",s[i],&ls[i]);
        }
        int resp=0;

        for(int i=0; i<MAX; ++i)
            v[i]=0;
        len=0;

        for(int i=0; i<n; ++i)
            resp+=dfs(i);

        printf("Case #%d: %d\n", ccnt, resp);
    }
    return 0;
}



