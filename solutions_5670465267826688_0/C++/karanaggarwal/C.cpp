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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;



map<char,int> M;

int Mul[4][4];
bool Sgn[4][4];


pair<int,bool> cur;

int main()
{
    M['1'] = 0;
    M['i'] = 1;
    M['j'] = 2;
    M['k'] = 3;

    Mul[0][0] = 0; Mul[0][1] = 1; Mul[0][2] = 2; Mul[0][3] = 3;
    Mul[1][0] = 1; Mul[1][1] = 0; Mul[1][2] = 3; Mul[1][3] = 2;
    Mul[2][0] = 2; Mul[2][1] = 3; Mul[2][2] = 0; Mul[2][3] = 1;
    Mul[3][0] = 3; Mul[3][1] = 2; Mul[3][2] = 1; Mul[3][3] = 0;

    Sgn[0][0] = false; Sgn[0][1] = false; Sgn[0][2] = false; Sgn[0][3] = false;
    Sgn[1][0] = false; Sgn[1][1] = true; Sgn[1][2] = false; Sgn[1][3] = true;
    Sgn[2][0] = false; Sgn[2][1] = true; Sgn[2][2] = true; Sgn[2][3] = false;
    Sgn[3][0] = false; Sgn[3][1] = false; Sgn[3][2] = true; Sgn[3][3] = true;

    int t; si(t); int T  = t; while(t--)
    {
        cout<<"Case #"<<T-t<<": ";
        int N,K; cin>>N>>K;
        if(K>50)K=40 + (K%4);
        N*=K;
        string A; cin>>A;
        string B = "";
        while(K--)B+=A;
        int i = 0;
        cur = MP(0,false);
        while(i<N and cur!=MP(1,false))
        {
            cur.S ^= (Sgn[cur.F][M[B[i]]]);
            cur.F = Mul[cur.F][M[B[i]]];
            i++;
        }
        if(cur!=MP(1,false)){cout<<"NO\n"; continue;}
        cur = MP(0,false);
        while(i<N and cur!=MP(2,false))
        {
            cur.S ^= (Sgn[cur.F][M[B[i]]]);
            cur.F = Mul[cur.F][M[B[i]]];
            i++;
        }
        if(cur!=MP(2,false)){cout<<"NO\n"; continue;}
        cur = MP(0,false);
        while(i<N)
        {
            cur.S ^= (Sgn[cur.F][M[B[i]]]);
            cur.F = Mul[cur.F][M[B[i]]];
            i++;
        }
        if(cur!=MP(3,false)){cout<<"NO\n"; continue;}
        cout<<"YES\n";

    }
    return 0;
}

