#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int N;

int solve2(){
  cin>>N;
  vector<long long int> D;
  vector<long long int> M;
  for(int i=0;i<N;i++){
    int d,h,m;
    cin>>d>>h>>m;
    for(int j=0;j<h;j++){
      D.push_back(d);
      M.push_back(m+j);
    }
  }

  assert(D.size()<=2);
  if(D.size()==1)
    return 0;
  if(M[0]==M[1])
    return 0;
  int v=0;
  int l=1;
  if(M[0]>M[1]){
    v=1;
    l=0;
  }
  auto vv=(720-D[v])*M[v];
  auto ll=(360-D[l])*M[l];
  if(vv>ll){
    return 0;
  }else{
    return 1;
  }
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve2()<<endl;
  }
  return 0;
}
