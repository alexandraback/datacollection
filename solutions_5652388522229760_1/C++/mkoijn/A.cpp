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

template<class T> inline string stringify(T x,int p=16){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

template <class T> inline
int numDigits(T x){
  int ret=0;
  if(ret==0) return 1;
  while(x){
    x/=10;
    ret++;
  }
  return ret;
}

unordered_set<int> s;

inline
void fill(long long x){
  if(x==0LL) s.insert(0);
  while(x>0){
    int r=x%10;
    x/=10;
    s.insert(r);
  }
  return;
}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    s.clear();
    int x;
    cin>>x;
    getline(cin, line);
    if(x==0) {cout<<"Case #"<<stringify(tt)<<": INSOMNIA\n"; continue;}
    int n=numDigits(x);
    long long max=x;
    while(n--){
      max*=10;
    }
    max*=10;
    long long ret=0;
    for(long long y=x; y<=max; y+=x){
      fill(y);
      ret=y;
      if(10==s.size()) break;
    }
    cout<<"Case #"<<stringify(tt)<<": "<<(10==s.size()?stringify(ret):"INSOMNIA")<<"\n";
  }

  return 0;
}
