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


LL jj,p,s;
LL kk;

LL rem[55][55];

LL cnt = 0;

LL t;

int main()
{
cin >> t;
rep(tt,1,t)
{

    cout << "Case #"<<tt<<": ";
    cin >> jj >> p >> s;
    cin >> kk;
    cnt = 0;
    std::vector<pair<LL,pLL>> V;
    rep( i , 1 , p)
    rep( j , 1 , s)
    rem[i][j] = kk;

    rep( i ,  1, jj)
    {
        
        rep(j,1,p)
        {LL frem = kk;

        rep(k,1,s)
        {
            if(frem && rem[j][k])
            {
                rem[j][k]--;
                frem--;
                V.pb(mp(i,pLL(j,k)));
            }
            if(!frem)break;
        }
        
        }

    }

    cout << V.size() <<"\n";
    for(pair<LL,pLL> P : V)
    {
        cout << P.ff <<" "<<P.ss.ff<<" "<<P.ss.ss<<"\n";
    }
}

    return 0;
}