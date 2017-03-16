#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

string elem = "eijkEIJK";

string table[8] = {
  "eijkEIJK",
  "iEkJIeKj",
  "jKEiJkeI",
  "kjIEKJie",
  "EIJKeijk",
  "IeKjiEkJ",
  "JkeIjKEi",
  "KJiekjIE"
};

char prod[256][256];
char inv[256];

bool solve()
{
  ll L, X;
  string s;
  
  cin >> L >> X >> s;

  string left_prod, right_prod;

  left_prod += s[0];
  for (int i = 1; i < L; i++) {
    left_prod += prod[left_prod[i-1]][s[i]];
  }
  char sprod = left_prod[L-1];

  char total = 'e';
  for (int i = 0; i < X; i++) {
    total = prod[total][sprod];
  }
  if (total != 'E') return false;
  
  right_prod += sprod;
  for (int i = 1; i < L; i++) {
    right_prod += prod[inv[left_prod[i-1]]][sprod];
  }

  ll left = -1;
  ll right = L * X * 2;

  char start = 'e';
  for (int i = 0; i <= min(X-1,4LL) && left < 0; i++) {
    for (int j = 0; j < L && left < 0; j++) {
      if (prod[start][left_prod[j]] == 'i') {
	left = i*L + j;
      }
    }
    start = prod[start][sprod];
  }

  char end = 'e';
  for (int i = 0; i <= min(X-1,4LL) && right > L*X; i++) {
    for (int j = L-1; j >= 0 && right > L*X; j--) {
      if (prod[right_prod[j]][end] == 'k') {
	right = L*(X-i) - (L-j);
      }
    }
    end = prod[sprod][end];
  }
  
  return left >= 0 && right <= L*X && left + 1 < right;
}

int main()
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      char a = elem[i];
      char b = elem[j];
      prod[a][b] = table[i][j];
      if (prod[a][b] == 'e') {
	inv[a] = b;
      }
    }
  }

  
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": " << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
