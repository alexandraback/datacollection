#include "bits/stdc++.h"

using namespace std;

int rev(int x)
{
    int ans = 0;
    while(x)
    {
        ans = ans*10 + x%10;
        x/=10;
    }
    return ans;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int test = 1;test<=t;++test)
    {
        queue<pair<int,int>> q;
        set<int> visited;
        int n;
        cin>>n;
        if(n == 1)
        {
            cout<<"Case #"<<test<<": 1\n";
            continue;
        }
        q.push({1,1});
        visited.insert(1);
        int ans = -1;
        while(ans == -1)
        {
            int pres = q.front().first;
            int dist = q.front().second;
            int r = rev(pres);
            q.pop();
            if(pres+1 == n || r == n)
            {
                ans = dist+1;
                break;
            }
            else
            {
                if(!visited.count(pres+1))
                {
                    q.push({pres+1,dist+1});
                    visited.insert(pres+1);
                }
                if(!visited.count(r))
                {
                    q.push({r,dist+1});
                    visited.insert(r);
                }
            }
        }
        cout<<"Case #"<<test<<": "<<ans<<'\n';
    }
    return 0;
}
