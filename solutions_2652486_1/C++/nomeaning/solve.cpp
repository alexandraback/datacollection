#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
int R,N,M,K;
const int MAX_T = 50000;
const int MAX_Q = 120;
int guess[100];
int main(){
  std::mt19937 engine;
  int T;
  cin>>T;
  cout<<"Case #1:"<<endl;
  cin>>R>>N>>M>>K;
  for(;R--;){
    for(int j=0;j<K;j++){
      cin>>guess[j];
    }
    std::uniform_int_distribution<int> rng1(2,M);
    std::uniform_int_distribution<int> rng2(0,1);
    bool ok = false;
    for(int i=0;i<MAX_T;i++){
      sort(guess, guess+K);
      int c[100];
      for(int j=0;j<N;j++){
        c[j] = rng1(engine);
      }
      for(int q=0;q<MAX_Q;q++){
        int pd = 1;
        for(int k=0;k<N;k++){
          if(rng2(engine))pd *= c[k];
        } 
        //cout << pd << endl;
        for(int k=0;k<K;k++){
          if(guess[k]==pd)guess[k]=0;
        }
      }
      ok = true;
      for(int k=0;k<K;k++){
        if(guess[k] != 0)ok=false;
      }
      if(ok){
        for(int k=0;k<N;k++){
          cout<<c[k];
        }
        cout<<endl;
        break;
      }
    }
    if(!ok)cout<<string(N,'2')<<endl;
  }
}
