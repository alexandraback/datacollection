#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int key[300];


int main()
{
    int T;
    cin>>T;
    for (int t=0;t<T;t++)
    {
        cout<<"Case #"<<t+1<<": ";
        int n,m,c;
        cin>>n>>m>>c;
        for (int i=0;i<m;i++)
        {
            cin>>key[i];
            if (key[i]>c)
                key[i]=c+1;
        }
        key[m]=c+1;
        long long s=n;
        int ans=0;
        if (key[0]!=1)
            ans=1;
        for (int i=0;i<=m;i++)
        {
            if (key[i]==1)
                continue;
            while (s+1<key[i])
            {
                ans++;
                s+=(s+1)*n;
            }
            s+=key[i]*n;

        }
        cout<<ans<<endl;

    }

}
