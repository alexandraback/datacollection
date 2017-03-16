#include<bits/stdc++.h>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define _sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount

// Useful container manipulation / traversal macros
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define f                           first
#define sc                          second

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str() // converting number (x) to string
#define SST(x) atoi(x) // converting a char array x to number

// Some common useful functions
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> pp;
typedef vector<string> VS;

#define fr(i,s,n)    for(int i=s;i<(n);++i)
#define MOD 1000000007

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int a,b,k;
LL dp[40][2][2][2];

LL f(int i,int ok1,int ok2,int ok3)
{
    LL& res=dp[i][ok1][ok2][ok3];
    if(res==-1)
    {
        if(i==0)
        {
            res=1;
        }
        else
        {
            res=0;

            i=i-1;
            for(int j=0;j<2;++j)
            {
                for(int l=0;l<2;++l)
                {
                    int r=j&l;

                    int bita=(a>>i)&1;
                    int bitb=(b>>i)&1;
                    int bitk=(k>>i)&1;

                    if(ok1==1 && j>bita)continue;
                    if(ok2==1 && l>bitb)continue;
                    if(ok3==1 && r>bitk)continue;

                    int nok1=ok1&&(bita==j);
                    int nok2=ok2&&(bitb==l);
                    int nok3=ok3&&(bitk==r);

                    res+=f(i,nok1,nok2,nok3);
                }
            }


        }
    }

    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif

    int T;
    s(T);

    for(int t=1;t<=T;++t)
    {
        cin>>a>>b>>k;

        a--;
        b--;
        k--;

        fill(dp,-1);
        LL cnt=f(32,1,1,1);
        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }


     return 0;
}


