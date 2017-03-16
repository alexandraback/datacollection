#include<bits/stdc++.h>

using namespace std;

#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back

#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)|(b))
#define XOR(a,b) ((a) ^ (b))
#define xx first
#define yy second
#define mp make_pair
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))

#define LB(a,x) (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x) (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define left nokol_left
#define right nokol_right
#define countbit(x) __builtin_popcountll((ll)x)
#define PQ priority_queue
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<class T>T __sqr(const T x){return x*x;}
template< class T, class X > inline T __pow(T a,X y) {T z=1; rep(i,1,y){z*=a;} return z; }
template< class T > inline T gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return __gcd(b,a%b);}
template< class T > inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/__gcd(a,b))*b;}
inline bool ispow2(int x){return (x!=0 && (x&(x-1))==0);}
template<class T>void UpdateMin(T &x,T y){  if(y<x){x=y;}}
template<class T>void UpdateMax(T &x,T y){if(x<y){x=y;}}
template<class T,class X, class Y > inline T bigmod(T n,X m,Y mod){ull ret=1, a = n%mod ; while(m){ if(m&1)ret=(ret*a)%mod; m>>=1; a=(a*a)%mod; }ret%=mod;return (T)ret;}
template<class T, class Y > inline T modinv(T n,Y mod) {return bigmod(n,mod-2,mod);}

template<class T,class X> int getbit(T s,X i) { return (s >> i) & 1; }
template<class T,class X> T onbit(T s, X i) { return s | (T(1) << i); }
template<class T,class X> T offbit(T s, X i) { return s & (~(T(1) << i)); }
template<class T> inline void read(T &n){char c;for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar()); n = c - '0';for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';}

void extended_euclid(ll a,ll b,ll &x,ll &y){ if(!b){ x = 1 , y = 0  ;  return ;} ll xx,yy; extended_euclid(b,a%b,xx,yy); x = yy; y = xx - (a/b)*yy; }
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b) { ll x = 1, y = 0; ll xLast = 0, yLast = 1; ll q, r, m, n; while(a != 0) {q = b / a; r = b % a; m = xLast - q * x; n = yLast - q * y; xLast = x, yLast = y; x = m, y = n; b = a, a = r; } return make_pair(b, make_pair(xLast, yLast)); }

const ll mod[]  ={0,1000000007,1000000009,1000000021,1000000033,1000000097,1000000093,1000000097,1000000103};
const ll base[] ={0,1000003,1000033,1000037,1000039,1000081,1000099,1000117,1000121};

#define eps  1e-9
#define MX   (lmt + 20 )
#define inf  1000000000LL
#define MOD  1000000007
//---------->0123456789123465789
#define lmt  200000

long long trans[20][20];

void precal(){

    trans[2][2] = -1;
    trans[3][3] = -1;
    trans[4][4] = -1;

    trans[2][3] = 4;
    trans[3][4] = 2;
    trans[4][2] = 3;

    trans[2][4] = -3;
    trans[3][2] = -4;
    trans[4][3] = -2;
}

string str , get;

bool ch1 , ch2 , ch3;

long long func(){

        long long num = 1;
        long long L = str.size();
        rep(i,0,L-1){
            int x = str[i] - 'i' + 2; // 2 ,  3  , 4

                 if(num==-1 || num==1 || x==-1 || x==1) num = num*x;
            else if(num==x || num==-x) num = (num==x?-1:1);
            else if((num < 0 && x < 0) || (num > 0 && x > 0)) { num = abs(num); x = abs(x);
                    num = trans[num][x];
            }
            else{
                num = abs(num);
                x = abs(x);
                num = -trans[num][x];
            }

            if(ch1){
                if(num==2) return i;
            }

            if(ch2){
                if(num==3) return i;
            }

            if(ch3){
                    if(num==4) return i;
            }
        }

    if(ch1 || ch2 || ch3) return -1;

    return num;
}

int main()
{
    READ("C-large.in");
    WRITE("C-large.out");

    precal();

    string ans;
    long long  ts  , L , R , tot , kk =1;
    cin>>ts;
    while(ts--){

        ch1 = ch2 = ch3 = false;

        cin>>L>>R;
        cin>>str;

        long long tk = func();

        string tmp = str;

        ch1 = true;
        str = tmp  + tmp + tmp + tmp;
        long long fst = func() , total;

             if(fst==-1) ans = "NO";
        else{

            total = fst +1 ;

            str = "";
            fst %= L;
            rep(i,fst +1 ,L - 1){
                str += tmp[i];
            }
            str = str + tmp + tmp + tmp + tmp;


            ch1 = false;
            ch2 = true;


            long long snd = func();

            if(snd==-1) ans = "NO";
            else {
                total += snd + 1;
//                str = "";
                long long wh = str.size();
                string gg = "";
//            cout<<"s "<<str<<endl;
                rep(i,snd+1,wh-1){  // problem here
                    gg += str[i];
                }

                str = gg;

                while(str.size() < 4*tmp.size()){
                    str += tmp;
                }

//                str  = str + tmp + tmp + tmp + tmp;
//            cout<<"s  is "<<str<<endl;

//return 0;
                ch2 = false;
                ch3 = true;

//                cout<<str<<endl;

                long long th = func();

//                cout<<"th "<<th<<endl;

                if(th==-1) ans = "NO";
                else{

                    total += th + 1;

                    long long cnt = total / L;
                    if(total % L!=0) cnt++;

                    if(cnt > R) ans = "NO";
                    else{
                        long long baki =  R - cnt;
                        baki %= 4;

//                        str = "";
                        long long gs = gg.size();
                        string yy =  "";
//                        th %= L;
                        long long wh = str.size();
//    cout<<"s     "<<th<<endl;
    //complete------------------------------------------------------------------------
                        rep(i,th+1,wh-1){

                            if( (i - gs)%L==0 ) break;

                            yy += str[i];
                        }

                        str = yy;


                        rep(i,1,baki){
                            str += tmp;
                        }

//        cout<<"Baki nai   "<<str <<endl;

                        ch3 = false;
                        long long nw = func();

                        if(nw==1){
                            ans = "YES";
                        }
                        else ans = "NO";
                    }
                }
            }
        }


        cout<<"Case #"<<kk++<<": "<<ans<<endl;
    }
    return 0;
}
