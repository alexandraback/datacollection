#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
int limit, coins, val;
vector <int> arr;
vector <int> poss;
vector <int> used;

int main(){
  int t;
  cin >> t;
  for (int idx = 1; idx <= t; idx++){
    poss.assign(105, 0); poss[0] = 1;
    used.assign(105, 0);
    cout << "Case #" << idx << ": ";
    cin >> limit >> coins >> val;
    arr.resize(coins);
    
    for (int i = 0; i < coins; i++) {
      int tmp; cin >> tmp;
      arr[i] = tmp;
      used[tmp] = 1;
      for (int k = 0; k < limit; k++){
	for (int j = val; j >= tmp; j--){
	  if (poss[j - tmp]) poss[j] = 1;
	}
      }
    }

    vector <int> usable;
    for (int i = 1; i <= min(val, 20); i++)
      if (!used[i]) usable.push_back(i);

    int use = (int) usable.size();
    int res = 1000000000;

    for (int bm = 0; bm < (1 << use); bm++){
      vector <int> cpy(poss);
      int curr = __builtin_popcount(bm);
      if (curr >= 8) continue;
      for (int j = 0; j < use; j++){
	if (bm & (1 << j)){
	  int tmp = usable[j];
	  for (int k = 0; k < limit; k++){
	    for (int m = val; m >= tmp; m--){
	      if (cpy[m - tmp]) cpy[m] = 1;
	    }
	  }
	}
      }
      bool flag = true;
      for (int i = 1; i <= val; i++)
	if (!cpy[i]) flag = false;
      if (flag) res = min(res, curr);
    }
    cout << res << endl;
  }


  return 0;
}
