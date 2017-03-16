#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <iomanip> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 
typedef pair<int, int> PII; 

LLI combine(int n, int k){
  LLI result = 1;
  REP(i, n) result *= (i+1); 
  REP(i, k) result /= (i+1);
  REP(i, (n-k)) result /= (i+1); 
  //cout << n << " over " << k << " is " << result << endl;
  return result; 
}

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    int N, X, Y; 
    cin >> N >> X >> Y; 
    X = abs(X);
    
    int layer_my = X+Y; 
    int h_my = Y; 
    int layer_lb=0;
    for(LLI i=1; N>(i*(i+1))/2; i+=2){
      layer_lb = i+1;
    }
    int rd = N - (layer_lb-1)*(layer_lb)/2; 
    //cout << "layer_my:"<< layer_my << " h_my:" << h_my << " layer_lb:" << layer_lb << " rd:" << rd << endl;
    
    double result = 0.42;
    if(layer_my>layer_lb){
      result = 0.0;
    }
    else if(layer_my<layer_lb){
      result = 1.0; 
    }
    //layer_my == layer_lb
    else if(h_my < rd-layer_lb){
      result = 1.0;
    }
    else if(h_my == layer_lb){
      result = (rd==2*layer_lb+1)?1.0:0.0; 
    }
    else if(h_my >= rd){
      result = 0.0; 
    }
    else{
      h_my -= max(0, rd-layer_lb); 
      int h = layer_lb - max(0, rd-layer_lb); 
      int r = rd - 2*max(0, rd-layer_lb); 
      
      double sum = 0.0; 
      //double binom = 1.0; 
      /*
      //!N <= 10^6
      for(int k=1; k<=r-h_my-1; k++){
        binom *= ((double)(r-k+1))/((double)k); 
        sum += binom; 
        //cout << r << " over " << k << " is " << binom << endl;
      }*/
      for(int k=h_my+1; k<=r ; k++){
        sum += combine(r, k); 
      }
      
      REP(i, r) sum /= 2.0; 
      result = sum; 
      
      //cout << h_my << "/" << h << " rest=" << r << endl;
    }
    
    cout << setprecision(9) << "Case #"<<t+1<<": "<<result << endl;
  }
	return 0;
}
