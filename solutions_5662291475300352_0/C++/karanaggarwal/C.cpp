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
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector< PII > VPII;

typedef pair< PLL , int > state;


class comp
{
    public:
    bool operator() (state a, state b)
    {
        if(a.F.F * a.F.S != b.F.F*b.F.S)
            return a.F.F * a.F.S >  b.F.F*b.F.S;
        return a.S > b.S;
    }
};

int main()
{
    priority_queue<state, vector<state>, comp> pq;
    int t; si(t); int T = t; while(t--)
    {
        while(!pq.empty())pq.pop();
        int ans  =  0;
        int N; cin>>N; 
        while(N--)
        {
            LL x, m , t;
            cin>>x>>m>>t;
            while(m--)
            {
                pq.push(MP(MP(360-x,t),0));
                t++;
                ans++;
            }
        }
        /*
        while(!pq.empty())
        {
            state a = pq.top(); pq.pop();
            trace3(a.F.F, a.F.S, a.S);
        }
        */
        int c = ans;
        int cta = 0; // total whose second round has been crossed
        while(!pq.empty() and cta < ans)
        {
            state a = pq.top(); pq.pop();
//            trace3(a.F.F, a.F.S, a.S);
            if(a.S==0)
                c--;
            else
            {
                c++; cta++;
            }
            ans=min(ans,c);
            pq.push(MP(  MP(a.F.F + 360 , a.F.S)   , -1));
        }
        cout<<"Case #"<<T-t<<": "<<ans<<endl;

    }
    return 0;
}

