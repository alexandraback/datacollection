#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int BUF = 100005;


int N, M;
double p[BUF];

void read(){
  cin >> N >> M;
  for(int i=0;i<N;i++) cin >> p[i];
}


void work(int cases){
  long double curP = 0;
  for(int i=0;i<N;i++)
    curP += log2(p[i]);

  long double minV = 2+M; // type ENTER immediately

  for(int nBS=0;nBS<=N;nBS++){ // type BS nBS times and ENTER
    if(nBS!=0)
      curP = curP-log2(p[N-nBS]);
    
    minV = min(minV,
               nBS+(M-(N-nBS))+1+
               (1-pow(2,curP))*(M+1));
  }

  printf("Case #%d: %Lf\n",cases,minV);
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
