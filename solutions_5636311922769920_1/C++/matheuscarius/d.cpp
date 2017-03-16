#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main () {
  int t;
  scanf("%d", &t);
  for(int caso = 1; caso <= t; caso++) {
    int k,c,s;
    scanf("%d %d %d", &k, &c, &s);
    vll resp;
    for(int atual = 1; atual <= k;) {
      ll index = atual++;
      for(int l = 2; l <= c && atual <= k; l++) {
        index = (index-1)*k;
        index += atual++;
      }
      resp.push_back(index);
    }
    if(resp.size() > s) printf("Case #%d: IMPOSSIBLE\n",caso);
    else {
      printf("Case #%d:", caso);
      for(int i = 0; i < resp.size(); i++) {
        printf(" %lld", resp[i]);
      }
      printf("\n");
    }
  }
  
  return 0;    
}
