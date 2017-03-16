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
int f[1000010] ;
string str,pre; 
void go(){
f[0] = 0 ;
f[1] = 0;
for(int i = 2 ; i <= str.length() ; ++i){
int j = f[i-1];
while(1){
if(str[i-1] == str[j]){
f[i] = j + 1;
break ;
}
else if(j == 0){
f[i] = 0;
break;
}
else
j = f[j];
}
}
}
int count(){
int state = 0 , ret = 0 ;
for(int i = 0 ; i < (int)pre.length() ; ++i){
if(pre[i] == str[state]){
state++ ;
if(state == (int)str.length()){
state = f[state] ;
ret++ ;
}
continue;
}
while(1){
if(pre[i] == str[state]){
state++ ;
if(state==(int)str.length()){
state = f[state];
ret++ ;
}
break;
}
else if(state != 0){
state = f[state] ;
}
else
break;
}
}
return ret ;
}
int main(){
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ; 
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0);
    int tc;  
    cin >> tc;
    int K , L , S; 
    double fuck = 0;
    REP(t,1,tc){
        cout << "Case #"<<t<<": " ;
        fuck = 0 ; 
        cin >> K >> L >> S; 
        string s , t; 
        cin >> s >> t; 
        str = t; 
        go();
        int maxi = powmod(K , S , 10000000000) ;
        //cout << maxi << "\n" ;  
        double valid = 0.0 ;
        double ans = 0.0 ; 
        for(int i = 0 ; i < maxi ; ++i){
            string cur="";
            int tit = i ;
            while(tit){
                cur.pb(s[tit%K]);
                tit /= K ;
            }
            while(cur.size() < S){
                cur.pb(s[0]);
            }
            reverse(cur.begin() , cur.end()) ; 
            if(maxi < 1000){
             //   trace2(cur,s) ; 
            }
            valid++ ; 
            double add =0.0; 
            pre = cur;
            add += count() ; 
            ans += add ; 
            fuck = max(fuck , add) ; 
        }
      //  trace1(ans); 
        ans /= valid ;
        double b=0.0; 
        string ck = t; 
        int state = t.length();
        cout << fixed << setprecision(6) << fuck-ans << "\n" ; 
    }
    return 0 ; 
}