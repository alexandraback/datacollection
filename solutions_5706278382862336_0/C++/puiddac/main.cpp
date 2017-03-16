

#include <iostream>
#include <iomanip> //setprecision
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <iterator> //istream_iterator
//#include <boost/algorithm>
//#include <boost/algorithm/string/split.hpp>

using namespace std;

#define REP(i,N) for(int i=0;i<(N);i++)
#define FOR(i,A,B) for(int i=(A);i<=(B);i++)
#define ROF(i,A,B) for(int i=(B);i>=(A);i--)
#define ALL(A) (A).begin(),(A).end()

#define ISIi std::istream_iterator<int>
#define ISS std::istringstream
#define cinL2B(L,B) getline(cin,L); B.clear(); B.str(L);

typedef pair<int,int> pi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vi> > vvvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef queue<pi> qpi;
typedef set<int> si;
typedef set<pi> spi;
typedef set<si> ssi;


long double P,Q;

int main(){
  int T,nr;
  string line;
  ISS buffer;
  string tmpP,tmpQ;
  int delim;
  
  getline(cin,line); istringstream(line)>>T;
  for(nr=0;nr<T;nr++){
    //getline(cin,line); istringstream(line)>>N;
    getline(cin,line);
    delim=line.find('/');
    tmpP=line.substr(0,delim);
    buffer.clear(); buffer.str(tmpP); buffer>>P;
    tmpQ=line.substr(delim+1,line.size());
    buffer.clear(); buffer.str(tmpQ); buffer>>Q;

    cout<<"Case #"<<nr+1<<":";
    // ------------------------------------------------------

    //cout<<endl<<tmpP<<" "<<tmpQ<<endl; 
    //cout<<endl<<P<<" "<<Q<<endl; 

    long double P2=pow(2,40)*P;
    long double N=P2/Q;
    //cout<<endl<<P<<" "<<Q<<" - > "<<N<<endl; 
    long double test=1;
    int p=0;
    bool gasit=false;
    while(p<=40 && !gasit){
      test=pow(2,p);
      if(test>N) gasit=true;
      p++;
    }
    p--;
    
    //cout<<" "<<N-floor(N)<<endl;
    if(N-floor(N)==0)
      cout<<" "<<40-p+1<<endl;
    else
      cout<<" impossible"<<endl;
  }
}
