// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;
// }}}
// #defines {{{
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
void RI() {}
template<typename... T>
void RI(int& head,T&... tail) {
    scanf("%d",&head);
    RI(tail...);
}
void PRI(int x) {
    printf("%d\n",x);
}
template<typename... Args>
void PRI(int head,Args... tail) {
    printf("%d ",head);
    PRI(tail...);
}
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRIIII(x,y,z,w) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d "#w"=%d>\n",x,y,z,w)
#define DPRF(x) fprintf(stderr,"<"#x"=%lf>\n",x)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
inline string concatenate_strings(vector<string> ss) {
   string s;
   for(int i=0;i<ss.size();i++)
      s+=ss[i];
   return s;
}
template <class T>
inline vector<T> read_from_string(string s) {
   vector<T> ret; stringstream ss(s,stringstream::in);
   while(1) { T x; ss>>x; ret.push_back(x); if(ss.eof()) break; }
   return ret;
}
// }}}

const int MAXN = 55;
const int MAXL = MAXN*MAXN;
const int MAXVAL = 2500;

int n;
int s[MAXL];
vector<int> ls[MAXN*2];
int gr[MAXN][MAXN];
bool flip;

bool cmp(vector<int> a,vector<int> b) {
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]) return a[i]<b[i];
    return 0;
}

bool fill(int r,int c,int val) {
    if(gr[r][c]>=0&&gr[r][c]!=val) return 0;
    gr[r][c]=val;
    return 1;
}

bool dfs(int r,int c,int q,int rskip,int cskip) {
    //printf("%d %d %d %d %d\n",r,c,q,rskip,cskip);
    //for(int i=0;i<n;i++) {
        //for(int j=0;j<n;j++)
            //printf("%d ",gr[i][j]); puts("");
    //} puts("--");
    if(r==n&&c==n) {
        if(flip) {
            if(rskip>=0) {
                for(int i=n-1;i>=0;i--)
                    printf(" %d",MAXVAL-gr[rskip][i]);
            } else {
                for(int i=n-1;i>=0;i--)
                    printf(" %d",MAXVAL-gr[i][cskip]);
            }
        } else {
            if(rskip>=0) {
                for(int i=0;i<n;i++)
                    printf(" %d",gr[rskip][i]);
            } else {
                for(int i=0;i<n;i++)
                    printf(" %d",gr[i][cskip]);
            }
        }
        puts("");
        return true;
    }
    bool ok2=false;
    int orig[n];
    if(r<n&&q<2*n-1&&(r==0||c==n||gr[r][0]<=gr[0][c])&&gr[r][0]==ls[q][0]) {
        bool ok=true;
        for(int i=0;i<n;i++)
            orig[i]=gr[r][i];
        for(int i=0;i<n;i++) {
            ok&=fill(r,i,ls[q][i]);
            if(!ok) break;
        }
        if(ok&&dfs(r+1,c,q+1,rskip,cskip)) return true;
        for(int i=0;i<n;i++)
            gr[r][i]=orig[i];
        ok2|=ok;
    }
    if(c<n&&q<2*n-1&&(c==0||r==n||gr[0][c]<=gr[r][0])&&gr[0][c]==ls[q][0]) {
        bool ok=true;
        for(int i=0;i<n;i++)
            orig[i]=gr[i][c];
        for(int i=0;i<n;i++) {
            ok&=fill(i,c,ls[q][i]);
            if(!ok) break;
        }
        if(ok&&dfs(r,c+1,q+1,rskip,cskip)) return true;
        for(int i=0;i<n;i++)
            gr[i][c]=orig[i];
        ok2|=ok;
    }
    if(!ok2&&rskip<0&&cskip<0) {
        //if(c==n||(r<n&&gr[r][0]<gr[0][c])) {
        if(dfs(r+1,c,q,r,cskip)) return true;
        //} else {
        if(dfs(r,c+1,q,rskip,c)) return true;
        //}
    }
    return false;
}

void solve() {
    sort(ls,ls+2*n-1,cmp);
    if(ls[1][0]!=ls[0][0]) {
        for(int q=0;q<2*n-1;q++) {
            for(int i=0;i<n;i++)
                ls[q][i]=MAXVAL-ls[q][i];
            for(int i=0;i<n-i-1;i++)
                swap(ls[q][i],ls[q][n-i-1]);
        }
        sort(ls,ls+2*n-1,cmp);
        flip=1;
    } else flip=0;
    memset(gr,-1,sizeof(gr));
    gr[0][0]=ls[0][0];
    dfs(0,0,0,-1,-1);
}

int main(void)
{
    int t;
    RI(t);
    for(int cas=1; cas<=t; cas++) {
        RI(n);
        for(int q=0;q<2*n-1;q++) {
            ls[q].resize(n);
            for(int i=0;i<n;i++)
                RI(ls[q][i]);
        }
        printf("Case #%d:",cas);
        solve();
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread
