#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long S1[26];
long long S2[26];

long long bn1, bn2, bdiff;

void generate(long long n1, long long n2, int i, int n) {
    if (i == n) {
        if (abs(n1 - n2) < bdiff) {
            bn1 = n1;
            bn2 = n2;
            bdiff = abs(n1 - n2);
        } else if (abs(n1 - n2) == bdiff) {
            if (bn1 > n1) {
                bn1 = n1;
                bn2 = n2;
            } else if (bn1 == n1 && bn2 > n2) {
                bn1 = n1;
                bn2 = n2;
            }
        }
        return;
    }
    if (S1[i] != '?'- '0' && S2[i] != '?'- '0') {
        generate(n1 * 10L + S1[i], n2 * 10L + S2[i], i+1, n);
        return;
    }
    if (n1 == n2) {
        if (S1[i] == '?'- '0' && S2[i] == '?'- '0') {
            generate(n1 * 10L, n2 * 10L, i+1, n);
            generate(n1 * 10L, n2 * 10L + 1L, i+1, n);
            generate(n1 * 10L + 1L, n2 * 10L, i+1, n);
            return;
        }
        if (S1[i] == '?'- '0') {
            if (S2[i] > 0) generate(n1 * 10L + S2[i] - 1L, n2 * 10L + S2[i], i+1, n);
                           generate(n1 * 10L + S2[i],      n2 * 10L + S2[i], i+1, n);
            if (S2[i] < 9) generate(n1 * 10L + S2[i] + 1L, n2 * 10L + S2[i], i+1, n);
            return;
        }
        if (S1[i] > 0) generate(n1 * 10L + S1[i], n2 * 10L + S1[i] - 1L, i+1, n);
                       generate(n1 * 10L + S1[i], n2 * 10L + S1[i], i+1, n);
        if (S1[i] < 9) generate(n1 * 10L + S1[i], n2 * 10L + S1[i] + 1L, i+1, n);
    }
    if (n1 < n2) {
        if (S1[i] == '?'- '0' && S2[i] == '?'- '0') {
            generate(n1 * 10L + 9L, n2 * 10L, i+1, n);
        } else if (S1[i] == '?'- '0') {
            generate(n1 * 10L + 9L, n2 * 10L + S2[i], i+1, n);
        } else {
            generate(n1 * 10L + S1[i], n2 * 10L, i+1, n);
        }
    } else {
        if (S1[i] == '?'- '0' && S2[i] == '?'- '0') {
            generate(n1 * 10L, n2 * 10L + 9L, i+1, n);
        } else if (S1[i] == '?'- '0') {
            generate(n1 * 10L, n2 * 10L + S2[i], i+1, n);
        } else {
            generate(n1 * 10L + S1[i], n2 * 10L + 9L, i+1, n);
        }
    }
}

void print(long long n, int l) {
    if (l == 0) return;
    print(n/10L, l-1);
    printf("%d", (int)(n%10L));
}

void solve() {
  bdiff = 1000000000L;
  bdiff *= bdiff;
  char c = 0;
  int n = 0;
  int k = 0;
  for (int t = 0; t <26; t++) S1[t] = S2[0] = 0;
  while ((c < '0' || c > '9') && c != '?') c= getchar();
  while ((c >= '0' && c <= '9') || c == '?') {
    S1[n++] = c - '0';
    c = getchar();
  }
  while ((c < '0' || c > '9') && c != '?') c= getchar();
  while ((c >= '0' && c <= '9') || c == '?') {
    S2[k++] = c - '0';
    c = getchar();
  }
  if (n != k) while (1);
  int index = 0;
  for (; index < n && S1[index] == S2[index]; index++);
  if (index == n) {
    for (int i = 0; i < n; i++) if (S1[i] == '?'- '0') printf("0"); else printf("%d", S1[i]);
    printf(" ");
    for (int i = 0; i < n; i++) if (S2[i] == '?'- '0') printf("0"); else printf("%d", S2[i]); 
    return;
  }
  generate(0, 0, 0, n);
  print(bn1, n);
  printf(" ");
  print(bn2, n);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}
