#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
using namespace std;

int T, N, ans1, ans2;

int main() {
  ifstream cin("D-large.in");
  ofstream cout("D-large.out");

  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> N;
    deque<double> mn(N), mk(N); //masses
    for (int i = 0; i < N; i++) cin >> mn[i];
    for (int i = 0; i < N; i++) cin >> mk[i];
    sort(mn.begin(), mn.end());
    sort(mk.begin(), mk.end());

    ans1 = ans2 = 0;

    //count the maximum # of Ken blocks Naomi can eliminate
    int ni = 0, ki = 0;
    while (ni < N && ki < N) {
      while (ni < N && mn[ni] < mk[ki]) ni++;
      if (ni == N) break;
      if (mn[ni] > mk[ki]) { //check, just in case
        ni++, ki++; //eliminate block pairs
        ans1++;
      }
    }

    //simulate the real War game
    for (int _ = 0; _ < N; _++) {
      double chosen_N = mn[mn.size() - 1];
      if (mk[mk.size() - 1] > chosen_N) { //Ken can beat Naomi
        //find smallest K block > chosen_N
        deque<double>::iterator it;
        it = upper_bound(mk.begin(), mk.end(), chosen_N);
        //burn both blocks
        mk.erase(it);
        mn.pop_back();
      } else { //Ken chooses his smallest block to get rid of
        mk.pop_front();
        mn.pop_back();
        ans2++;
      }
    }

    cout << "Case #" << Case << ": ";
    cout << ans1 << " " << ans2 << "\n";
  }
  return 0;
}
