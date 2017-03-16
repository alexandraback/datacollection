#include <bits/stdc++.h>


using namespace std;
#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define pii pair<int,int>
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define ld long double
#define tr(n) cin>>n
#define tr2(n,m) cin>>n>>m
#define tr3(a,b,c) cin>>a>>b>>c
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vii vector<pii>
#define vii vector<pii>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define Si set<int>
#define SLL set<LL>
#define SpLL set<pLL>
#define Sii set<pii>
#define fill(a,v) memset(a,v,sizeof(a))
#define oo 1000000007
#define MOD 1000000007

#define i64 long long

const i64 MODD=1000000007LL;

i64 poww(i64 x,i64 y,i64 MODD)
{
    if(x==0LL && y==0LL)
    {
        return 1LL;
    }
    i64 ret=1;

    while(y)
    {
        if(y&1LL)
        {
            ret*=x;
            ret%=MODD;
        }
        x*=x;
        x%=MODD;
        y>>=1;
    }


    return ret;
}


int t;

//cout << "Case #"
LL b,m;


LL cnt = 0;

LL dp[1005][1005];

int main()
{
    cin >> t;
    rep(tt,1,t)
    {cout << "Case #"<<tt<<": ";
    cin >> b >> m;    
    cnt = 0;
    m--;
    LL tmp = m;
    rep( i , 0, b+1)rep(j,0,b+1)dp[i][j]=0;
    dp[1][b] = 1;
    while(tmp)
    {
        cnt++;
        tmp/=2;
    }
   // cnt++;
   // cout << cnt << " " << b <<"...\n" ;
    if(!(b-2>=cnt))
    {
        cout <<"IMPOSSIBLE\n";
        continue;    
    }

    rep(i,1,cnt){
        rep(j,0,i-1)
        {
            dp[b-i][b-j] = 1;
        }

    }

    for(int i = 1;i<=cnt ; ++i)
    {
        if(m%2)
        {
            dp[1][b-i] = 1;
        }
        m/=2;
    }
    cout <<"POSSIBLE\n";
    rep( i , 1 ,b)
    {
        rep( j , 1,b)
        {
            cout << dp[i][j];
        }cout <<"\n";

    }
    }


    return 0;
}