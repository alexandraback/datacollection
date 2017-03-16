#include<iostream>
#include<cstdio>
#define SIZE 10009
#define MAX(a,b) (a>b?a:b)

using namespace std;

int n,emax,arr[SIZE];
int table[6][11];

int myfunc(int r,int e,int num)
{
    if(num==n)
    {
        return(0);
    }

    if(e==0)
    return(r,r,num+1);

    if(table[e][num]!=0)
    return(table[e][num]);

    int i,ret=0,val;
    for(i=0;i<=e;i++)
    {
        if(e-i+r>emax)
        val=emax;
        else
        val=e-i+r;
        ret=MAX(ret,arr[num]*i+myfunc(r,val,num+1));
    }
    table[e][num]=ret;
    return(ret);
}

int main()
{
    FILE *fin=fopen("B-small-attempt3.in","r");
    FILE *fout=fopen("hehe12.txt","w");
    int t,i,j,e,r,x;
    int ans;
    fscanf(fin,"%d",&t);
    for(x=1;x<=t;x++)
    {
        fscanf(fin,"%d%d%d",&e,&r,&n);
        emax=e;

        for(i=0;i<n;i++)
        {
            fscanf(fin,"%d",&arr[i]);
        }
        for(i=0;i<6;i++)
        for(j=0;j<11;j++)
        table[i][j]=0;
        ans=0;
       ans=myfunc(r,e,0);
        fprintf(fout,"Case #%d: %d\n",x,ans);
    }
    return(0);
}
