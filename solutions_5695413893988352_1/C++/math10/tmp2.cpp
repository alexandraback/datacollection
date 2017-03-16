/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define eb emplace_back
#define pii pair<int64 ,int64 >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case #%d: ",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'|c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"    "; return *this; }}dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "["; forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i; cerr << "]" << endl;
}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = 1000000000000000000ll;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
string a,b;
int l;
int64 ans , o,p;

int64 powOf10[19];
pii dp[20];
int vis[20];
pii call(int pos){
    if(pos == l){
        return pii(0,0);
    }

    if(vis[pos]) return dp[pos];
    vis[pos] = true;
    int x1,y1,x2,y2;
    if(a[pos] == '?') x1 = 0, y1 = 9;
    else x1 = y1 = a[pos] - '0';
    if(b[pos] == '?') x2 = 0, y2 = 9;
    else x2 = y2 = b[pos] - '0';
    int64 x = 0,y = 0;
    pii ans;
    int64 dif = INF;
    forab(i,x1,y1){
        forab(j,x2,y2){
            x = i;
            y = j;
            if(i != j){
                if(i > j){
                    forab(k,pos+1,l-1){
                        if(a[k] == '?') x *= 10;
                        else x = x*10 + (a[k]-'0');
                        if(b[k] == '?') y = y*10 + 9;
                        else y = y*10 + (b[k]-'0');
                    }
                }

                if(i < j){
                    forab(k,pos+1,l-1){
                        if(a[k] == '?') x = x*10 + 9;
                        else x = x*10 + (a[k]-'0');
                        if(b[k] == '?') y = y*10;
                        else y = y*10 + (b[k]-'0');
                    }
                }
                if(abs(x-y) < dif){
                    dif = abs(x-y);
                    ans = pii(x,y);
                }

            }else{
                pii p = call(pos+1);
                x = x*powOf10[l-pos-1] + p.ff;
                y = y*powOf10[l-pos-1] + p.ss;

                if(abs(x-y) < dif){
                    dif = abs(x-y);
                    ans = pii(x,y);
                }
            }
        }
    }

    return dp[pos] = ans;

}

string toString(int64 number){
    stringstream ss;
    ss << number;
    string s = ss.str();
    while(s.size() < l) s = "0" + s;
    return s;
}

int main() {
#ifdef Sanim
    //geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    powOf10[0] = 1;
    For(i,18) powOf10[i] = powOf10[i-1]*10;
    int t = II;
    For(cs,t){
        cin >> a >> b;
        l = a.size();
        ans = mod;
        memo(vis,0);
        pii ans = call(0);
        a = toString(ans.ff);
        b = toString(ans.ss);
        /*bool flag = 0;
        rep(i,l){
            if(a[i] != '?' && b[i] != '?'){
                if(a[i] == b[i]) continue;
                if(a[i] < b[i]) {
                    swap(a,b);
                    flag = 1;
                }
                forab(j,i+1,l-1){
                    if(a[j] =='?') a[j] = '0';
                    if(b[j] =='?') b[j] = '9';
                }
                break;
            }else if(a[i] == '?' && b[i] == '?'){
                a[i] = '0';
                b[i] = '0';
            }else if(a[i] == '?'){
                a[i] = b[i];
            }else{
                b[i] = a[i];
            }
        }
        if(flag)swap(a,b);*/
        OC;
        cout << a << " " << b << endl;
    }
}
