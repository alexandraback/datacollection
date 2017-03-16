#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define rep(i,n)        for(int i = 0 ; i < n; ++i)
#define REP(i,a,b)      for(int i = a ; i <= b; ++i)
#define pb(a)           push_back(a)
#define mp              make_pair
#define pii             pair<int,int>
#define MOD             1000000007
#define drep(i,n)       for(int i = n; i >= 0 ; --i)
#define DREP(i,a,b)     for(int i = a; i >= b ; --i)
#define ull             unsigned long long
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
#define sl(a)           scanf(LLD,a)
#define si(a)           scanf("%d",a)
#define si2(a,b)        scanf("%d%d",&a,&b)
#define si3(a,b,c)      scanf("%d%d%d",&a,&b,&c)
#define pri(a)          printf("%d",a)
#define prl(a)          printf(LLD,a)
#define priln           printf("\n")
#define pri2(a,b)       printf("%d %d\n" , a , b) 
#define ss              second
#define ff              first
#define vi              vector<int>
#define vl              vector<ll>
#define all(a)          a.begin(),a.end()
#define SZ(a)           a.size()
#define tri             pair < int , pii >
#define TRI(a,b,c)      mp(a,mp(b,c))
#define vs              vector<string>
#define msi             map<string,int>
#define mii             map<int,int>
#define mis             map<int,string>
#define mci             map<char,int>
#define DUP(a)          sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind)  (lower_bound(all(arr),ind)-arr.begin())
#define tr(it, a)       for(__typeof((a).begin()) it = a.begin(); it != a.end(); it++)
#define KK if(debug)
#define trace1(x) KK    cerr << #x << ": " << x << endl;
#define trace2(x, y) KK cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)    KK      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)  KK cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << "\n";
#define trace5(a, b, c, d, e) KK cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << "\n";
#define trace6(a, b, c, d, e, f) KK cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << "\n";
#define gc getchar()
inline int inp(){register int n=0,s=1,c=gc;if(c=='-')s=-1;while(c<48)c=gc;while(c>47)n=(n<<3)+(n<<1)+c-'0',c = gc;return n*s;}
#define pc(x) putchar(x) //_unlocked(x);
inline void writeInt (ll n)
{ll N = n, rev, count = 0;rev = N; if (N == 0) { pc('0'); pc('\n'); return ;}
while ((rev % 10) == 0) { count++; rev /= 10;}rev = 0; while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}while (count--) pc('0'); }
long long powmod(long long a , long long b , long long mod){if(b==0){return 1%mod; } long long x = powmod(a,b/2,mod) ; x = (x*x)%mod ; if(b&1){x = (a*x)%mod ; } return x ; }
const int INF = 1000000000;
const long double EPS = 1e-9;
const long double PI = (long double)(3.1415926535897932384626433832795);

int debug = 1; 

int main(){
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ; 
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0);
    int tc; 
    cin >> tc;
    int R , C , W ; 
    int fans = 0 ; 
    REP(t,1,tc){
        cout << "Case #" << t << ": " ; 
        fans = 0 ; 
        cin >> R >> C >> W ; 
        int mov = 0 ; 
        int curr = W ; 
        if(W==1){
            cout << C + (R-1)*C/W << "\n" ; 
            continue ; 
        }
        if(C/curr == 1){
            if(C % curr == 0){
                cout << W + (R-1)*C/W<< "\n" ; 
                continue ; 
            }
            else{
                cout << W + 1 + (R-1)*C/W << "\n"  ;
                continue ;  
            }
        }
        else{
            fans = max(fans , W+1 + (R-1)*C/W);
            curr += W ; 
            while(curr <= C){
                mov++ ; 
                //if(t==4)trace2(curr,mov) ;                
                if((curr/W) < (C/W)){
                    fans= max(fans ,mov +  W + 1 + (R-1)*C/W) ; 
                    //cout << fans << "\n" ; 
                }
                else{
                    if(C == curr){
                        fans = max(fans , mov + W + (R-1)*C/W) ; 
                    }
                    else{
                        fans = max(fans , mov + W + 1 + (R-1)*C/W) ; 
                    }
                }
                curr += W;  
            }
        }
        cout << fans << "\n" ; 
    }
    return 0 ;
}
    