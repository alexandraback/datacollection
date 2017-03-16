// @author kelvin
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RIII(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x)
#define PRII(x,y) printf("%d %d\n",x,y)
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

#define MAXL 55
#define MAXC MAXL*MAXL

int rn,cn,mine,safe;
bool vis[MAXL][MAXL][MAXC];
char cfg[MAXL][MAXL];
vector<pii> path;

bool dfs(int r,int c,int cnt) {
    vis[r][c][cnt]=1;
    if(r>rn) {
        //DPRIII(r,c,cnt);
        if(cnt!=safe) return 0;
        return 1;
    }
    int nr,nc,ncnt;
    // left
    if(c&&(c==1||r!=1)) {
        nr=r;
        nc=c-1;
        ncnt=cnt;
        if(!vis[nr][nc][ncnt]&&dfs(nr,nc,ncnt)) return 1;
    }
    // down
    if(r<1||c!=1) {
        nr=r+1;
        nc=c;
        ncnt=cnt+(nr<=rn?c:0);
        if(!vis[nr][nc][ncnt]&&dfs(nr,nc,ncnt)) {
            //DPRII(nr,nc);
            for(int j=c+1;j<=cn;j++)
                cfg[nr][j]='*';
            return 1;
        }
    }
    return 0;
}

bool solve() {
    memset(cfg,'.',sizeof(cfg));
    cfg[1][1]='c';
    if(rn==1) {
        for(int j=safe+1;j<=cn;j++)
            cfg[1][j]='*';
        return 1;
    }
    if(cn==1) {
        for(int i=safe+1;i<=rn;i++)
            cfg[i][1]='*';
        return 1;
    }
    memset(vis,0,sizeof(vis));
    return dfs(0,cn,0);
}

int main(void)
{
    int t,cas;
    RI(t);
    for(cas=1;cas<=t;cas++) {
        RIII(rn,cn,mine);
        safe=rn*cn-mine;
        printf("Case #%d:\n",cas);
        if(!solve()) puts("Impossible");
        else {
            for(int i=1;i<=rn;i++) {
                cfg[i][cn+1]='\0';
                puts(cfg[i]+1);
            }
        }
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

