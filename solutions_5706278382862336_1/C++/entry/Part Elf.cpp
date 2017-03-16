/*Part Elf*/
#include<iostream>
#include<string>
using namespace std;

long long hcf(long long q,long long p)
{   if(!p)
        return q;
    return hcf(p,q%p);
}
int main()
{
    freopen("A-large (3).in","r",stdin);
    freopen("out2.txt","w",stdout);
    long long a[42],i;
    a[0]=1;
    for(i=1;i<=41;i++)
        a[i]=a[i-1]*2;
    //cout<<a[41]<<endl;
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {   string s;
        cin>>s;
        long long p=0,q=0;
        for(i=0;s[i]!='/';i++)
           p=10*p+(s[i]-48);
        i++;
        for(;i<s.size();i++)
           q=10*q+(s[i]-48);
        long long h=hcf(q,p);
        //cout<<p<<" "<<q<<" "<<h<<endl;
        p/=h;
        q/=h;
        int flag=0;
        for(i=0;i<=41;i++)
        {   if(a[i]==q)
            {   flag=1;
                break;
            }
        }
        if(!flag||p%2!=1)
        {   cout<<"Case #"<<cas<<": ";
            cout<<"impossible\n";
            cas++;
            continue;
        }
        if(p==1&&q==1)
        {   cout<<"Case #"<<cas<<": ";
            cout<<0<<endl;
            cas++;
            continue;
        }
        int ans=1,temp=2;
        while(p*temp<q)
        {   ans++;
            temp*=2;
        }
        cout<<"Case #"<<cas<<": ";
        cout<<ans<<endl;
        cas++;
    }
    return 0;
}
