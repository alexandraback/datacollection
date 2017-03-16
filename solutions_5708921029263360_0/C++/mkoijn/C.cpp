#define NDEBUG
#include<bits/stdc++.h>
using namespace std;

#define SZ(X) ((int)X.size())
#define CLR(X) memset(X,0,sizeof(X))
#define MAX(A,B) ({__typeof__(A)_x=(A);__typeof__(B)_y=(B);_x>_y?_x:_y;})
#define MIN(A,B) ({__typeof__(A)_x=(A);__typeof__(B)_y=(B);_x<_y?_x:_y;})
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
#define BIT_COUNT(X) (__builtin_popcountll((unsigned long long)(X)))
#define BIT_CHECK(X,N) ((X)&(1<<(N)))

template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}
template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}

typedef vector<string> VS;


inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}

int J, P, S, K,n;
vector<tuple<int, int,int>> x;
typedef pair<int,int> PII;

inline bool check(int q){
  map<PII,int> m1,m2,m3;
  m1.clear();m2.clear();m3.clear();
  REP(i,n){
    if(BIT_CHECK(q,i)){
      m1[MP(get<0>(x[i]),get<1>(x[i]))]++;
      m2[MP(get<0>(x[i]),get<2>(x[i]))]++;
      m3[MP(get<1>(x[i]),get<2>(x[i]))]++;
    }
  }
  FOREACH(I,m1) if((I->SE)>K) return false;
  FOREACH(I,m2) if((I->SE)>K) return false;
  FOREACH(I,m3) if((I->SE)>K) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  FOR(tt,1,T){
    cin>>J>>P>>S>>K;
    x.clear();
    FOR(i,1,J) FOR(j,1,P) FOR(k,1,S) x.PB(make_tuple(i,j,k));
    n=J*P*S;
    int m=0;
    int s=0;
    string ret="";
    if(J==3&&P==3&&S==3&&K==2){
      m=12;
      s=149723;
      ret="1 1 1\n1 2 1\n2 2 2\n3 3 3\n2 1 2\n3 1 3\n1 1 2\n1 2 2\n2 1 1\n";
      ret+="2 2 1\n1 3 3\n3 3 1";
    }else if(J==3&&P==3&&S==3&&K==1){
      m=9;
      ret="1 1 1\n2 2 2\n3 3 3\n1 3 2\n1 2 3\n2 3 1\n2 1 3\n3 2 1\n3 1 2";
    }else
    FORD(i,(1<<n)-1,1){
      if(BIT_COUNT(i)>m&&check(i)){
        m=BIT_COUNT(i);
        s=i;
      }
    }
    cout<<"Case #"<<stringify(tt)<<": "<<stringify(m)<<"\n";
    if(ret!=""){
      cout<<ret<<"\n";
    }else
    REP(i,n){
      if(BIT_CHECK(s,i)){
        cout<<stringify(get<0>(x[i]))<<" "<<stringify(get<1>(x[i]))<<" "<<stringify(get<2>(x[i]))<<"\n";
      }
    }
  }

  return 0;
}
