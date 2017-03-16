#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
//const ll INF=(_I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define minn(a) memset(a, 0xC0, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a,b) memset(a, b, sizeof(a))
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
#define fi first
#define se second
typedef pair <int, int> PII;
typedef pair <ll , ll > PX ;

string aa,bb;
unsigned long long  ans;
int n;
void dfs(bool f,bool g,int x,string a,string b,unsigned long long ch,unsigned long long res) {
    //if(ch + res > ans) return;

   // cout<<a<<' '<<b<<' '<<f<<' '<<g<<' '<<x<<' '<<ch <<' '<<res<<endl;

    if(n == x) {
     //   cout<<a<<' '<<b<<' '<<res<<endl;
        if(res < ans) {
            ans = res;
            aa =a;
            bb = b;
        }
        else if(res == ans) {
            if(aa > a) {
                aa = a;
                bb = b;
            }
            else if (aa == a && bb > b) {
                bb = b;
            }
        }
        return;
    }
    int i = x;
    if (f == 0) {
        if (a[i] == '?' && b[i] == '?') {
            a[i] = b[i] = '0';
            dfs(f,g,x+1,a,b,ch/10,res);
            a[i] = '1';
            b[i] = '0';
            f = 1;
            g = 1;
            res += ch;
            dfs(f,g,x+1,a,b,ch/10,res);
            res -= ch;

            a[i] = '0';
            b[i] = '1';
            f = 1;
            g = 0;
            res += ch;
            dfs(f,g,x+1,a,b,ch/10,res);
            a[i] = b[i] = '?';
        } else if (a[i] == '?') {
            a[i] = b[i];
            dfs(f,g,x+1,a,b,ch/10,res);

            if (b[i] != '9') {
                a[i] = b[i] + 1;
                f = 1;
                g = 1;
                res += ch;
                dfs(f,g,x+1,a,b,ch/10,res);
                res -= ch;
            }
            if (b[i] != '0') {
                a[i] = b[i] - 1;
                f = 1;
                g = 0;
                res += ch;
                dfs(f,g,x+1,a,b,ch/10,res);
            }
            a[i] = '?';

        } else if (b[i] == '?') {
            b[i] = a[i];
            dfs(f,g,x+1,a,b,ch/10,res);
            if (a[i] != '9') {
                b[i] = a[i] + 1;
                f = 1;
                g = 0;
                res += ch;
                dfs(f,g,x+1,a,b,ch/10,res);
                res -= ch;
            }
            if (a[i] != '0') {
                b[i] = a[i] - 1;
                f = 1;
                g = 1;
                res += ch;
                dfs(f,g,x+1,a,b,ch/10,res);
            }
            b[i] = '?';

        } else {
            if (a[i] > b[i]) {
                f = 1;
                g = 1;
                res += ch * (a[i] - b[i]);
                dfs(f,g,x+1,a,b,ch/10,res);
            } else if (a[i] < b[i]) {
                f = 1;
                g = 0;
                res += ch * (b[i] - a[i]);
                dfs(f,g,x+1,a,b,ch/10,res);
            }
            else {
                dfs(f,g,x+1,a,b,ch/10,res);
            }
        }
    } else {
        if (g) { // a > b
            bool f1 = 0,f2 = 0;
            if (a[i] == '?'){
                a[i] = '0';
                f1 = 1;
            }
            if (b[i] == '?'){
                b[i] = '9';
                f2 = 1;
            }
            if (a[i] > b[i]) {
                res += ch * (a[i] - b[i]);
            }
            else {
                res -= ch * (b[i] - a[i]);
            }
            dfs(f,g,x+1,a,b,ch/10,res);
            if(f1) a[i] = '?';
            if(f2) b[i] = '?';
        } else { // a < b
            bool f1 = 0,f2 = 0;
            if (a[i] == '?'){
                a[i] = '9';
                f1 = 1;
            }
            if (b[i] == '?'){
                b[i] = '0';
                f2 = 1;
            }
            if (a[i] > b[i]) {
                res -= ch * (a[i] - b[i]);
            }
            else {
                res += ch * (b[i] - a[i]);
            }
            dfs(f,g,x+1,a,b,ch/10,res);
            if(f1) a[i] = '?';
            if(f2) b[i] = '?';
        }

    }
}


void work() {
    string a,b;
    cin>>a>>b;

 //   cout<<a<<' '<<b<<' ';

    int i,j;
    bool f = 0,g = 0;
    n = a.length();

    ans = -1;
    unsigned long long tp = 1;
    rep(i,n-1) tp *= 10;

    dfs(f,g,0,a,b,tp,0);

//
//    rep(i,n) {
//        if (f == 0) {
//            if (a[i] == '?' && b[i] == '?') {
//                a[i] = b[i] = '0';
//            }
//            else if (a[i] == '?') {
//                a[i] = b[i];
//            }
//            else if (b[i] == '?') {
//                b[i] = a[i];
//            }
//            else {
//                if (a[i] > b[i]) {
//                    f = 1;
//                    g = 0;
//                }
//                else if(a[i] < b[i]){
//                    f = 1;
//                    g = 0;
//                }
//            }
//        }
//        else {
//            if (g) { // a > b
//                if (a[i] == '?') a[i] = '0';
//                if (b[i] == '?') b[i] = '9';
//            }
//            else { // a < b
//                if (a[i] == '?') a[i] = '9';
//                if (b[i] == '?') b[i] = '0';
//            }
//
//        }
//
//    }
    cout<<aa<<' '<<bb<<endl;
  //  cout<<abs(atoi(aa.c_str())-atoi(bb.c_str()))<<endl;
}

int main() {
#ifdef LOCAL
    freopen( "in.txt", "r" , stdin);
 freopen ("out.txt","w",stdout );
#endif



    int T,cas=1;
    cin>>T;
    while(T--) {
        printf("Case #%d: ",cas++);
        work();
    }



    return 0;
}



