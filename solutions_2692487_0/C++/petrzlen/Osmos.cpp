#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 
typedef pair<int, int> PII; 

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    int A, N; 
    cin >> A >> N; 
    
    vector<int> M(N, 0); 
    REP(i, N) cin >> M[i];
    
    sort(M.begin(), M.end()); 
    
    int best = 123456789; 
    int add=0; 
    
    if(A>1){
      int m=0; 
      while(m < N){
        while(m < N && M[m] < A){ //eat
          A += M[m];
          m++; 
        }
        best = min(best, add + N-m); //delete all other
        
        A += A-1; 
        add++; 
      }
    }
    else{
      best = add = N; 
    }
    
    cout << "Case #"<<t+1<<": "<<min(best, add)<<endl; 
  }
	return 0;
}
