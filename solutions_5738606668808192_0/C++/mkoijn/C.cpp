#include<iostream>
#include<complex>
#include<vector>
#include<string>

#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<sstream>
#include<unistd.h>
#include<valarray>
#include<numeric>
#include<algorithm>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>

#include<fstream>
#include<time.h>
#include<unordered_set>
using namespace std;

#define BIG_TEST 0

#define NDEBUG
#include<assert.h>
#define SZ(X) ((int)X.size())
#define CLR(X) memset(X,0,sizeof(X))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MOD(A,B) (((A)%(B)+(B))%(B))
#define MP make_pair
#define FI first
#define SE second
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define RFOREACH(I,C) for(VAR(I,(C).rbegin());I!=(C).rend();I++)
#define ALL(X) (X).begin(),(X).end()
#define SRT(X) sort((X).begin(),(X).end())
#define PB push_back

typedef vector<string> VS;
typedef vector<int> VI;

template<class T> inline string stringify(T x,int p=32){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

typedef long long ll;

struct BigNum{
  #define REDUCE() while(len>1 && !cyf[len-1]) len--;
  #define OPER1(op) bool operator op (const BigNum &a) const
  #define OPER2(op) BigNum& operator op (const BigNum &a)
  #define OPER3(op) BigNum operator op(const BigNum &a) const {BigNum w=*this;w op ## = a; return w;}
  #define OPER4(op) BigNum operator op(int a) {BigNum w = *this; w op ## = a;return w;}
  static const int BASE=1000000000,BD=9;int len,al;ll* cyf;
  BigNum(int v=0,int l=2):len(1),al(l),cyf(new ll[l]){REP(x,al) cyf[x]=0;if((cyf[0]=v)>=BASE) przen(1);}
  BigNum(const BigNum &a):len(a.len),al(len),cyf(new ll[al]){REP(x,al) cyf[x]=a.cyf[x];}
  ~BigNum(){delete cyf;}
  void res(int l){if(l>al){ll* n=new ll[l=MAX(l,2*al)];REP(x,l) n[x]=x>=al?0:cyf[x];delete cyf;cyf=n;al=l;}}
  void przen(int p){int	x=0;for(;x<p||cyf[x]<0||cyf[x]>=BASE;x++){res(x+2);if(cyf[x]<0){ll i=(-cyf[x]-1)/BASE+1;cyf[x]+=i*BASE;cyf[x+1]-=i;}else if(cyf[x]>=BASE){ll i=cyf[x]/BASE;cyf[x]-=i*BASE;cyf[x+1]+=i;}}len=max(len,x+1);REDUCE();}
  OPER1(==){if(a.len!=len) return 0;REP(x,len) if(cyf[x]!=a.cyf[x]) return 0;return 1;}
  OPER1(<){if(len!=a.len) return len<a.len;int x=len-1;while(x&&a.cyf[x]==cyf[x]) x--;return cyf[x]<a.cyf[x];}
  OPER1(>){return a<*this;}
  OPER1(<=){return !(a<*this);}
  OPER1(>=){return !(*this<a);}
  OPER1(!=){return !(*this==a);}
  BigNum &operator=(int a){REP(x,len) cyf[x]=0;len=1;if((cyf[0]=a)>=BASE) przen(1);return *this;}
  void operator+=(int a){cyf[0]+=a;przen(1);}
  void operator-=(int a){cyf[0]-=a;przen(1);}
  void operator++(){cyf[0]+=1;przen(1);}
  void operator--(){cyf[0]-=1;przen(1);}
  void operator*=(int a){REP(x,len) cyf[x]*=a;przen(len);}
  int operator/=(int a){ll w=0;FORD(p,len-1,0){w=w*BASE+cyf[p]; cyf[p]=w/a; w%=a;}REDUCE();return w;}
  int operator%(int a){ll w=0;FORD(p,len-1,0) w=(w*BASE+cyf[p])%a;return w;}
  OPER2(+=){res(a.len);REP(x,a.len) cyf[x]+=a.cyf[x];przen(a.len);return *this;}
  OPER2(-=){REP(x,a.len) cyf[x]-=a.cyf[x]; przen(a.len);return *this;}
  OPER2(*=){BigNum c(0,len+a.len);REP(x,a.len){REP(y,len) c.cyf[y+x]+=cyf[y]*a.cyf[x];c.przen(len+x);}*this=c;return *this;}
  OPER2(/=){int n=max(len-a.len+1,1);BigNum d(0,n),prod;FORD(i,n-1,0){int l=0,r=BASE-1;while(l<r){int	m=(l+r+1)/2;if(*this < prod+(a*m<<i))r=m-1;else l=m;}prod+=a*l<<i;d.cyf[i]=l;if(l) d.len=max(d.len, i+1);}*this=d;return *this;}
  OPER2(%=){BigNum v=*this;v/=a;v*=a;*this-=v;return *this;}
  OPER2(=){res(a.len);FORD(x,len-1,a.len) cyf[x]=0;REP(x,a.len) cyf[x]=a.cyf[x];len=a.len;return *this;}
  void read(const VI &v,int p){*this=0;FORD(x,SZ(v),0) {*this*=p;*this+=v[x];}}
  BigNum &operator=(string a){int s=a.length();*this=0;res(len=s/BD+1);REP(x,s) cyf[(s-x-1)/BD]=10*cyf[(s-x-1)/BD]+a[x]-'0';REDUCE();return *this;}
  void write() const{printf("%d",int(cyf[len-1]));FORD(x,len-2,0) printf("%0*d",BD,int(cyf[x]));}
  void write(char *buf) const{int p=sprintf(buf,"%d",int(cyf[len-1]));FORD(x,len-2,0) p+=sprintf(buf+p, "%0*d", BD, int(cyf[x]));}
  VI write(int pod) const{VI w;BigNum v;v=*this;while(v.len>1||v.cyf[0]) w.PB(v/=pod);return w;}
  string stringify(){char c[al+1];write(c);return string(c);}
  BigNum &operator>>=(int n){if(n>=len) n=len;REP(x,len-n) cyf[x]=cyf[x+n];FOR(x,len-n,n) cyf[x]=0;len-=n;if(len==0) len=1;return *this;}
  BigNum &operator<<=(int n){if(cyf[0]==0 && len==1) return *this;res(len+n);FORD(x,len-1,0) cyf[x+n]=cyf[x];REP(x,n) cyf[x]=0;len+=n;return *this;}
  BigNum sqrt(){int n=(len+1)/2;BigNum a(0,n),sq;FORD(i,n-1,0){int l=0,r=BASE-1;while(l<r){int m=(l+r+1)/2;if(*this<sq+(a*2*m<<i)+(BigNum(m)*m<<2*i))r=m-1;else l=m;}sq+=(a*2*l<<i)+(BigNum(l)*l<<2*i);a.cyf[i]=l;a.len=n;}return a;}
  OPER3(+);OPER3(-);OPER3(*);OPER3(/);OPER3(%);OPER4(<<);OPER4(>>);
};

inline bool MRtest(BigNum x,BigNum n){if(x>=n) return 0;BigNum d=1,y,l=n-1;int t=0;bool st=0;while((l%2)==0){++t;l/=2;} for(;l>0||t--;l/=2){if((l%2)==1) d=(d*x)%n; else if(!st&&l==0){st=1; x=d;}y=(x*x)%n;if(y==1&&x!=1&&x!=n-1) return 1;x=y;}return x!=1;}
inline bool isPrime(const BigNum& x,int t=-1){if(t==-1){char buf[x.BD+3];t=sprintf(buf,"%d",int(x.cyf[x.len-1]));FORD(n,x.len-2,0) t+=sprintf(buf,"%0*d",x.BD,int(x.cyf[n]));t=MAX(t,20);}if(x<2||MRtest(2,x)||MRtest(3,x)||MRtest(5,x)||MRtest(7,x)) return 0;t-=4;REP(i,t) if(MRtest(min(rand(),11),x)) return 0;return 1;}

#define BIT_CHECK(X,N) ((X)&(1<<(N)))
#define BIT_SET(X,N) ((X)|=(1<<(N)))
#define BIT_HIGHEST(X) (31-__builtin_clz((unsigned int)(X)))

int N=16;
int J=50;
unsigned int q=1U;
string qs="";

BigNum v[11];

#define DEB 0

inline void construct(){
  BigNum x2(0,32),x3(0,32),x4(0,32),x5(0,32),x6(0,32),x7(0,32),x8(0,32),x9(0,32),x10(0,32);
  qs="";
  FORD(i,N-1,0){
    x2*=2;x3*=3;x4*=4;x5*=5;x6*=6;x7*=7;x8*=8;x9*=9;x10*=10;
    if(BIT_CHECK(q,i)){
      x2+=1;x3+=1;x4+=1;x5+=1;x6+=1;x7+=1;x8+=1;x9+=1;x10+=1;
      qs+="1";
    } else qs+="0";
  }
  v[2]=x2;v[3]=x3;v[4]=x4;v[5]=x5;v[6]=x6;v[7]=x7;v[8]=x8;v[9]=x9;v[10]=x10;
  if(DEB) {
    cout<<"K "<<qs<<" "<<stringify(q)<<"\n";
    string ret=qs+" "+v[2].stringify()+" "+v[3].stringify()+" "+v[4].stringify()+" "+v[5].stringify()+" "+v[6].stringify()+" "+v[7].stringify()+" "+v[8].stringify()+" "+v[9].stringify()+" "+v[10].stringify();
    cout<<ret+"\n"<<flush;
  }
}

inline bool notPrime(){
  bool ret=true;
  FOR(i,2,10){
    if(isPrime(v[i])){
      if(DEB){
        string ret2="prime: "+v[i].stringify();
        cout<<ret2+"\n"<<flush;
      }
      ret=false;
      break;
    }
  }
  return ret;
}

inline void pisz(){
  BigNum d(2);
  BigNum sent(0);
  vector<bool> wb(9,true);
  vector<BigNum> w(9,sent);
  while(1){
    bool con=false;
    if(wb[0]){
      w[0]=v[2];
      if((w[0]%=d)==0) {w[0]=d; wb[0]=false; if(DEB) {cout<<"w0 "<<w[0].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[1]){
      w[1]=v[3];
      if((w[1]%=d)==0) {w[1]=d; wb[1]=false; if(DEB) {cout<<"w1 "<<w[1].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[2]){
      w[2]=v[4];
      if((w[2]%=d)==0) {w[2]=d; wb[2]=false; if(DEB) {cout<<"w2 "<<w[2].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[3]){
      w[3]=v[5];
      if((w[3]%=d)==0) {w[3]=d; wb[3]=false; if(DEB) {cout<<"w3 "<<w[3].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[4]){
      w[4]=v[6];
      if((w[4]%=d)==0) {w[4]=d; wb[4]=false; if(DEB) {cout<<"w4 "<<w[4].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[5]){
      w[5]=v[7];
      if((w[5]%=d)==0) {w[5]=d; wb[5]=false; if(DEB) {cout<<"w5 "<<w[5].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[6]){
      w[6]=v[8];
      if((w[6]%=d)==0) {w[6]=d; wb[6]=false; if(DEB) {cout<<"w6 "<<w[6].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[7]){
      w[7]=v[9];
      if((w[7]%=d)==0) {w[7]=d; wb[7]=false; if(DEB) {cout<<"w7 "<<w[7].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(wb[8]){
      w[8]=v[10];
      if((w[8]%=d)==0) {w[8]=d; wb[8]=false; if(DEB) {cout<<"w8 "<<w[8].stringify()<<" "<<d.stringify()<<"\n";}} else con=true;
    }
    if(con){
      d+=1;
    }else{
      break;
    }
  }
  string ret="";
  if(DEB) ret="JAM! ";
  ret+=qs+" "+w[0].stringify()+" "+w[1].stringify()+" "+w[2].stringify()+" "+w[3].stringify()+" "+w[4].stringify()+" "+w[5].stringify()+" "+w[6].stringify()+" "+w[7].stringify()+" "+w[8].stringify();
  cout<<ret+"\n"<<flush;
}

int main(){
  srand(time(NULL));
  if(BIG_TEST){
    N=32;
    J=500;
  }
  //N=6;J=3; //test
  
  cout<<"Case #1:\n";
  BIT_SET(q,N-1);
  if(DEB) printf("%u\n",q);
  while(J){
    construct();
    if(notPrime()){
      if(DEB) cout<<"NOT PRIME\n";
      J--;
      pisz();
    }
    q+=2;
  }
  
  return 0;
}
