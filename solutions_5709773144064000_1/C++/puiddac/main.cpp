
#include <iostream>
#include <iomanip> //setprecision
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <iterator> //istream_iterator

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


int main(){
  int N,nr;
  string line;
  long double C,F,X;
  
  getline(cin,line); istringstream(line)>>N;
  for(nr=0;nr<N;nr++){
    getline(cin,line); istringstream(line)>>C>>F>>X;

    cout<<"Case #"<<nr+1<<":";
    // ------------------------------------------------------
    //cout<<C<<" "<<F<<" "<<X<<endl;

    long double time=0;
    long double rate=2;

    //bool gata=false;

    while((rate+F)*C + rate*X < (rate+F)*X){
	time+=C/rate;
	rate+=F;
    }
    time+=X/rate;

    /*    
    while(!gata){
      //if(C/rate + X/(rate+F)<X/rate){
      if((rate+F)*C + rate*X < (rate+F)*X){
	//nrF++;
	//tot+=C;
	time+=C/rate;
	rate+=F;
      }
      else{
	gata=true;
	time+=X/rate;
      }
    }
    */
    cout<<" "<<std::fixed<<std::setprecision(7)<<time<<endl;
  }
}
