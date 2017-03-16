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
    fprintf(stderr,"%d ",head);
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

const int len=64;
int a,b,k;
int as[len+1],bs[len+1],ks[len+1];
long long dp[len+1][2][2][2];

long long solve() {
    for(int ta=0;ta<2;ta++)
        for(int tb=0;tb<2;tb++)
            for(int tk=0;tk<2;tk++)
                dp[0][ta][tb][tk]=1;
    for(int x=0;x<len;x++) {
        for(int ta=0;ta<2;ta++) {
            for(int tb=0;tb<2;tb++) {
                for(int tk=0;tk<2;tk++) {
                    dp[x+1][ta][tb][tk]=0;
                    for(int ia=0;ia<2;ia++) {
                        for(int ib=0;ib<2;ib++) {
                            int ik=ia&ib;
                            if(ta&&ia>as[x]) continue;
                            if(tb&&ib>bs[x]) continue;
                            if(tk&&ik>ks[x]) continue;
                            int tta=ta&&(ia==as[x]);
                            int ttb=tb&&(ib==bs[x]);
                            int ttk=tk&&(ik==ks[x]);
                            dp[x+1][ta][tb][tk]+=dp[x][tta][ttb][ttk];
                        }
                    }
                }
            }
        }
    }
    return dp[len][1][1][1];
}

int main(void)
{
    int t,cas;
    RI(t);
    for(cas=1;cas<=t;cas++) {
        RI(a,b,k);
        a--; b--; k--;
        int ta=a,tb=b,tk=k;
        for(int i=0;i<len;i++) {
            as[i]=ta&1;
            bs[i]=tb&1;
            ks[i]=tk&1;
            ta>>=1;
            tb>>=1;
            tk>>=1;
        }
        //as[len]=bs[len]=ks[len]='\0';
        printf("Case #%d: ",cas);
        cout << solve() << endl;
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread

