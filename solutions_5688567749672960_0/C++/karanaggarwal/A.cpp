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




int rev(int x)
{
    int ret = 0;
    while(x)
    {
        ret = ret*10 + (x%10); x/=10;
    }
    return ret;
}

int D[1000001];
bool V[1000001];
int main()
{
    int N = 1000001;
    priority_queue<PII> Q;
    for(int i=0; i<1000001; i++)D[i] = N;
    Q.push(MP(-1,1)); D[1] = 1;
    while(!Q.empty())
    {
        PII a = Q.top(); Q.pop();
        if(V[a.S])continue; V[a.S] = true;
        int y = rev(a.S);
        if(y<N and D[y]>D[a.S]+1)
        {
            D[y] = 1 + D[a.S];
            Q.push(MP(-D[y],y));
        }
        y = a.S+1;
        if(y<=1000000 and D[y]>D[a.S]+1)
        {
            D[y] = 1 + D[a.S];
            Q.push(MP(-D[y],y));
        }
    }
    int t; si(t); int T = t; 
    while(t--)
    {
        int n; si(n); 
        cout<<"Case #"<<T-t<<": "<<D[n]<<endl;
    }
    return 0;
}

