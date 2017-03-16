#include<iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

int main() {
  int cas; cin>>cas;
  int R,N,M,K;
  cin>>R>>N>>M>>K;
  int prod;
  cout<<"Case #1:"<<endl;
  for(int ca=0; ca<R; ++ca) {
    int mb=0, mc=0, md=0;
    for(int i=0 ; i<K ; ++i) {
      cin>>prod;
      int b=0, c=0, d=0;
      if (prod ==1) continue;
      int orgprod = prod;
      prod = orgprod;
      while(prod %3 ==0 ) {
        prod /= 3;
        b++;
      }
      prod = orgprod;
      while(prod %5 ==0 ) {
        prod /= 5;
        c++;
      }
      prod = orgprod;
      while(prod %4 ==0 ) {
        prod /= 4;
        d++;
      }
      prod = orgprod;

      mb = MAX(b, mb);
      mc = MAX(c, mc);
      md = MAX(d, md);

    }
    int xa = N-mb-mc-md;
    for(int j=0;j<xa;++j) cout<<2;
    for(int j=0;j<mb;++j) cout<<3;
    for(int j=0;j<md;++j) cout<<4;
    for(int j=0;j<mc;++j) cout<<5;

    cout<<endl;
  }
}
