#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <utility>
#include <map>
using namespace std;
long long reverse_ll(long long a)
{
    int shit[20],cnt=0;
    int x=1;
    while(a)
    {
        shit[cnt++]=a%10;
        a/=10;
        x*=10;
    }
    long long ret=0;
    for(int i=0;i<cnt;i++)ret=ret*10+shit[i];
    return ret;
}
int main()
{
    freopen("C:\\Users\\Frid\\Downloads\\A-small-attempt1.in","r",stdin);
    freopen("C:\\Users\\Frid\\Downloads\\A-small-attempt1.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        long long a;
        cin>>a;
        queue<long long> q;
        map<long long,long long> check;
        q.push(1);
        check[1]=1;
        while(q.size())
        {
            long long x=q.front();q.pop();
            if(x==a)
            {
                cout<<"Case #"<<i<<": "<<check[x]<<endl;
                break;
            }
            long long xx=x+1;
            long long xxx=reverse_ll(x);
            if(!check.count(xx))
            {
                q.push(xx);
                check[xx]=check[x]+1;
            }
            if(!check.count(xxx))
            {
                q.push(xxx);
                check[xxx]=check[x]+1;
            }
        }

    }
    return 0;
}
