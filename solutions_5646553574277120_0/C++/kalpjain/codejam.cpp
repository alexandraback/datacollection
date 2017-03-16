#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a>b);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(void) {
    freopen("in.txt","rt",stdin);
    freopen("test.txt","wt",stdout);
    int t,tc,c,d,v1;
    cin>>t;
    for(tc=1;tc<=t;++tc)
    {
        cin>>c>>d>>v1;
        cout<<"Case #"<<tc<<": ";
        bool b[1000]={0};
        int i,a[d],j,k,ans=0;
        vector <int> v;
        for(i=0;i<d;++i)
        {
            cin>>a[i];
            b[a[i]]=1;
            v.push_back(a[i]);
        }
        for(i=0;i<1<<d;++i)
        {
            int s=0;
            for(j=0;j<d;++j)
            {
                if(i&(1<<j))
                    s+=a[j];
            }
            if(!b[s]&&s<=v1)
            {
                v.push_back(s);
                b[s]=1;
            }
        }
        for(i=1;i<=v1;++i)
        {
            if(!b[i])
            {
                ans++;
                b[i]=1;
                vector <int> temp=v;
                v.push_back(i);
                for(j=0;j<temp.size();++j)
                {
                    if(!b[v[j]+i]&&v[j]+i<=v1)
                    {
                        v.push_back(temp[j]+i);
                        b[temp[j]+i]=1;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
