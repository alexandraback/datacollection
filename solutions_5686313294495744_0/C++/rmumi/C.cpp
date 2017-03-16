#include <bits/stdc++.h>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

string svi[]={
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T;
    scanf("%d",&T);
    int n;
    for(int CASE=1;CASE<=T;CASE++)
    {
        //this is horrible, but just saving time...
        printf("Case #%d: ",CASE);
        scanf("%d",&n);
        vector<pair<string,string> > a;
        a.resize(n);
        for(int i=0;i<n;i++)
            cin>>a[i].xx>>a[i].yy;
        int maxio=0;
        for(int bi=0;bi<(1<<n);bi++)
        {
            int i=0;
            for(i=0;i<n;i++)
            {
                if(!(bi&(1<<i)))
                {
                    int prv=0,drg=0;
                    for(int j=0;j<n;j++)
                    {
                        if(bi&(1<<j))
                        {
                            if(a[j].xx==a[i].xx)prv=1;
                            if(a[j].yy==a[i].yy)drg=1;
                        }
                    }
                    if(prv==0 || drg==0)break;
                }
            }
            if(i==n)
                maxio=max(n-__builtin_popcount(bi),maxio);
        }
        cout<<maxio<<endl;
    }
    return 0;
}
