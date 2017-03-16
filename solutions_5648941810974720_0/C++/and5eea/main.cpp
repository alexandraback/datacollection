#include <cstdio>
#include <cstring>
using namespace std;
int l,i,n,a[12],v[200],nrt,j;
char s[3000];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d\n",&nrt);
    for(l=1;l<=nrt;l++)
    {
        gets(s);
        n=strlen(s);
        for(i='A';i<='Z';i++)
            v[i]=0;
        for(i=0;i<=9;i++)
            a[i]=0;
        for(i=0;i<n;i++)
            v[s[i]]++;
        if(v['Z']>0)
        {
            a[0]=v['Z'];
            v['E'] -=v['Z'];
            v['R'] -=v['Z'];
            v['O'] -=v['Z'];
            v['Z']=0;
        }
        if(v['W']>0)
        {
            a[2]=v['W'];
            v['T'] -=v['W'];
            v['O'] -=v['W'];
            v['W']=0;
        }
        if(v['G']>0)
        {
            a[8]=v['G'];
            v['E'] -=v['G'];
            v['I'] -=v['G'];
            v['H'] -=v['G'];
            v['T'] -=v['G'];
            v['G']=0;
        }
        if(v['X']>0)
        {
            a[6]=v['X'];
            v['S'] -=v['X'];
            v['I'] -=v['X'];
            v['X']=0;
        }
        if(v['S']>0)
        {
            a[7]=v['S'];
            v['E'] -=v['S'];
            v['V'] -=v['S'];
            v['E'] -=v['S'];
            v['N'] -=v['S'];
            v['S']=0;
        }
        if(v['H']>0)
        {
            a[3]=v['H'];
            v['T'] -=v['H'];
            v['R'] -=v['H'];
            v['E'] -=v['H'];
            v['E'] -=v['H'];
            v['H']=0;
        }
        if(v['U']>0)
        {
            a[4]=v['U'];
            v['F'] -=v['U'];
            v['O'] -=v['U'];
            v['R'] -=v['U'];
            v['U']=0;
        }
        if(v['O']>0)
        {
            a[1]=v['O'];
            v['N'] -=v['O'];
            v['E'] -=v['O'];
            v['O']=0;
        }
        if(v['N']>0)
        {
            a[9]=v['N']/2;
            v['I'] -=v['N']/2;
            v['E'] -=v['N']/2;
            v['N']=0;
        }
        if(v['V']>0)
        {
            a[5]=v['V'];
            v['I'] -=v['V'];
            v['F'] -=v['V'];
            v['E'] -=v['V'];
            v['V']=0;
        }
        printf("Case #%d: ",l);
        for(i=0;i<=9;i++)
        {
            for(j=1;j<=a[i];j++)
                printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}
