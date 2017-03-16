// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) _dump(#__VA_ARGS__, __VA_ARGS__);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }

/// }}}

long rev( long x ) {
    long y=0;
    while ( x ) {
        y=y*10+x%10;
        x/=10;
    }
    return y;
}

long n;
void input() {
    cin>>n;
}

long solve_small() {
    const int SN=1e7;
    static int dis[SN];
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    auto push=[&]( int x, int d ) {
        if ( dis[x]!=-1 ) return;
        dis[x]=d;
        q.push(x);
    };
    push(1,1);
    while ( !q.empty() && dis[n]==-1 ) {
        int x=q.front(); q.pop();
        if ( x+1<=n ) push(x+1,dis[x]+1);
        push(rev(x),dis[x]+1);
    }
    assert(dis[n]!=-1);
    return dis[n];
}

long pw10[20];
void predo() {
    pw10[0]=1;
    REP(i,19) pw10[i+1]=10*pw10[i];
}

long solve_large() {
    if ( n<=10 ) return n;
    long x=10,ans=10;
    int len=2;
    while ( x*10<=n ) {
        assert(x==pw10[len-1]);
        auto t1=pw10[(len+0)/2]-1;
        auto t2=pw10[(len+1)/2]-1;
        x+=t1;
        ans+=t1;
        x=rev(x);
        ans++;
        x+=t2;
        ans+=t2;
        len++;
        //dump(x,ans);
    }
    if ( x==n ) return ans;
    long mi=n-x;
    auto test=[&]( long m ) {
        if ( x+m>n ) return;
        long y=rev(x+m);
        if ( y>n ) return;
        long z=m+1+n-y;
        mi=min(mi,z);
    };
    char s[20];
    sprintf(s,"%ld",n);
    long prefix=0;
    for ( int i=0; s[i]; i++ ) {
        prefix=prefix*10+s[i]-'0';
        test(rev(prefix));
        test(rev(prefix-1));
    }
    ans+=mi;
    return ans;
}

void solve() {
    long ans=solve_large();
    if ( n<=1000000 ) assert(ans==solve_small());
    printf("%ld\n",ans);
}

int main( int argc, char *argv[] ) {
    predo();
    int n_case;
    RI(n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}

