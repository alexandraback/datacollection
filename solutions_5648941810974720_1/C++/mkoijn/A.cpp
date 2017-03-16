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

template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}
template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}

typedef vector<string> VS;


inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    getline(cin, line);
    string ret="";
    int m[30];
    int t[30];
    FOR(i,0,29) t[i]=m[i]=0;
    FOR(i,0,SZ(line)-1){
      m[line[i]-'A']++;
    }
    t[0]=m['Z'-'A'];
    m['E'-'A']-=m['Z'-'A'];
    m['R'-'A']-=m['Z'-'A'];
    m['O'-'A']-=m['Z'-'A'];
    t[6]=m['X'-'A'];
    m['S'-'A']-=m['X'-'A'];
    m['I'-'A']-=m['X'-'A'];
    t[7]=m['S'-'A'];
    m['E'-'A']-=m['S'-'A'];
    m['V'-'A']-=m['S'-'A'];
    m['E'-'A']-=m['S'-'A'];
    m['N'-'A']-=m['S'-'A'];
    t[5]=m['V'-'A'];
    m['F'-'A']-=m['V'-'A'];
    m['I'-'A']-=m['V'-'A'];
    m['E'-'A']-=m['V'-'A'];
    t[4]=m['F'-'A'];
    m['O'-'A']-=m['F'-'A'];
    m['U'-'A']-=m['F'-'A'];
    m['R'-'A']-=m['F'-'A'];
    t[3]=m['R'-'A'];
    m['T'-'A']-=m['R'-'A'];
    m['H'-'A']-=m['R'-'A'];
    m['E'-'A']-=m['R'-'A'];
    m['E'-'A']-=m['R'-'A'];
    t[2]=m['W'-'A'];
    m['T'-'A']-=m['W'-'A'];
    m['O'-'A']-=m['W'-'A'];
    t[1]=m['O'-'A'];
    m['N'-'A']-=m['O'-'A'];
    m['E'-'A']-=m['O'-'A'];
    t[8]=m['T'-'A'];
    m['E'-'A']-=m['T'-'A'];
    m['I'-'A']-=m['T'-'A'];
    m['G'-'A']-=m['T'-'A'];
    m['H'-'A']-=m['T'-'A'];
    t[9]=m['E'-'A'];
    FOR(i,0,9) if(t[i]){
      FOR(j,1,t[i]){
        ret+=stringify(i);
      }
    }
    cout<<"Case #"<<stringify(tt)<<": "<<ret<<"\n";
  }

  return 0;
}
