#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

const char tab[6]=" 1ijk";
char s[1<<20];
int v[1<<20];
long long m;
int n,p;

int getsign(int x)
{
    return x/labs(x);
}

int trans(int x,int y)
{
    if((labs(x)==1)||(labs(y)==1))
    {
        return x*y;
    }
    else if(labs(x)==labs(y))
    {
        return -getsign(x)*getsign(y);
    }
    else if((labs(x)==2)&&(labs(y)==3))
    {
        return +getsign(x)*getsign(y)*4;
    }
    else if((labs(x)==3)&&(labs(y)==4))
    {
        return +getsign(x)*getsign(y)*2;
    }
    else if((labs(x)==4)&&(labs(y)==2))
    {
        return +getsign(x)*getsign(y)*3;
    }
    else if((labs(x)==2)&&(labs(y)==4))
    {
        return -getsign(x)*getsign(y)*3;
    }
    else if((labs(x)==4)&&(labs(y)==3))
    {
        return -getsign(x)*getsign(y)*2;
    }
    else if((labs(x)==3)&&(labs(y)==2))
    {
        return -getsign(x)*getsign(y)*4;
    }
}

int check()
{
    int i,k;
    k=1;
    for(i=0;i<n;i++)
    {
        k=trans(k,v[i]);
    }
    if(k==1)
    {
        return 0;
    }
    else if(k==-1)
    {
        if(m%2==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(m%4==2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int check(int x)
{
    int k;
    k=1;
    while(p<n)
    {
        k=trans(k,v[p]);
        p++;
        if((x!=1)&&(k==x))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int c,t,i;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d %I64d",&n,&m);
        scanf("%s",s);
        for(i=1;i<64;i++)
        {
            strncpy(s+i*n,s,n);
        }
        n=n*min(m,64LL);
        for(i=0;i<n;i++)
        {
            v[i]=strchr(tab,s[i])-tab;
        }
        printf("Case #%d: ",c+1);
        n=n/min(m,64LL);
        if(check()==0)
        {
            printf("NO\n");
            continue;
        }
        n=n*min(m,64LL);
        p=0;
        if((check(2)==1)&&(check(3)==1)&&(check(4)==1))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
