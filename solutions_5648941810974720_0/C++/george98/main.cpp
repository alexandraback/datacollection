#include <cstdio>
#include <cstring>

using namespace std;

int v[100],sol[100];
char sir[2010];

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        scanf("\n%s",sir+1);
        int n=strlen(sir+1);
        for(int i=1;i<=n;i++) v[sir[i]]++;
        sol[0]=v['Z'];
        v['E']-=v['Z'];
        v['R']-=v['Z'];
        v['O']-=v['Z'];
        v['Z']=0;
        sol[2]=v['W'];
        v['T']-=v['W'];
        v['O']-=v['W'];
        v['W']=0;
        sol[4]=v['U'];
        v['F']-=v['U'];
        v['O']-=v['U'];
        v['R']-=v['U'];
        v['U']=0;
        sol[6]=v['X'];
        v['S']-=v['X'];
        v['I']-=v['X'];
        v['X']=0;
        sol[8]=v['G'];
        v['E']-=v['G'];
        v['I']-=v['G'];
        v['H']-=v['G'];
        v['T']-=v['G'];
        v['G']=0;
        sol[1]=v['O'];
        v['N']-=v['O'];
        v['E']-=v['O'];
        v['O']=0;
        sol[3]=v['T'];
        v['H']-=v['T'];
        v['R']-=v['T'];
        v['E']-=v['T'];
        v['E']-=v['T'];
        v['T']=0;
        sol[5]=v['F'];
        v['I']-=v['F'];
        v['V']-=v['F'];
        v['E']-=v['F'];
        v['F']=0;
        sol[7]=v['S'];
        v['E']-=v['S'];
        v['V']-=v['S'];
        v['E']-=v['S'];
        v['N']-=v['S'];
        v['S']=0;
        sol[9]=v['E'];
        v['N']-=v['E'];
        v['I']-=v['E'];
        v['N']-=v['E'];
        v['E']=0;
        printf("Case #%d: ",t);
        for(int i=0;i<=9;i++)
            for(int j=1;j<=sol[i];j++) printf("%d",i);
        printf("\n");
        for(int i=0;i<=9;i++) sol[i]=0;
        for(int i='A';i<='Z';i++) v[i]=0;
    }
    return 0;
}
