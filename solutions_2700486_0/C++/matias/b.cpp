#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

double prob(int N, int Y){
  double sum = 0.0;
  for (int y = Y;y<=N;y++){
    double cur = 0.0;
    for (int i=2;i<=y;i++){
      cur-=log(i);
    }
    for (int i = N-y+1;i<=N;i++){
      cur+=log(i);
    }
    cur-=N*log(2);
    sum+=exp(cur);
  }
  return sum;      
}

int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int N,X,Y;
    cin>>N>>X>>Y;
    if (X<0) X = -X;
    int level = (X+Y)/2;
    for (int i=0;i<level;i++){
      N-= (1+4*i);
    }
    double res;
    if (N<=Y) {
      res = 0.0;
    }
    else if (N>Y+level*2) {
      res = 1.0;
    }
    else if (X==0 && N<(level*4+1)) {
      res = 0.0;
    }
    else {
      res = prob(N,Y+1);
    }

    cout<<"Case #"<<t<<": "<<res<<endl;
  }
}
