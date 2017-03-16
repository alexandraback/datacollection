#include<bits/stdc++.h>
#define MAXN 155
#define PI acos(-1.0)
#define MOD 1000000007
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,s,t) for(int i=s; i<=t; i++)
#define mem(a,b)  memset(a,b,sizeof(a))
#define show(x) { cerr<<">>>"<<#x<<" = "<<x<<endl; }
#define show2(x,y) { cerr<<">>>"<<#x<<"="<<x<<"  "<<#y<<" = "<<y<<endl; }
using namespace std;



int main()
{
    freopen("E:\\acm\\input.txt","r",stdin);
    freopen("E:\\acm\\output.txt","w",stdout);
    int T; cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        long long a,b;
        long long tmp = 0;
        char ch;
        while(cin>>ch && ch != '/')
        {
            tmp = tmp*10 + ch - '0';
        }
        a = tmp;
        tmp = 0;
        while(scanf("%c",&ch)==1 && ch != '\n')
        {
            tmp = tmp*10 + ch - '0';
        }
        b = tmp;
        long long g = __gcd(a,b);
        a = a/g;
        b = b/g;
        tmp = b;
        int ans = -1;
        for(int i=0; i<40; i++)
        {
            if(tmp%2 == 0) tmp=tmp/2;
        }

        printf("Case #%d: ",cas);
        if(tmp>1) {
            printf("impossible\n");
            continue;
        }
        for(int i=0; i<40; i++)
        {
            if(2*a >= b)
            {
                ans = i+1;
                break;
            }
            a = a*2;
            g = __gcd(a,b);
            a = a/g;
            b = b/g;

        }
        printf("%d\n",ans);
    }


}












