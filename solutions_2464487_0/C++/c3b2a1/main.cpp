#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<math.h>

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
    long long r,t;
    getline(input,nummern);
    stringstream(nummern)>>r>>t;
    double xsh=0.5*r-0.25;
    double hv=-xsh+sqrt(xsh*xsh+0.5*t);
    long long res=hv;
    while((2*r-1)*res+2*(res*res)>t) {
      res--;
    }
    while((2*r-1)*res+2*(res*res)<=t) {
      res++;
    }
    res--;
    output<<"Case #"<<testnr<<": "<<res<<endl;
  }
  input.close();
  output.close();
  cout<<"\nFinished\n";
  return 0;
}
