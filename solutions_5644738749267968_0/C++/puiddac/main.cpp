
#include <iostream>
#include <iomanip> //setprecision
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <iterator> //istream_iterator
#include <algorithm> //sort

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



bool ia_toate(const vd& naomi,const vd& ken,int len){

  vb used(len,false);
  int min;

  REP(i,len){
    min=0; while(min<len && (used[min] || ken[len-i-1]>naomi[min])) min++;

    if(min>=len) return false;

    used[min]=true;
  }

  return true;
}

int main(){
  int N,nr;
  string line;
  int n;
  vd naomi,ken;
  double tmp;
  int y,z;
  
  getline(cin,line); istringstream(line)>>N;
  for(nr=0;nr<N;nr++){
    getline(cin,line); istringstream(line)>>n;
    naomi.clear(); ken.clear();
    getline(cin,line);
    ISS buffer(line);
    REP(i,n){
      buffer>>tmp;
      naomi.push_back(tmp);
    }

    getline(cin,line);
    buffer.clear();
    buffer.str(line);
    REP(i,n){
      buffer>>tmp;
      ken.push_back(tmp);
    }

    cout<<"Case #"<<nr+1<<":";
    // ------------------------------------------------------
    //cout<<C<<" "<<F<<" "<<X<<endl;

    sort(ALL(naomi));
    sort(ALL(ken));

    //cout<<endl;
    //REP(i,n) cout<<naomi[i]<<" "; cout<<endl;
    //REP(i,n) cout<<ken[i]<<" "; cout<<endl;
    //cout<<endl;

    if(naomi[0]>ken[n-1]){
      cout<<" "<<n<<" "<<n<<endl;
    }
    else if(naomi[n-1]<ken[0]){
      cout<<" "<<0<<" "<<0<<endl;
    }
    else{
      z=0;
      int i=0;
      int j=0;
      /*
      while(j<n){
	while(ken[j]<naomi[i] && j<n) j++;
	i++;
	j++;
      }
      z=n-i;
      */

      vb used(n,false);
      while(i<n){
	j=0;
	while(j<n && (ken[j]<naomi[i]||used[j])) j++;
	if(j==n){
	  z++;
	}
	else{
	  used[j]=true;
	}
	i++;
      }


      y=0;
      while(n){
	while(n && naomi[0]>ken[0]){
	  naomi.erase(naomi.begin());
	  ken.erase(ken.begin());
	  n--;
	  y++;
	}

	while(n && naomi[n-1]>ken[n-1]){
	  naomi.erase(naomi.begin()+n-1);
	  ken.erase(ken.begin()+n-1);
	  n--;
	  y++;
	}

	if(n){
	  naomi.erase(naomi.begin());
	  ken.erase(ken.begin()+n-1);
	  n--;
	}

	/*	
       	if(n && ia_toate(naomi,ken,n)){
	  y=n;
	  n=0;
	}
	*/
    }

      cout<<" "<<y<<" "<<z<<endl;
    }
  }
}
