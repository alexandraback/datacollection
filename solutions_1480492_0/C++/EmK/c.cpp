// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";


ll_t gcd(ll_t s,ll_t t) { return t ? gcd(t , s%t) : max(s,-s); }
ll_t lcm(ll_t s,ll_t t) { return s/gcd(s,t)*t; }
struct rational{
  mutable ll_t a,b;
  rational(ll_t aa=0,ll_t bb=1) : a(aa),b(bb){
    if(b<0) {
      a = -a ;  b = -b ;
    }
    reduce();
  }
  rational(string s){
    if(s.find('/')==string::npos){
      istringstream in(s);
      in>>a; b=1;
    }else{
      s[s.find('/')]=' ';
      istringstream in(s);
      in>>a>>b; if(b==0) abort();
    }
    if(b<0) {
      a = -a ;  b = -b ;
    }
    reduce();
  }
  void reduce() const{
    if(a==0){
      b=1;
    }else{
      ll_t g = gcd(a,b);
      a/=g ; b/=g;
    }
  }
  double get_value() const {
    return 1.0 * a / b ; 
  }
  rational inverse(){
    return rational(b,a);
  }
  friend rational operator+(const rational &r1 , const rational&r2){
    ll_t l = lcm(r1.b,r2.b);
    ll_t v = r1.a * (l / r1.b) + r2.a * (l / r2.b) ;
    return rational(v , l);
  }
  friend rational operator-(const rational &r1 , const rational&r2){
    ll_t l = lcm(r1.b,r2.b);
    ll_t v = r1.a * (l / r1.b) - r2.a * (l / r2.b) ;
    return rational(v , l);
  }
  friend rational operator*(const rational &r1 , const rational&r2){
    return rational(r1.a*r2.a , r1.b*r2.b);
  }
  friend rational operator/(const rational &r1 , const rational&r2){
    return rational(r1.a*r2.b , r1.b*r2.a);
  }
  rational operator + () {
    return rational(a,b) ; 
  }
  rational operator - () {
    return rational(-a,b);
  }
  friend long long compare(const rational &r1 , const rational&r2) {
    return r1.a*r2.b-r2.a*r1.b;
  }

#define DEF_OP(op)                             \
  rational& operator op##= (const rational &r)        \
  { return *this = (*this) op r ; }
  DEF_OP(+) DEF_OP(-)  DEF_OP(*) DEF_OP(/)
#undef DEF_OP

#define DEF_COMP(op)                                                    \
  friend bool operator op (const rational& r1 , const rational& r2)     \
  { return compare(r1,r2) op 0 ; }                                      

  DEF_COMP(==) DEF_COMP(!=) DEF_COMP(>=) DEF_COMP(<=) DEF_COMP(>) DEF_COMP(<) 
#undef DEF_COMP

  friend ostream& operator<<(ostream& o , rational r){
    if(r.b==1) return o << r.a ;
    return o << r.a << "/" << r.b ;
  }
};

rational get_collide_time(int p1 , int v1 , int p2 , int v2)
{
  if(v1 == v2) return -1;
  // p1 + t*v1 == p2 + t*v2
  // t(v1-v2) = p2-p1;
  rational r = rational(p2 - p1 , v1 - v2);
  if(r < 0) return -1;
  return r;
}

char C[55];
int S[55],P[55];

double memo[10000][1<<6];

bool isLeft(int rane , int p){
  return (rane & (1<<p)) == 0;
}

string tostr(int N , int d){
  string s;
  FOR(i,N){
    if(isLeft(d , i)) s += 'L' ; else s += 'R';
  }
  return s;
}

double dfs(int N , vector<rational>& time , int pos = 0 , int rane = 0){
  if(pos + 1 >= SZ(time)){
    return 1e20;
  }
  double& ret = memo[pos][rane];
  if(!isnan(ret)) return ret;
  double val = -1 ;
  
  vector<rational> car(N , 0);
  rational t = (time[pos] + time[pos+1]) / 2;
  FOR(i,N){
    car[i] = P[i] + S[i] * t;
  }
  vector<bool> both(N , true);
  FOR(i,N) FOR(j,i){
    rational d = car[i] - car[j];
    if( d > -5 && d < 5){
      if(isLeft(rane , i) == isLeft(rane , j)){ // collide
        return val = time[pos].get_value();
      }
      both[i] = both[j] = false;
    }
  }
  //cout<<time[pos]<<" "<<tostr(N , rane)<<endl;
  FOR(newRane , 1<<N){
    bool ok = true;
    FOR(i,N){
      if(both[i] == false){
        if(isLeft(rane , i) != isLeft(newRane , i)){
          ok = false; break;
        }
      }
    }
    if(!ok) continue;
    double sub = dfs(N , time , pos+1 , newRane);
    if(val < sub) val = sub;
  }
  return ret = val;
}

vector<rational> d(vector<rational> dat){
  vector<rational> ret;
  FOR(i,SZ(dat)) {
    ret.push_back(dat[i]);
    ret.push_back(dat[i]);
  }
  return ret;
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    int N;
    cin>>N;
    int init = 0;
    FOR(i,N){
      cin>>C[i]>>S[i]>>P[i];
      if(C[i]=='R') init |= (1<<i);
    }
    vector<rational> time;
    FOR(i,N) FOR(j,i){
      rational r = -1 ; 
      r = get_collide_time(P[i] , S[i] , P[j] - 5 , S[j]);
      if(r != -1) time.push_back(r);
      r = get_collide_time(P[i] , S[i] , P[j] + 5 , S[j]);
      if(r != -1) time.push_back(r);
    }
    time.push_back(0);
    sort(ALL(time));
    time.erase(unique(time.begin(),time.end()),time.end());
    time.push_back(time.back() + 2);
    time = d(time);
    /*FOR(i,SZ(time)){
      cout<<time[i]<<endl;
      }*/
    memset(memo , -1 , sizeof(memo));
    double ans = dfs(N, time , 0 , init);
    if(ans > 1e19){
      printf("Case #%d: Possible\n" , case_no++);
    }else{
      printf("Case #%d: %.10f\n" , case_no++ , ans);
    }
    
  }
  return 0 ;
}
