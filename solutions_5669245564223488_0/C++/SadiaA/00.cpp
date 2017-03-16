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
vector<int>pr;
string s,st;

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    ll t;
    cin>>t;
    ll a,b,n,c,Ans;

    for(int i=1;i<=t;i++)
    {
        cin>>n;
        v.clear();
        pr.clear();
        for(a=0;a<n;a++)
        {
            cin>>st;
            v.push_back(st);
            pr.push_back(a);
        }
        Ans=0;
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
        }
        int ar[900];
        cout<<"Case #"<<i<<": ";
        do
        {
            st="2";
            for(a=0;a<n;a++) st=st+v[ pr[a] ];
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
            if(a==st.size()) Ans++;

        }while(next_permutation(pr.begin(),pr.end()));

        cout<<Ans<<endl;
    }


    return 0;
}
