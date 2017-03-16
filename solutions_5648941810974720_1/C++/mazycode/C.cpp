#include<stdio.h>
#include<string.h>
int p[10];
int x[256];
char s[100000];
void doit()
{
    for(int i=0;i<10;i++)p[i]=0;
    for(int i=0;i<256;i++)x[i]=0;
    scanf("%s",s);
    int n = strlen(s);
    for(int i=0;i<n;i++)
    {
        x[s[i]]++;
    }
    p[0] = x['Z'];
    x['Z'] = 0;
    x['E'] -= p[0];
    x['R'] -= p[0];
    x['O'] -= p[0];

    p[6] = x['X'];
    x['X'] = 0;
    x['I'] -= p[6];
    x['S'] -= p[6];

    p[8] = x['G'];
    x['G'] = 0;
    x['E'] -= p[8];
    x['I'] -= p[8];
    x['H'] -= p[8];
    x['T'] -= p[8];

    p[4] = x['U'];
    x['U'] = 0;
    x['F'] -= p[4];
    x['O'] -= p[4];
    x['R'] -= p[4];

    p[3] = x['R'];
    x['R'] = 0;
    x['T'] -= p[3];
    x['H'] -= p[3];
    x['E'] -= 2*p[3];

    p[5] = x['F'];
    x['F'] = 0;
    x['I'] -= p[5];
    x['V'] -= p[5];
    x['E'] -= p[5];

    p[7] = x['V'];
    x['V'] = 0;
    x['S'] -= p[7];
    x['N'] -= p[7];
    x['E'] -= 2*p[7];

    p[2] = x['W'];
    x['W'] = 0;
    x['T'] -= p[2];
    x['O'] -= p[2];

    p[1] = x['O'];
    x['O'] = 0;
    x['E'] -= p[1];
    x['N'] -= p[1];
    p[9] = x['I'];
    for(int i=0;i<10;i++)
        for(int j=0;j<p[i];j++)
        printf("%d",i);
    printf("\n");
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("Case #%d: ",i+1);
        doit();
    }
}
