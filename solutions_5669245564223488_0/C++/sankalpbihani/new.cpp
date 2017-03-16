#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long L;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define mod 1000000007
#define INF mod

int main()
{
#ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;
    for(int T=1;T<=t;T++)
    {
        cin>>n;
        string s[n];
        for(int i=0; i<n; i++) cin>>s[i];
        int a[n];
        for(int i=0; i<n; i++) a[i]=i;
        L ans=0;
        do
        {
            bool flag=1;
            int x[27];
            fill(x,x+27,-1);
            char l=-1;
            for(int i=0; i<n; i++)
            {
                for(int j=0;j<s[a[i]].length(); j++)
                {
                    if(l!=s[a[i]][j] and x[s[a[i]][j]-'a']!=-1) {
                            flag=0;
                            break;
                    }
                    l=s[a[i]][j];
                    x[s[a[i]][j]-'a']=i;
                }
            }
            if(flag) ans++;
        }
        while(next_permutation(a,a+n));
        cout<<"Case #"<<T<<": "<<ans%mod<<endl;
    }
    return 0;
}
