#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const int N = 10000;
const char* m[4] = {
  "hijk", "iHkJ", "jKHi", "kjIH"
};

char pre[N];
bool isNeg[256];
int neg[256];
char f[256][256];
char ff[256][256];

void init() {
  for (int i = 'H'; i <= 'K'; i++) isNeg[i] = true;
  for (int i = 'H'; i <= 'K'; i++) neg[i] = tolower(i);
  for (int i = 'h'; i <= 'k'; i++) neg[i] = toupper(i);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      f['h'+i]['h'+j] = m[i][j];      ff['h'+i][m[i][j]] = 'h'+j;
      f['h'+i]['H'+j] = neg[m[i][j]]; ff['h'+i][neg[m[i][j]]] = 'H'+j;
      f['H'+i]['h'+j] = neg[m[i][j]]; ff['H'+i][neg[m[i][j]]] = 'h'+j;
      f['H'+i]['H'+j] = m[i][j];      ff['H'+i][m[i][j]] = 'H'+j;
    }
  }
}

string go(const vector<int>& first, const vector<int>& last, const string& all) {
  for (int i = 0; i < first.size(); i++) {
    for (int j = 0; j < last.size(); j++) {
      int a = first[i];
      int b = last[j]-1;
      if (a < b) {
        if (ff[pre[a]][pre[b]] == 'j') return "YES";
      }
    }
  }
  return "NO";
}

int main() {
  init();

  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int l, x; cin >> l >> x;
    string s; cin >> s;
    string all;
    while (x--) all += s;

    vector<int> first;
    char curr = 'h';
    for (int i = 0; i < all.size(); i++) {
      curr = f[curr][all[i]];
      pre[i] = curr;
      if (curr == 'i') first.push_back(i);
    }

    vector<int> last;
    for (int i = 0; i < all.size(); i++) {
      curr = pre[all.size()-1];
      if (i > 0) curr = ff[pre[i-1]][curr];
      if (curr == 'k') last.push_back(i);
    }

    cout << "Case #" << tt << ": " << go(first, last, all) << endl;
  }

  return 0;
}

