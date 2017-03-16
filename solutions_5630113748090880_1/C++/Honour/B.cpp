//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

vector<int>vec;
int ar[2509];

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    int i,j,k,l,n,cas,test,flag,temp,now,ans=0;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        memset(ar,0,sizeof(ar));
        cin>>n;

        for(i=1;i<=2*n-1;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>k;
                ar[k]++;
            }
        }

        printf("Case #%d:",cas);
        for(i=1;i<=2500;i++) if(ar[i]%2) cout<<" "<<i;cout<<endl;

    }



}
