

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


int N;

vs vagon;

bool compat[12][12];

int m=1000000007;
int rezultat=0;

bool OK(string& train){
  int n=train.size();
  REP(i,n){
    while(i<n-1 && train[i]==train[i+1]) i++;
    int j=i+1; while(j<n){ if(train[i]==train[j]) return false; j++;}
  }
  return true;
}

void canonic(string & v){
  int i=0;
  while(i<v.size()){
    while(i<v.size()-1 && v[i]==v[i+1]) v.erase(v.begin()+i+1);
    i++;
  }
}


void handle(vb&folosit, string train){
  bool end=true;
  REP(i,N) if(!folosit[i]) end=false;//end=(end && folosit[i]);
  if(end)
    rezultat=(rezultat+1)% m;
  else{
    //cout<<"OK "<<rezultat<<" "<<ultim<<endl;
    REP(i,N){
      string new_train=train+vagon[i];
      if(!folosit[i] && OK(new_train)){//vagon[i].x==ultim){
	folosit[i]=true;
	handle(folosit,new_train);
	folosit[i]=false;
      }
    }
  }

  //  if(end){
  //  REP(i,N) end=end && folosit[i];
  //  if(end) rezultat=(rezultat+1)% m;
  //  //else return 0;
  //}
}



int main(){
  int T,nr;
  string line;
  ISS buffer;
  string tmp;
  
  getline(cin,line); istringstream(line)>>T;
  for(nr=0;nr<T;nr++){
    getline(cin,line); istringstream(line)>>N;
    cinL2B(line,buffer);
    vagon.clear();
    REP(i,N){
      //string tmp;
      buffer>>tmp;
      canonic(tmp);
      vagon.push_back(tmp);
    }

    cout<<"Case #"<<nr+1<<":";
    // ------------------------------------------------------
    rezultat=0;

    //cout<<endl; REP(i,N) cout<<" "<<vagon[i]<<endl;

    /*
    REP(i,N) REP(j,N){
      compat=OK(vagon[i],vagon[j]);
    }
    //cout<<m;
    /*
    int rez=0;

    //vi poz(N,20);
    REP(i,N){
      folosit[i]=true;
      //rez=rez+handle(folosit,vagon[i].y)% m;
      handle(folosit,vagon[i].y);
      folosit[i]=false;
    }
    */
    vb folosit(N,false);
    handle(folosit,"");

    cout<<" "<<rezultat<<endl;
  }
}
