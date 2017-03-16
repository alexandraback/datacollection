#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
  int N;
  cin>>N;
  vector<double> naomi(N),ken(N);
  for(int i=0;i<N;i++)
    cin>>naomi[i];
  for(int i=0;i<N;i++)
    cin>>ken[i];
  sort(naomi.begin(),naomi.end());
  sort(ken.begin(),ken.end());
  int basicwin=0;
  int curR=0;
  for(int i=0;i<N;i++){
    while(curR<N && ken[curR]<=naomi[i]){
      curR++;
    }
    if(curR==N)
      basicwin++;
    else
      curR++;
  }
  int curN=0;
  int win=0;
  for(int i=0;i<N;i++){
    while(curN<N && ken[i]>naomi[curN]){
      curN++;
    }
    if(curN<N){
      win++;    
      curN++;
    }
  }
  cout<<win<<" "<<basicwin;
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
    cout<<endl;
  }
}
