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

vector<string>v;
vector<int>per;

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int t;
    cin>>t;
    ll a,b,c,d,e,x,y,z,n;

    for(int it=1;it<=t;it++)
    {
        cin>>n;
        v.clear();
        string s,st;
        per.clear();
        cout<<"Case #"<<it<<": ";
        for(a=0;a<n;a++)
        {
            cin>>s;
            v.push_back(s);
            per.push_back(a);
        }
        for(a=0;a<n;a++)
        {
            s=v[a];
            st="";
            for(b=0;b<s.size();b++)
            {
                if(st=="") st=st+s[b];
                else
                {
                    c=st.size();
                    if(st[c-1]==s[b]) continue;
                    st=st+s[b];
                }
            }
            v[a]=st;
            //cout<<v[a]<<" ";
        }
        int ar[256];
        ll ans;
        ans=0;
        do
        {
            st="2";
            for(a=0;a<n;a++) st=st+v[ per[a] ];
            for(a='a';a<='z';a++) ar[a]=0;
            for(a=1;a<st.size();a++)
            {
                if(ar[ st[a] ])
                {
                    b=ar[ st[a] ];
                    if(b==a-1)
                    {
                        ar[ st[a] ]=a;
                    }
                    else break;
                }
                else
                {
                    ar[ st[a] ]=a;
                }
            }
            if(a==st.size()) ans++;

        }while(next_permutation(per.begin(),per.end()));
        cout<<ans<<endl;
    }


    return 0;
}
