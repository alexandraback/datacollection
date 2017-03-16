#define NDEBUG
#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;

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
#define BIT_CHECK(X,N) ((X)&(1<<(N)))

template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}
template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}

typedef vector<string> VS;
typedef vector<pair<string,string>> VSS;


inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}

unordered_map<string, int> f,s;

inline int numf(const string &x){
  if(f.find(x)==f.end()) return 0;
  return f[x];
}

inline int nums(const string &x){
  if(s.find(x)==s.end()) return 0;
  return s[x];
}

#define DEB 0
inline bool debc(int x){
  bool ret=true;
  FOR(i,0,15) if(i!=1&&i!=8){
    if(BIT_CHECK(x,i)) ret=false;
  }
  return ret&&BIT_CHECK(x,1)&&BIT_CHECK(x,8);
}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    int N;
    cin>>N;
    VSS q;
    f.clear(), s.clear();
    getline(cin, line);
    int ret=0;
    FOR(i,1,N){
      getline(cin, line);
      VS x=parse(line);
      q.PB(MP(x[0],x[1]));
      f[x[0]]++;
      s[x[1]]++;
    }
    if(DEB){
      FOREACH(I,f) cout<<"f "<<I->FI<<" "<<I->SE<<"\n";
      FOREACH(I,s) cout<<"s "<<I->FI<<" "<<I->SE<<"\n";
    }
    FOR(i,0,(1<<N)-1){
      unordered_map<string, int> f2=f,s2=s;
      bool ok=true;
      int c=0;
      FOR(j,0,N-1){
        if(BIT_CHECK(i,j)){
          c++;
          f2[q[j].FI]--;
          s2[q[j].SE]--;
          if(DEB && debc(i)){
            cout<<"d "<<stringify(j)<<" "<<stringify(c)<<" "<<stringify(f2[q[j].FI])<<" "<<stringify(s2[q[j].SE])<<"\n";
          }
          if(f2[q[j].FI]<=0){
            ok=false;
            break;
          }
          if(s2[q[j].SE]<=0){
            ok=false;
            break;
          }
        }
      }
      if(ok){
        if(c>ret) ret=c;
      }
    }

    cout<<"Case #"<<stringify(tt)<<": "<<stringify(ret)<<"\n";
  }

  return 0;
}
