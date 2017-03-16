#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


double D;
int N;
int A;
vector<double> Ti, Xi, Ai;

int main(void)
{
  int T; cin >> T;
  
 
  
  for(int t=0; t < T; ++t){
      cin >> D; cin >> N; cin >> A; 
      
      Ti.clear(); Ai.clear(); Xi.clear();
      for(int i=0; i < N; ++i){
	double ti,xi;
	cin >> ti; 
	cin >> xi;
	Ti.push_back(ti); 
	Xi.push_back(xi);
      }
      
      cout << "Case #" << t+1 << ":" << endl;
      
      double time;
      for(int i=0; i < A; ++i){
	double a; cin >> a;
	
	if(N == 1){
	  time = sqrt(2.0*D/a); 
	}
	else{
	  //Other
	  if(Xi[0] < D)
	    time = (D-Xi[0]) / ((Xi[1]-Xi[0]) / (Ti[1]-Ti[0]));
	  else  
	    time = 0.0;
	  
	  time = max(time, sqrt(2.0*D/a));
	  
	}
	printf("%.7f\n", time);
      }
      
  }
      
  
  return 0;
}

