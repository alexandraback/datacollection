#include <bits/stdc++.h>

using namespace std;

#define int long long

int mp=1ll<<40;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int test=0;test<T;test++)
    {
        cout<<"Case #"<<test+1<<": ";

        int n;
        cin>>n;

        pair<string,int> x[n];
        for(int i=0;i<n;i++)
            cin>>x[i].first,x[i].second=i;
        for(int i=0;i<n;i++)
        {
            string t;
            t+=x[i].first[0];
            for(int j=1;j<x[i].first.size();j++)
                if(x[i].first[j]!=x[i].first[j-1])t+=x[i].first[j];
            x[i].first=t;
        }
        sort(x,x+n);
        int ans=0;
        do
        {
            string t;
            int cnt[26];
            fill(cnt,cnt+26,0);
            for(int i=0;i<n;i++)
                t+=x[i].first;
            cnt[t[0]-'a']++;
            for(int i=1;i<t.size();i++)
                if(t[i]!=t[i-1] && cnt[t[i]-'a'])goto NXT;
                else cnt[t[i]-'a']++;

            ans++;
            NXT:;
        }
        while(next_permutation(x,x+n));

        cout<<ans<<endl;
    }
}
