#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
  int tc; cin >> tc;
  for(int tid = 1; tid <= tc; tid++){
    int a,b;
    cin >> a >> b;
    vector< double > ps(a);
    for(int i=0; i<a; i++){  cin >> ps[i]; }

    vector< double > tab(a+1);
    tab[0] = 1.0;
    for(int i=1; i<=a; i++){
      tab[i] = ps[i-1] * tab[i-1];
    }
    vector< double > ans;

    for(int i=0; i<=a; i++){
      double p = ( tab[a-i] * (double)(b-a + 1 + i + i) +
		   (1.0 - tab[a-i]) * (double)(b-a + 1 + i + i + b + 1));
      ans.push_back(p);
    }
    ans.push_back( (double)(1 + 1 + b) );
    sort(ans.begin(), ans.end());
    printf("Case #%d: %.6lf\n",tid,ans[0]);
  }

  return 0;
}
