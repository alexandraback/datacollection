
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
  int R,C,M;
  int r,c,minusR,minusC,m;
  char mat[55][55];
  
  getline(cin,line); istringstream(line)>>N;
  for(nr=0;nr<N;nr++){
    getline(cin,line); istringstream(line)>>R>>C>>M;

    cout<<"Case #"<<nr+1<<":";
    // ------------------------------------------------------
    //cout<<R<<" "<<C<<" "<<M<<endl;
    REP(i,R) REP(j,C) mat[i][j]='*';

    m=M;
    r=R;
    c=C;

    while(m >= r || m >= c){
      if(r<c){
	c--;
	m-=r;
      }
      else{
	r--;
	m-=c;
      }
    }
    minusR=R-r;
    minusC=C-c;
    //cout<<r<<" "<<c<<" "<<m<<endl;

    REP(i,r) REP(j,c) mat[i][j]='.';
    mat[0][0]='c';

    bool posibil=true;
    
    if(r==0 || c==0) posibil=false;
    else if(m <=r-2){
      if(c>2)
	REP(i,m) mat[r-i-1][c-1]='*';
      else// c=2,1
	if(c==2){// m=0,1
	  if(m==0); // format is ok
	  if(m==1) posibil=false;
	}
	else if(c==1){// m=0
	  if(minusC==0); // format is ok
	  else posibil=false; //minusC>0
	}
    }
    else{ // m=r-1
      if(c>3){
	if( r==1 )// m=0
	  if(minusR==0); // format is ok
	  else posibil=false;
	else if( r==2 ) posibil=false;// m=1
	else{ // m>=2
	  REP(i,m-1) mat[r-i-1][c-1]='*';
	  mat[r-1][c-2]='*';
	}
      }
      else// c=3,2,1
	if(c==3){// m=0,1,2
	  if( m==2 || m==1 ) posibil=false;// r=3,2
	  if( m==0 )// r=1
	    if(minusR==0); //format is ok
	    else posibil=false;
	}
	else if(c==2){// m=0,1
	  if( m==1 ) posibil=false;// r=2
	  if( m==0 )// r=1
	    if(minusR==0); //format is ok
	    else posibil=false;
	}
	else // c=1, m=0, r=1
	  ;//format is ok in ambele cazuri (doar o casuta libera, restul mine)
	  //if(minusR==0 && minusC==0); //format is ok
	  //else posibil=false;
    }

    cout<<endl;
    if(!posibil)
      cout<<"Impossible"<<endl;
    else
      REP(i,R) { REP(j,C) cout<<mat[i][j]; cout<<endl;}
  }
}
