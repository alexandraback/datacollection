#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; ++i)
#define MAX 100010

long double prob[MAX], grid[MAX][4], pr[MAX];

int main(){
  
  int T, A, B;
  
  cin>>T;
  
  for(int j = 0 ; j < T ; ++j){
    
  cin>>A>>B;
  FOR(i,0,A)
    cin>>prob[i];
  FOR(i,1,A)
    prob[i] *= prob[i-1];
  FOR(i,0,A){
    pr[i] = (A-i+B-i-1)*prob[i]+(A-i+B-i+B)*(1-prob[i]);
//    cout<<pr[i]<<endl;
  }
  long double ans = B+2;
  FOR(i,0,A)
    ans = min(ans, pr[i]);
  printf("Case #%d: ", j+1);	cout<<setprecision(10)<<ans<<endl;
  
  }
  
  return 0;
  
}