#include<stdio.h>
#include<string.h>
char s[2022];
int n;
int T;
int a[100];
int ans[20];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.txt","w",stdout);
    int i,j,k;
    int p,q,r;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%s",s);
    printf("Case #%d: ",ii);
    r = strlen(s);
    for(i=0;i<100;i++)a[i]=0;
    for(i=0;i<20;i++)ans[i]=0;
    for(i=0;i<r;i++)
    {
        a[s[i]-'A']++;
    }
    if(a['Z'-'A']!=0)
    {
        while(a['Z'-'A'] != 0)
        {
            ans[0]++;
            a['Z'-'A']--;
            a['E'-'A']--;
            a['R'-'A']--;
            a['O'-'A']--;
        }
    }
    if(a['X'-'A']!=0)
    {
        while(a['X'-'A'] != 0)
        {
            ans[6]++;
            a['S'-'A']--;
            a['I'-'A']--;
            a['X'-'A']--;
        }
    }
    if(a['G'-'A']!=0)
    {
        while(a['G'-'A'] != 0)
        {
            ans[8]++;
            a['E'-'A']--;
            a['I'-'A']--;
            a['G'-'A']--;
            a['H'-'A']--;
            a['T'-'A']--;
        }
    }
    if(a['U'-'A']!=0)
    {
        while(a['U'-'A'] != 0)
        {
            ans[4]++;
            a['F'-'A']--;
            a['O'-'A']--;
            a['U'-'A']--;
            a['R'-'A']--;
        }
    }
    if(a['F'-'A']!=0)
    {
        while(a['F'-'A'] != 0)
        {
            ans[5]++;
            a['F'-'A']--;
            a['I'-'A']--;
            a['V'-'A']--;
            a['E'-'A']--;
        }
    }

    if(a['V'-'A']!=0)
    {
        while(a['V'-'A'] != 0)
        {
            ans[7]++;
            a['S'-'A']--;
            a['E'-'A']--;
            a['V'-'A']--;
            a['E'-'A']--;
            a['N'-'A']--;
        }
    }

    if(a['W'-'A']!=0)
    {
        while(a['W'-'A'] != 0)
        {
            ans[2]++;
            a['T'-'A']--;
            a['W'-'A']--;
            a['O'-'A']--;
        }
    }

    if(a['O'-'A']!=0)
    {
        while(a['O'-'A'] != 0)
        {
            ans[1]++;
            a['O'-'A']--;
            a['N'-'A']--;
            a['E'-'A']--;
        }
    }

    if(a['H'-'A']!=0)
    {
        while(a['H'-'A'] != 0)
        {
            ans[3]++;
            a['T'-'A']--;
            a['H'-'A']--;
            a['R'-'A']--;
            a['E'-'A']--;
            a['E'-'A']--;
        }
    }

    if(a['I'-'A']!=0)
    {
        while(a['I'-'A'] != 0)
        {
            ans[9]++;
            a['N'-'A']--;
            a['I'-'A']--;
            a['N'-'A']--;
            a['E'-'A']--;
        }
    }
    for(i=0;i<=9;i++)
    {
        for(j=0;j<ans[i];j++)printf("%d",i);
    }
    printf("\n");
}

    return 0;
}

