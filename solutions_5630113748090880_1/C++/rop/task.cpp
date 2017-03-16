#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
void solve(int tc){
  int n, x;
  scanf("%d", &n);
  map<int, int>mp;
  for(int i = 0; i < 2*n-1; i++)for(int j = 0; j < n; j++){
  	scanf("%d", &x);
  	mp[x]++;
  }
  printf("Case #%d:", tc);
  for(auto k : mp){
  	if(k.second&1)printf(" %d", k.first);
  }
  printf("\n");
}
int main(){
  int tc;
  scanf("%d", &tc);
  for(int i = 1; i <= tc; i++)solve(i);
}