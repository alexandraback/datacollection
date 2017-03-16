#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;

bool bi[1000006];
vector<int>pr;

void sieve()
{
    ll a,b;
    pr.clear();
    pr.push_back(2);
    for(a=3;a<=1000000;a=a+2)
    {
        if(!bi[a])
        {
            bi[a]=true;
            pr.push_back(a);
            for(b=a*a;b<=1000000;b=b+a) bi[b]=true;
        }
    }
    //cout<<pr.size()<<endl;
    //for(a=0;a<10;a++) cout<<pr[a]<<endl;
}

ll A,B;

map<ll,ll>m;

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);
    sieve();
    int t;
    cin>>t;
    ll a,b,c,d,e,x,y,z,n;
    char ch;

    z=1;

    for(a=0;a<=40;a++)
    {
        //cout<<z<<" "<<a<<endl;
        m[z]=a;
        z=z*2;
    }

    for(int it=1;it<=t;it++)
    {
        cin>>A>>ch>>B;

        for(a=0;a<pr.size();a++)
        {
            while(1)
            {
                if(A%pr[a]==0 && B%pr[a]==0)
                {
                    A=A/pr[a];
                    B=B/pr[a];
                    continue;
                }
                break;
            }
        }
        cout<<"Case #"<<it<<": ";
        ll ans=0;
        if(!m[B])
        {
            cout<<"impossible"<<endl;
            continue;
        }
        while(1)
        {
            ans++;
            if(A*2>=B)
            {
                break;
            }
            else B=B/2;
        }

        cout<<ans<<endl;
        /*cout<<A<<" "<<B<<endl;

        if(m[B]) cout<<m[B]<<endl;
        else cout<<"Impossible"<<endl;*/
    }

    return 0;
}
