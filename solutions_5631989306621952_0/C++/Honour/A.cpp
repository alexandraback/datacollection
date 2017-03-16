//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

char aa[100009],ss[100009];
string dd,ANS,L,R;

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

        ANS="";

        for(i=0;i<n;i++)
        {
            ss[0]=aa[i];
            ss[1]='\0';
            dd=ss;

            L=ANS+dd;
            R=dd+ANS;

            ANS=max(L,R);

        }

        printf("Case #%d: ",cas);
        for(i=0;i<n;i++) printf("%c",ANS[i]);
        printf("\n");

    }



}
