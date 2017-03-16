#include <bits/stdc++.h>

using namespace std;

int freq[30];
char str[2005], ans[2005];

string arr[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool possible(int x) {
  int aux[30]; memset(aux, 0, sizeof aux);
  for (int i = 0; i < arr[x].size(); ++i) {
    aux[arr[x][i] - 'A']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (aux[i] > freq[i]) return false;
  }
  for (int i = 0; i < 26; ++i) {
    freq[i] -= aux[i];
  }
  return true;
}

int vec[10] = {8, 0, 3, 2, 4, 5, 7, 6, 1, 9};

int main() {
  int nt; scanf("%d", &nt);
  for (int caso = 1; caso <= nt; ++caso) {
    scanf("%s", str);
    memset(freq, 0, sizeof freq);

    for (int i = 0; str[i]; ++i) {
      freq[str[i] - 'A']++;
    }

    int sz = 0;

    for (int i = 0; i < 10; ++i) {
      while (possible(vec[i])) ans[sz++] = vec[i] + '0';
    }

    sort(ans, ans + sz);
    ans[sz] = 0;

    printf("Case #%d: %s\n", caso, ans);
  }
  return 0;
}