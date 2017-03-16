#include<bits/stdc++.h>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

int t,j,p,s,k;

int main()
{
    int i,x,y,l,nr,cnt;
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    cin.sync_with_stdio(false);
    cin>>t;
    for (l=1;l<=t;l++)
    {
        cin>>j>>p>>s>>k;
        cout<<"Case #"<<l<<": ";
        cout<<p*j*min(k,s)<<"\n";
        cnt=0;
        for (x=1;x<=p;x++)
            {
                nr=0;
                for (i=1;i<=j;i++)
                {
                    cnt++;
                    if (cnt>j) cnt=1;
                    for (y=1;y<=min(k,s);y++)
                    {
                        nr++;
                        if (nr>s) nr=1;
                        cout<<cnt<<" "<<x<<" "<<nr<<"\n";
                    }
                }
            }
    }
    return 0;
}

