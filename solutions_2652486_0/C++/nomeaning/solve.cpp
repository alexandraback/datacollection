#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
int R,N,M,K;
const int MAX_T = 300;
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
    std::uniform_int_distribution<int> rng(2,M);
    bool ok = false;
    for(int i=0;i<MAX_T;i++){
      sort(guess, guess+K);
      int c[100];
      for(int j=0;j<N;j++){
        c[j] = rng(engine);
      }
      for(int j=0;j<1<<N;j++){
        int pd = 1;
        for(int k=0;k<N;k++){
          if(j>>k&1)pd *= c[k];
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
