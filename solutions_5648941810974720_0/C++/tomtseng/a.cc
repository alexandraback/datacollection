#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

/*
 * Certain numbers can be identified uniquely
 * Z -> 0
 * G -> 8
 * X -> 6
 * W -> 2
 * U -> 4
 * remaining R's -> 3
 * remaining S's -> 7
 * remaining O's -> 1
 * remaining F's -> 5
 * remaining I's -> 9
 */

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T;
  cin >> T;
  string str;

  for (int t = 1; t <= T; t++) {
    cin >> str;
    int sz = str.size();
    unordered_map<char, int> charcnt;
    vector<int> numcnt(10, 0);

    for (int i = 0; i < sz; i++)
      charcnt[str[i]]++;

    numcnt[0] = charcnt['Z'];
    charcnt['R'] -= charcnt['Z'];
    charcnt['O'] -= charcnt['Z'];

    numcnt[8] = charcnt['G'];
    charcnt['I'] -= charcnt['G'];

    numcnt[6] = charcnt['X'];
    charcnt['S'] -= charcnt['X'];
    charcnt['I'] -= charcnt['X'];

    numcnt[2] = charcnt['W'];
    charcnt['O'] -= charcnt['W'];

    numcnt[4] = charcnt['U'];
    charcnt['O'] -= charcnt['U'];
    charcnt['R'] -= charcnt['U'];
    charcnt['F'] -= charcnt['U'];

    numcnt[3] = charcnt['R'];

    numcnt[7] = charcnt['S'];
    
    numcnt[1] = charcnt['O'];

    numcnt[5] = charcnt['F'];
    charcnt['I'] -= charcnt['F'];

    numcnt[9] = charcnt['I'];

    cout << "Case #" << t << ": ";
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < numcnt[i]; j++) 
        cout << i;
    cout << "\n";
  }

  return 0;
}
