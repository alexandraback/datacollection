#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>


using namespace std;

int main(int argc, char *argv []) {
  if(argc<3) return 1;
  ifstream input;
  input.open(argv[1]);
  ofstream output;
  output.open(argv[2]);
  int tcc;
  string nummern;
  getline(input,nummern);
  stringstream(nummern)>>tcc;
  for(int testnr=1;testnr<=tcc;testnr++) {
    int A,N;
    getline(input,nummern);
    stringstream(nummern)>>A>>N;
    int *m=new int[N];
    getline(input,nummern);
    stringstream ss(nummern);
    for(int i=0;i<N;i++) {
      ss>>m[i];
    }
    sort(m,m+N);
    int nr=0;
    int anz=0;
    int res=0;
    if(A==1) {
      res=N;
    } else {
      while(nr<N) {
        while(A>m[nr]&&nr<N) {
          A+=m[nr];
          nr++;
        }
        int hv=anz+(N-nr);
          if(!res||res>hv)
            res=hv;
        if(nr<N) {
          anz++;
          A=2*A-1;
        }  
      }
    }
    output<<"Case #"<<testnr<<": "<<res<<endl;
    delete [] m;
  }
  input.close();
  output.close();
  cout<<"\nFinished\n";
  return 0;
}
