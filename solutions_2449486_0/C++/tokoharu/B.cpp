#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 

int input[100][100];

bool solve() {
  int n,m;
  cin>>n>>m;
  int maximH[100];
  int maximW[100];
  REP(i,100) maximH[i] = maximW[i] = 0;
  REP(i,n) {
    REP(j,m) {
      cin>>input[i][j];
      maximH[i] = max(maximH[i],input[i][j]);
      maximW[j] = max(maximW[j], input[i][j]);
    }
  }
  
  REP(i,n) {
    REP(j,m) {
      if(maximH[i]!=input[i][j] && maximW[j] !=input[i][j])
	return false;
    }
  }
  return true;
   
}

int main() {
  int t;
  cin>>t;
  REP(i,t) {
    string ans="NO";
    if(solve()) ans = "YES";
    cout<<"Case #"<<i+1<<": "<<ans<<endl;
  }
  return 0;
  
}
