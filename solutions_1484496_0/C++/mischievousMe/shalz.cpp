#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;


int main()
{
    int t;
scanf("%d",&t);
    int n,x=0;
    while(t--)
    {
        x++;
        scanf("%d",&n);
        int ar[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        int sum[(1<<20)];
        int ind=0;
        map<int,vector<int> > m;
        for(int i=0;i<(1<<n);i++)
        {
            int ll=i,s=0;
            for(int j=0;ll;j++,ll>>=1)
                if(ll&1)
                    s+=ar[j];
            sum[ind++]=s;
            m[s].push_back(i);
        }
        sort(sum,sum+(1<<n));
        int ans;
        bool fl=0;
        for(int i=0;i<(1<<n)-1;i++)
        {
            if(sum[i]==sum[i+1])
            {
                ans=sum[i];
                fl=1;
                break;
            }
        }
        cout<<"Case #"<<x<<":\n";
        if(fl)
        {
            int f=m[ans][0],ss=m[ans][1];
            int ll=f;
            for(int j=0;ll;j++,ll>>=1)
            {
                if(ll&1) cout<<ar[j]<<" ";
            }
            cout<<"\n";
            ll=ss;
            for(int j=0;ll;j++,ll>>=1)
            {
                if(ll&1) cout<<ar[j]<<" ";
            }
            cout<<"\n";
        }
        else cout<<"Impossible\n";
    }
    return 0;
}
