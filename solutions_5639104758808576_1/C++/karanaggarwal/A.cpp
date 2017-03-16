#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define rTR(v,it) for( LET(it,v.rbegin()) ; it != v.rend() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)
#define TRACE


int main()
{
    int t; si(t); int T = t;
    while(t--)
    {
        int N; cin>>N;
        string A; cin>>A;
        int sum =0;
        int ans = 0;
        for(int i=0; i<=N;i++)
        {
            if(sum<i)
            {
                ans+=(i-sum);
                sum=i;
            }
            sum+=(A[i]-'0');
        }
        cout<<"Case #"<<T-t<<": "<<ans<<endl;
    }
    return 0;
}

