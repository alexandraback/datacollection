#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <math.h>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 100

typedef long long llong;

int main(){
  int t, cases = 0;
  cin >> t;
  while (t--){
    string s;
    int n;
    cin >> s >> n;

    int last = 0, cons = 0;
    llong total = 0;
    for (int i = 0; i < s.length(); ++i){
      if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') ++cons;
      else cons = 0;

      if (cons >= n){
	total += (i+2-n-last)*(s.length()-i);
	last = i+2-n;
      }
    }

    cout << "Case #" << ++cases << ": " << total << endl;
  }
  return 0;
}
