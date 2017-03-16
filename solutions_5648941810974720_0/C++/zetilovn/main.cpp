#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;

#define M_PI 3.14159265358979323846264338327950288

void substract(map<char, int> &m, vector<string> &v, vector<int> &cnt, int num)
{
  for (auto x: v[num]) {
    m[x] -= cnt[num];
  }
}


int main()
{
  ifstream cin("/Users/Zetilov/Downloads/A-small-attempt0.in-2.txt");
  ofstream fout("/Users/Zetilov/ClionProjects/untitled/output.txt");
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  fout.setf(ios_base::fixed);
  fout.precision(28);

  vector<string> v = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  int tst;
  cin >> tst;
  for (int cs = 1; cs <= tst; ++cs) {
    fout << "Case #" << cs << ": ";
    cout << cs << endl;
    vector<int> cnt(10);
    map<char, int> m;
    string S;
    cin >> S;
    for (auto c: S) {
      ++m[c];
    }
    cnt[0] = m['Z'];
    substract(m, v, cnt, 0);

    cnt[2] = m['W'];
    substract(m, v, cnt, 2);

    cnt[4] = m['U'];
    substract(m, v, cnt, 4);

    cnt[6] = m['X'];
    substract(m, v, cnt, 6);

    cnt[8] = m['G'];
    substract(m, v, cnt, 8);

    cnt[3] = m['T'];
    substract(m, v, cnt, 3);

    cnt[5] = m['F'];
    substract(m, v, cnt, 5);

    cnt[1] = m['O'];
    substract(m, v, cnt, 1);

    cnt[7] = m['V'];
    substract(m, v, cnt, 7);

    cnt[9] = m['I'];
    substract(m, v, cnt, 9);

    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        fout << i;
      }
    }
    fout << '\n';
  }
  return 0;
}