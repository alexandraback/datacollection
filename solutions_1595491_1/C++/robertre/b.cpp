#include <iostream>

using namespace std;

int solve(int N, int S, int p) {
  int scoreok = 3*p-2;
  int scoresu = 3*p-4;
  if (p == 1) {
    scoresu = 1;
  } else if (p<=0) {
    scoreok = 0;
    scoresu = 0;
  }
  int res = 0;
  for(int i=0;i<N;++i) {
    int score;
    cin>>score;
    if (score >= scoreok) {
      res++;
    } else if (S > 0 &&score >= scoresu) {
      res++;
      S--;
    }
  }
  return res;
}

int main(int argc, char** argv) {
  int ntc;
  cin>>ntc;
  for(int t=0;t<ntc;++t) {
    int N, S, p;
    cin>>N>>S>>p;
    int res = solve(N, S, p);
    cout<<"Case #"<<t+1<<": "<<res<<endl;
  }
}
