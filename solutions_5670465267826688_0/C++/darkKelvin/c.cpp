// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
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

#define MAXL 10050


class Qtn {
    public:
        int sg;
        char qt;
        Qtn() {}
        Qtn(int sg,char qt): sg(sg),qt(qt) {}
        Qtn& operator*=(const Qtn &b);
        Qtn operator*(const Qtn &b) const {
            return Qtn(*this)*=b;
        }
        bool operator==(const Qtn &b) const {
            return sg==b.sg&&qt==b.qt;
        }
        static int qt2i(char c) {
            if(c=='1') return 0;
            if(c=='i') return 1;
            if(c=='j') return 2;
            if(c=='k') return 3;
            assert(false);
        }
        int toi() {
            return (sg==1?0:1)*4+qt2i(qt);
        }
};

class State {
    public:
        int ml;
        Qtn qtn;
        State() {}
        State(int ml, Qtn qtn): ml(ml),qtn(qtn) {}
        int toi() {
            return ml*8+qtn.toi();
        }
        string tos() {
            char s[20];
            sprintf(s,"(%d,%c%c)",ml,qtn.sg==-1?'-':'+',qtn.qt);
            return s;
        }
        bool matching() const {
            //if(qtn.sg!=1) return 0;
            if(ml==0) return qtn==Qtn(1,'1');
            if(ml==1) return qtn==Qtn(1,'i');
            if(ml==2) return qtn==Qtn(1,'j');
            //if(ml==3) return qtn==Qtn(1,'k');
            return 0;
        }
        vector<State> operator*(const char &b) const {
            vector<State> ss;
            ss.PB(State(ml,qtn*Qtn(1,b)));
            if(matching()) ss.PB(State(ml+1,Qtn(1,b)));
            return ss;
        }
};

const char sym[]="1ijk";
Qtn tbl[200][200];
State stateval[32];
void init() {
    const char str[]=" 1 i j k i-1 k-j j-k-1 i k j-i-1";
    for(int i=0;i<4;i++) {
        char si = sym[i];
        for(int j=0;j<4;j++) {
            char sj = sym[j];
            int t = (i*4+j)*2;
            char sg = (str[t]=='-')?-1:1;
            char qt = str[t+1];
            tbl[si][sj]=Qtn(sg,qt);
        }
    }
    //
    int sti=0;
    for(int ml=0;ml<4;ml++) {
        for(int sg=1;sg>=-1;sg-=2) {
            for(int qi=0;qi<4;qi++) {
                char qt=sym[qi];
                State st = State(ml,Qtn(sg,qt));
                stateval[sti++] = st;
            }
        }
    }
}
Qtn cmult(char a,char b) {
    return tbl[a][b];
}
Qtn& Qtn::operator*=(const Qtn &b) {
    Qtn t = cmult(qt,b.qt);
    qt = t.qt;
    sg = sg*b.sg*t.sg;
    return *this;
}

const int nstate=32;

int len,rep;
char s[MAXL];
bool tr[nstate][nstate];

bool solve() {
    bool tt[2][nstate];
    bool *t0=tt[0], *t1=tt[1];
    for(int ss=0;ss<32;ss++) {
        for(int b=0;b<nstate;b++)
            t0[b]=0;
        t0[ss]=1;
        for(int i=0;i<len;i++) {
            char c=s[i];
            for(int b=0;b<nstate;b++)
                t1[b]=0;
            for(int si=0;si<nstate;si++) {
                if(!t0[si]) continue;
                State s0=stateval[si];
                vector<State> nxt=s0*c;
                /*printf("State: %s, char: %c\n>",s0.tos().c_str(),c);
                for(int j=0;j<nxt.size();j++) {
                    printf(" %s",nxt[j].tos().c_str());
                } puts("");*/
                for(auto ns:nxt) {
                    t1[ns.toi()]=1;
                }
            }
            swap(t0,t1);
        }
        for(int b=0;b<nstate;b++)
            tr[ss][b]=t0[b];
    }
    //
    /*for(int i=0;i<4;i++) {
        for(int j=0;j<32;j++) {
            //printf("%d ",(int)tr[i][j]); puts("");
            if(tr[i][j]) {
                printf("%s -> %s\n",stateval[i].tos().c_str(),stateval[j].tos().c_str());
            }
        }
    }*/
    //
    for(int b=0;b<nstate;b++)
        t0[b]=0;
    t0[0]=1;
    for(int t=0;t<rep;t++) {
        for(int b=0;b<nstate;b++)
            t1[b]=0;
        for(int i=0;i<nstate;i++) {
            if(!t0[i]) continue;
            for(int j=0;j<nstate;j++)
                if(tr[i][j]) t1[j]=1;
        }
        swap(t0,t1);
    }
    return t0[State(3,Qtn(1,'k')).toi()];
}

int main(void)
{
    int t;
    init();
    RI(t);
    for(int cas=1;cas<=t;cas++) {
        RI(len,rep);
        RS(s);
        string sol=solve()?"YES":"NO";
        printf("Case #%d: %s\n",cas,sol.c_str());
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread
