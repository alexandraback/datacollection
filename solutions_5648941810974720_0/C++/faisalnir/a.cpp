#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int a[26];

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        char s[10000];
        scanf("%s",s);
        int l=strlen(s);
        vector<int>x;
        memset(a,0,sizeof a);
        for(int i=0;i<l;i++)a[s[i]-'A']++;
        if(a['X'-'A'])
        {
            int n=a['X'-'A'];
            a['X'-'A']=0;
            a['S'-'A']-=n;
            a['I'-'A']-=n;
            for(int j=0;j<n;j++)x.pb(6);

        }
        if(a['U'-'A'])
        {
            int n=a['U'-'A'];
            a['U'-'A']=0;
            a['F'-'A']-=n;
            a['O'-'A']-=n;
            a['R'-'A']-=n;
            for(int j=0;j<n;j++)x.pb(4);

        }
        if(a['Z'-'A'])
        {
            int n=a['Z'-'A'];
            a['Z'-'A']=0;
            a['E'-'A']-=n;
            a['O'-'A']-=n;
            a['R'-'A']-=n;
            for(int j=0;j<n;j++)x.pb(0);

        }
        if(a['G'-'A'])
        {
            int n=a['G'-'A'];
            a['G'-'A']=0;
            a['E'-'A']-=n;
            a['I'-'A']-=n;
            a['H'-'A']-=n;
            a['T'-'A']-=n;
            for(int j=0;j<n;j++)x.pb(8);

        }
        if(a['W'-'A'])
        {
            int n=a['W'-'A'];
            a['W'-'A']=0;
            a['O'-'A']-=n;

            a['T'-'A']-=n;
            for(int j=0;j<n;j++)x.pb(2);

        }
        if(a['T'-'A'])
        {
           int n=a['T'-'A'];for(int j=0;j<n;j++)x.pb(3);
        }
        if(a['O'-'A'])
        {
           int n=a['O'-'A'];for(int j=0;j<n;j++)x.pb(1);
        }
        if(a['F'-'A'])
        {
           int n=a['F'-'A'];for(int j=0;j<n;j++)x.pb(5);a['I'-'A']-=n;
        }
        if(a['S'-'A'])
        {
           int n=a['S'-'A'];for(int j=0;j<n;j++)x.pb(7);
        }
        if(a['I'-'A'])
        {
           int n=a['I'-'A'];for(int j=0;j<n;j++)x.pb(9);
        }
        printf("Case #%d: ",c);
        sort(x.begin(),x.end());
        for(int i=0;i<x.size();i++)printf("%d",x[i]);
        printf("\n");
    }

}
