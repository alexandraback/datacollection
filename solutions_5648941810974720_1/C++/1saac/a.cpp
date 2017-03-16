#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int a[30],b[30];

int main()
{
    int T,ca=0;
    //freopen("A-large (1).in","r",stdin);
    //freopen("A-large (1).out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ca++;
        char x[3000];
        cin>>x;
        memset(b,0,sizeof b);
        memset(a,0,sizeof a);
        int i,j,l;
        l=strlen(x);
        for (i=0;i<l;i++) b[x[i]-'A']++;
        a[0]=b['Z'-'A'];
        b['Z'-'A']-=a[0];
        b['E'-'A']-=a[0];
        b['R'-'A']-=a[0];
        b['O'-'A']-=a[0];
        a[2]=b['W'-'A'];
        b['T'-'A']-=a[2];
        b['W'-'A']-=a[2];
        b['O'-'A']-=a[2];
        a[8]=b['G'-'A'];
        b['E'-'A']-=a[8];
        b['I'-'A']-=a[8];
        b['G'-'A']-=a[8];
        b['H'-'A']-=a[8];
        b['T'-'A']-=a[8];
        a[6]=b['X'-'A'];
        b['S'-'A']-=a[6];
        b['I'-'A']-=a[6];
        b['X'-'A']-=a[6];
        a[7]=b['S'-'A'];
        b['S'-'A']-=a[7];
        b['E'-'A']-=a[7];
        b['V'-'A']-=a[7];
        b['E'-'A']-=a[7];
        b['N'-'A']-=a[7];
        a[5]=b['V'-'A'];
        b['F'-'A']-=a[5];
        b['I'-'A']-=a[5];
        b['V'-'A']-=a[5];
        b['E'-'A']-=a[5];
        a[4]=b['F'-'A'];
        b['F'-'A']-=a[4];
        b['O'-'A']-=a[4];
        b['U'-'A']-=a[4];
        b['R'-'A']-=a[4];
        a[1]=b['O'-'A'];
        b['O'-'A']-=a[1];
        b['N'-'A']-=a[1];
        b['E'-'A']-=a[1];
        a[3]=b['R'-'A'];
        b['T'-'A']-=a[3];
        b['H'-'A']-=a[3];
        b['R'-'A']-=a[3];
        b['E'-'A']-=a[3];
        b['E'-'A']-=a[3];
        a[9]=b['I'-'A'];
        b['N'-'A']-=a[9];
        b['I'-'A']-=a[9];
        b['N'-'A']-=a[9];
        b['E'-'A']-=a[9];
        printf("Case #%d: ",ca);
        for (i=0;i<=9;i++)
            for (j=1;j<=a[i];j++)
            cout<<i;
        cout<<endl;
    }


    return 0;
}
