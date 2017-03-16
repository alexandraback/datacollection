//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

char aa[100009],ss[100009];
int KEEP[10000],ar[100000];

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    int i,j,k,l,n,cas,test,flag,temp,now,ans=0;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        scanf("%s",aa);
        n=strlen(aa);

        for(i='a';i<='z';i++) ar[i]=0;
        for(i=0;i<100;i++) KEEP[i]=0;

        for(i=0;i<n;i++) aa[i]=tolower(aa[i]);

        for(i=0;i<n;i++) ar[aa[i]]++;

        KEEP[0]=ar['z'];
        KEEP[8]=ar['g'];
        KEEP[4]=ar['u'];
        KEEP[6]=ar['x'];
        KEEP[5]=ar['f']-KEEP[4];
        KEEP[7]=ar['v']-KEEP[5];
        KEEP[3]=ar['r']-KEEP[0]-KEEP[4];
        KEEP[2]=ar['t']-KEEP[8]-KEEP[3];
        KEEP[1]=ar['o']-KEEP[2]-KEEP[4]-KEEP[0];
        KEEP[9]=ar['i']-KEEP[5]-KEEP[6]-KEEP[8];

        printf("Case #%d: ",cas);
        for(i=0;i<10;i++)
        {
            for(j=0;j<KEEP[i];j++)
            {
                cout<<i;
            }
        }
        printf("\n");

    }



}
