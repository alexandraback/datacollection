#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#define DN 1000000
using namespace std;

int d[DN+1];

int rn(int n) {
  int r=0;
  for(;n;r=r*10+n%10,n/=10);
  return r;
}

void b() {
  queue<int> c;
  d[1]=1;
  for(c.push(1);!c.empty();) {
    int fr=c.front(); c.pop();
    if(fr>DN) continue;
    if(!d[fr+1]) {
      d[fr+1]=d[fr]+1;
      c.push(fr+1);
    }
    int r=rn(fr);
    if(!d[r]) {
      d[r]=d[fr]+1;
      c.push(r);
    }
  }
}

int main() {
  b();
  /*ofstream g("tst.txt");
  for(int i=1; i<=1000; ++i) {
    g<<fixed<<setw(3)<<d[i]<<' ';
    if(i%20==0) g<<'\n';
  }*/
  ifstream f("input.txt");
  ofstream g("output.txt");
  int T; f>>T;
  for(int t=1; t<=T; ++t) {
    int n; f>>n;
    g<<"Case #"<<t<<": "<<d[n]<<'\n';
  }
}