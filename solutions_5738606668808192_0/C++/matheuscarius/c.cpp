#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll divisor(ll x) {
  for(ll d = 2; d*d <= x; d++)
    if(x%d==0) return d;
    
  return 0;
}

int main () {
  int t,n,j;
  scanf("%d %d %d", &t, &n, &j);
  printf("Case #1:\n");
  
  ll table[15][20] = {};
  for(int i = 2; i <= 10; i++) {
    table[i][0]=1;
    for(int j = 1; j < 16; j++)
      table[i][j]=table[i][j-1]*i;
  }
  int cont = 0;
  for(int x = (1<<15)+1; cont < 50; x+=2) {
    ll div[15] = {};
    bool jamcoin = true;
    for(int i = 2; i <= 10; i++) {
      ll val = 0;
      for(int j = 0; j < 16; j++) {
        int dig = (x&(1<<j))>0;
        val += dig*table[i][j];
      }
//      printf("%lld\n", val);
      div[i] = divisor(val);
      if(div[i]==0) {
        jamcoin = false;
        break;
      }
    }
    bitset<16> a(x);
    if(jamcoin)
      printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n", a.to_string().c_str(),div[2],div[3],div[4],div[5],div[6],div[7],div[8],div[9],div[10]),cont++;
  }
  
  return 0;    
}
