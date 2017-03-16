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
template<class T> inline T ABS(T x){return x<0?-x:x;}

typedef vector<string> VS;


inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}

inline int cyf(int x, int d){
  FOR(i,1,d) x/=10;
  return x%10;
}

inline int len(int x){
  if(x==0) return 1;
  int r=0;
  while(x>0){
    x/=10;
    r++;
  }
  return r;
}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    getline(cin, line);
    VS x=parse(line);
    int n=0, m=0;
    int r=1000000;
    int w1=10000000, w2=10000000;
    int d11=-1,d12=-1,d13=-1,d21=-1,d22=-1,d23=-1;
    if(SZ(x[0])==1) {
      n=9;
      d11=(x[0][0]=='?'?-1:x[0][0]-'0');
    }
    else if(SZ(x[0])==2) {
      n=99;
      d11=(x[0][1]=='?'?-1:x[0][1]-'0');
      d12=(x[0][0]=='?'?-1:x[0][0]-'0');
    }
    else if(SZ(x[0])==3) {
      n=999;
      d11=(x[0][2]=='?'?-1:x[0][2]-'0');
      d12=(x[0][1]=='?'?-1:x[0][1]-'0');
      d13=(x[0][0]=='?'?-1:x[0][0]-'0');
    }
    if(SZ(x[1])==1) {
      m=9;
      d21=(x[1][0]=='?'?-1:x[1][0]-'0');
    }
    else if(SZ(x[1])==2) {
      m=99;
      d21=(x[1][1]=='?'?-1:x[1][1]-'0');
      d22=(x[1][0]=='?'?-1:x[1][0]-'0');
    }
    else if(SZ(x[1])==3) {
      m=999;
      d21=(x[1][2]=='?'?-1:x[1][2]-'0');
      d22=(x[1][1]=='?'?-1:x[1][1]-'0');
      d23=(x[1][0]=='?'?-1:x[1][0]-'0');
    }
//cout<<"dupa "<<stringify(d11)<<" "<<stringify(d12)<<" "<<stringify(d13)<<" "<<stringify(d21)<<" "<<stringify(d22)<<" "<<stringify(d23)<<"\n";
    FOR(i,0,n){
      if((d11==-1||d11==cyf(i,0))&&(d12==-1||d12==cyf(i,1))&&(d13==-1||d13==cyf(i,2))){
        FOR(j,0,m){
          if((d21==-1||d21==cyf(j,0))&&(d22==-1||d22==cyf(j,1))&&(d23==-1||d23==cyf(j,2))){
            int r2=ABS(i-j);
            bool ok=false;
            if(r2<r){
              ok=true;
            }else if(r2==r){
              if(i<w1){
                ok=true;
              }else if(i==w1){
                if(j<w2){
                  ok=true;
                }
              }
            }
            if(ok){
              r=r2;
              w1=i;
              w2=j;
            }
          }
        }
      }
    }
    int qq1=SZ(x[0])-len(w1);
    int qq2=SZ(x[1])-len(w2);
    string s1="";
    FOR(i,1,qq1){
      s1+="0";
    }
    string s2="";
    FOR(i,1,qq2){
      s2+="0";
    }
    cout<<"Case #"<<stringify(tt)<<": "<<s1<<stringify(w1)<<" "<<s2<<stringify(w2)<<"\n";
  }

  return 0;
}
