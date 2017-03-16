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

typedef long long ll;
typedef vector<long long> VI;

template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoll(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoll(a.c_str()));return wyn;}

string s;
int sn;
ll L, X;

inline char cc(long long i){
  int p=(int)(i%sn);
  return s[p];
}

// I=-i, J=-j, K=-k, -=-1
inline char qq(char from, char to){
  if(from=='-'){
    if(to=='-'){
      return '1';
    }else if(to=='I'){
      return 'i';
    }else if(to=='J'){
      return 'j';
    }else if(to=='K'){
      return 'k';
    }else if(to=='i'){
      return 'I';
    }else if(to=='j'){
      return 'J';
    }else if(to=='k'){
      return 'K';
    }else{//1
      return '-';
    }
  }else if(from=='I'){
    if(to=='-'){
      return 'i';
    }else if(to=='I'){
      return '-';
    }else if(to=='J'){
      return 'k';
    }else if(to=='K'){
      return 'J';
    }else if(to=='i'){
      return '1';
    }else if(to=='j'){
      return 'K';
    }else if(to=='k'){
      return 'j';
    }else{//1
      return 'I';
    }
  }else if(from=='J'){
    if(to=='-'){
      return 'j';
    }else if(to=='I'){
      return 'K';
    }else if(to=='J'){
      return '-';
    }else if(to=='K'){
      return 'i';
    }else if(to=='i'){
      return 'k';
    }else if(to=='j'){
      return '1';
    }else if(to=='k'){
      return 'I';
    }else{//1
      return 'J';
    }
  }else if(from=='K'){
    if(to=='-'){
      return 'k';
    }else if(to=='I'){
      return 'j';
    }else if(to=='J'){
      return 'I';
    }else if(to=='K'){
      return '-';
    }else if(to=='i'){
      return 'J';
    }else if(to=='j'){
      return 'i';
    }else if(to=='k'){
      return '1';
    }else{//1
      return 'K';
    }
  }else if(from=='i'){
    if(to=='-'){
      return 'I';
    }else if(to=='I'){
      return '1';
    }else if(to=='J'){
      return 'K';
    }else if(to=='K'){
      return 'j';
    }else if(to=='i'){
      return '-';
    }else if(to=='j'){
      return 'k';
    }else if(to=='k'){
      return 'J';
    }else{//1
      return 'i';
    }
  }else if(from=='j'){
    if(to=='-'){
      return 'J';
    }else if(to=='I'){
      return 'k';
    }else if(to=='J'){
      return '1';
    }else if(to=='K'){
      return 'I';
    }else if(to=='i'){
      return 'K';
    }else if(to=='j'){
      return '-';
    }else if(to=='k'){
      return 'i';
    }else{//1
      return 'j';
    }
  }else if(from=='k'){
    if(to=='-'){
      return 'K';
    }else if(to=='I'){
      return 'J';
    }else if(to=='J'){
      return 'i';
    }else if(to=='K'){
      return '1';
    }else if(to=='i'){
      return 'j';
    }else if(to=='j'){
      return 'I';
    }else if(to=='k'){
      return '-';
    }else{//1
      return 'k';
    }
  }else{//1
    if(to=='-'){
      return '-';
    }else if(to=='I'){
      return 'I';
    }else if(to=='J'){
      return 'J';
    }else if(to=='K'){
      return 'K';
    }else if(to=='i'){
      return 'i';
    }else if(to=='j'){
      return 'j';
    }else if(to=='k'){
      return 'k';
    }else{//1
      return '1';
    }
  }
}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    getline(cin, line);
    VI x=parsei(line);
    L=x[0], X=x[1];
    getline(cin, line);
    s=line, sn=SZ(s);
    int k=6;
    if(X<k) k=X;
    char w1='1';
    for(int i=0; i<sn; i++){
      w1=qq(w1,cc(i));
    }
    char w2='1';
    char det='i';
    char sig='1';
    for(int i=0; i<sn*k; i++){
      w2=qq(w2,cc(i));
      if(det=='i'){
        if('i'==w2){
          det='j';
          w2='1';
        }else if('I'==w2){
          det='j';
          w2='1';
          if('1'==sig){
            sig='-';
          }else{
            sig='1';
          }
        }
      }else if(det=='j'){
        if('j'==w2){
          det='k';
          w2='1';
        }else if('J'==w2){
          det='k';
          w2='1';
          if('1'==sig){
            sig='-';
          }else{
            sig='1';
          }
        }
      }else if(det=='k'){
        if('k'==w2){
          det='x';
          w2='1';
        }else if('K'==w2){
          det='x';
          w2='1';
          if('1'==sig){
            sig='-';
          }else{
            sig='1';
          }
        }
      }
    }
    string ret="NO";
    if('x'==det){
      int r=(X-k)%4;
      if(2==r){
        if('1'==w1||'-'==w1){
          w1='1';
        }else{
          w1='-';
        }
      }else if(3==r){
        if('i'==w1){
          w1='I';
        }else if('I'==w1){
          w1='i';
        }else if('j'==w1){
          w1='J';
        }else if('J'==w1){
          w1='j';
        }else if('k'==w1){
          w1='K';
        }else if('K'==w1){
          w1='k';
        }
      }else if(0==r){
        w1='1';
      }
      w2=qq(w2,w1);
      if(('-'==w2&&'-'==sig)||('1'==w2&&'1'==sig)) ret="YES";
    }
    cout<<"Case #"<<stringify(tt)<<": "<<ret<<"\n";
  }

  return 0;
}
