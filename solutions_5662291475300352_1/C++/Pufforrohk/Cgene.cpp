#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int N;


int compute(long long int D, long long int M, long long int T){
  auto sum = T + D*M;
  auto frac = (T+D*M)/(360*M);
  return frac-1;
}

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

  assert(D.size()<=10);
  long long int best = 1000000000000;
  for(int target=0;target<D.size();target++){
    auto tempo = (360-D[target])*M[target]; 
    long long int counter = 0;
    for(int j=0;j<D.size();j++){
      if(j!=target){
	auto t1 = (360-D[j])*M[j];
	if(t1>tempo){
	  counter++;
	}else{
	  counter+=compute(D[j],M[j],tempo);
	  /*	  int c = 360;
	  while(counter<best){
	    auto t2 = (360+c-D[j])*M[j];
	    if(t2<=tempo){
	      counter++;
	    }else{
	      break;
	    }
	    c+=360;
	    }*/
	}
      }
    }
    best = min(best,counter);
  }
  return best;
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve2()<<endl;
  }
  return 0;
}
