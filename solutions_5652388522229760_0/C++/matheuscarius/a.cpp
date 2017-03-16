#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main () {
  
  int t;
  scanf("%d", &t);
 
  for(int caso = 1; caso <= t; caso++) {
    bitset<10> digits;
    ll n;
    scanf("%d", &n);
    if(n==0) {
      printf("Case #%d: INSOMNIA\n", caso);
      continue;
    }
    for(int i = 1; 1; i++) {
      int aux = n*i;
      while(aux > 0) {
        digits[aux%10] = true;      
        aux/=10;
      }
      if (digits.all()) {
        printf("Case #%d: %lld\n",caso, i*n);
        break;
      }
    }
  }
  return 0;
}
