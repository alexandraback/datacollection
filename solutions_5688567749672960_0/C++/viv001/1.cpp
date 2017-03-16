
// Author : Vivek Hamirwasia (viv001)
#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define LET(x,a) __typeof(a) x(a)
#define MP make_pair
#define tr(container , it) for(LET(it,container.begin) ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 1000000000
#define gi(x) scanf("%d",&x)
//_____starts____here_______
int dp[1000003];
priority_queue<PII> PQ;

int rev(int x)
{
    int d = 0;
    while(x!=0)
    {
        d = d*10 + x%10;
        x/=10;
    }
    return d;
}
int main()
{
    int t;
    gi(t);
    int kase = 0;
    while(t--)
    {
        kase++;
        while(!PQ.empty())
            PQ.pop();
        int n;
        gi(n);

        for(int i=0;i<=n;i++)
            dp[i] = INF;

        dp[n] = 1;
        PQ.push(MP(-1,n));
        while(!PQ.empty())
        {
            int num = PQ.top().second;
            if(num==1) break;
            int cst = -PQ.top().first;
            PQ.pop();
            int nxt = num-1;
            
            if(nxt>=1 && nxt<=1000000 && cst+1<dp[nxt])
            {
                dp[nxt] = cst+1;
                PQ.push(MP(-dp[nxt],nxt));
            }

            nxt = rev(num);
            if(rev(nxt)!=num) continue;
            if(nxt>=1 && nxt<=1000000 && cst+1<dp[nxt])
            {
                dp[nxt] = cst+1;
                PQ.push(MP(-dp[nxt],nxt));
            }
        }
        cout<<"Case #"<<kase<<": "<<dp[1]<<endl;
    }

    return 0;
}


