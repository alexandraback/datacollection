#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>
using namespace std;

typedef pair<int,int> P;

int main(){
  int T;
  cin >> T;

  for(int SET = 1; SET <= T; SET++){
    printf("Case #%d: ", SET);

    int a, b;
    cin >> a >> b;
    int len = log10(a) + 1;
    int maxp = pow(10, len - 1);
    set<P> ans;

    for(int i = a; i <= b; i++){
      for(int p = 10, q = maxp; p <= maxp; p *= 10, q /= 10){
        int rev =  (i % p) * q + i / p;
        if(i < rev && rev <= b){
          ans.insert(P(i, rev));
        }
      }
    }

    cout << ans.size() << endl;
  }
}
