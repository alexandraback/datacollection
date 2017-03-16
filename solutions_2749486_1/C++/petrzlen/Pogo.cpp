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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char ds[4] = {'W', 'S', 'E', 'N'};

bool solve(LLI &x, LLI &y, LLI &n, string &result){
  if(n <= 0) return false;

  LLI z=n*(n+1ll)/2ll - 2ll*n + 1ll; 
  int d=-1; 
  
  if(abs(x) + abs(y) < z){
    if(x >= 0) d=0;
    else d=2; 
  }
  else{
    if(x > 0 && (x - z) > abs(y)) d=2;
    else if(x < 0 && abs(x + z) > abs(y)) d=0; 
    else if(y > 0) d=3;
    else d=1; 
  }
  
  //cout << "("<<x<<","<<y<<") " << d << endl;
  
  x += n*dx[d];
  y += n*dy[d];
  result += ds[d]; 
  n--;
  
  return true; 
}

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    LLI X,Y;
    string result=""; 
    
    cin >> X >> Y;
    LLI n=0; 
    while(n*(n+1ll)/2ll < abs(X)+abs(Y) || (n*(n+1ll)/2ll - (abs(X)+abs(Y))) % 2ll == 1ll) n++; 
    //cout << "n="<<n << endl;
    
    while(solve(X,Y,n,result)); 
    REP(i, result.size()/2) swap(result[i], result[result.size()-1-i]); 
    
    cout << "Case #"<<t+1<<": " << result << endl;
  }
	return 0;
}
