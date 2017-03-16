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
typedef pair<string,string> pss;
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

#define MAXL 20

int len;
char a[MAXL],b[MAXL];

// a <= b
pss sub(char *a, char *b, int x) {
    string aa=a, bb=b;
    if(a[x]=='?'&&b[x]=='?') {
        aa[x]='0';
        bb[x]='1';
    } else if(a[x]=='?') {
        aa[x]=max((char)(bb[x]-1), '0');
    } else if(b[x]=='?') {
        bb[x]=min((char)(aa[x]+1), '9');
    }
    //
    for(int i=x+1;i<len;i++) {
        if(aa[i]=='?') aa[i]='9';
        if(bb[i]=='?') bb[i]='0';
    }
    for(int i=0;i<x;i++) {
        if(aa[i]=='?'&&bb[i]=='?') aa[i]=bb[i]='0';
        else {
            if(aa[i]=='?') aa[i]=bb[i];
            if(bb[i]=='?') bb[i]=aa[i];
        }
    }
    return MP(aa,bb);
}

bool cmp(pss as, pss bs) {
    //long long a1 = stoll(as.F);
    //long long a2 = stoll(as.S);
    //long long b1 = stoll(bs.F);
    //long long b2 = stoll(bs.S);
    long long a1,a2,b1,b2;
    stringstream(as.F) >> a1;
    stringstream(as.S) >> a2;
    stringstream(bs.F) >> b1;
    stringstream(bs.S) >> b2;
    if(abs(a1-a2)!=abs(b1-b2)) return abs(a1-a2)<abs(b1-b2);
    if(a1!=b1) return a1<b1;
    return a2<b2;
}

void solve() {
    bool first=true;
    pss opt;
    len=strlen(a);
    for(int i=0;i<=len;i++) {
        pss sol1 = sub(a,b,i);
        pss sol2 = sub(b,a,i);
        sol2 = MP(sol2.S,sol2.F);
        if(first||cmp(sol1,opt)) {
            opt=sol1;
            first=false;
        }
        if(first||cmp(sol2,opt)) {
            opt=sol2;
            first=false;
        }
    }
    cout << opt.F << ' ' << opt.S << endl;
}

int main(void)
{
    int t;
    RI(t);
    for(int cas=1; cas<=t; cas++) {
        RS(a);
        RS(b);
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread
