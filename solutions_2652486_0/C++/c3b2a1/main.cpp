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
  int R=100;
  int M=5;
  int N=3;
  int K=7;
  for(int testnr=1;testnr<=tcc;testnr++) {
    output<<"Case #"<<testnr<<": \n";
    int count[11];
    for(int r=0;r<R;r++) {
      for(int i=0;i<=M;i++) {
        count[i]=0;
      }
      getline(input,nummern);
      stringstream ss(nummern);
      int mx2=0;
      for(int s=0;s<K;s++) {
        int m2=0;
        int hv;
        ss>>hv;
        while(hv%6==0) {
          m2++;
          hv/=6;
        }
        if(m2>count[6]) count[6]=m2;
        m2=0;
        while(hv%2==0) {
          m2++;
          hv/=2;
        }
        if(m2>mx2) mx2=m2;
        m2=0;
        while(hv%3==0) {
          m2++;
          hv/=3;
        }
        if(m2>count[3]) count[3]=m2;
        m2=0;
        while(hv%5==0) {  //save
          m2++;
          hv/=5;
        }
        if(m2>count[5]) count[5]=m2;
        m2=0;
        while(hv%7==0) {
          m2++;
          hv/=7;
        }
        if(m2>count[7]) count[6]=m2;        
      }
      int re=N;
      for(int i=3;i<=M;i++) {
        while(count[i]!=0) {
          output<<i;
          count[i]--;
          re--;
        }
      }
      while(re<mx2&&re>0) {
        if(re+2<mx2) {
          mx2-=3;
          output<<"8";
        } 
        if(re+1<mx2) {
          mx2-=2;
          output<<"4";
        } 
        re--;
      }
      while(re>0) {
        output<<"2";
        re--;
      }
      output<<endl;
    }
  }
  input.close();
  output.close();
  cout<<"\nFinished\n";
  return 0;
}
