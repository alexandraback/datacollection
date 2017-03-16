#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

// How many times does p2 beat p1?
int getNumWins(double p1[], double p2[], int n) {
  int answer = 0;
  int p2_counter = 0;
  for (int i = 0; i < n; i++) {
    while (p1[i] > p2[p2_counter] && p2_counter < n) {
      p2_counter++;
    }
    if (p2_counter >= n) { break; }

    answer++;
    p2_counter++;
  }
  return answer;
}

int main() {
  int n_tests;
  cin >> n_tests;
  for (int i_test = 0; i_test < n_tests; i_test++) {
    int n;
    cin >> n;

    double naomi[n], ken[n];
    for (int i = 0; i < n; i++) { cin >> naomi[i]; }
    for (int i = 0; i < n; i++) { cin >> ken[i]; }

    sort(naomi, naomi + n);
    sort(ken, ken + n);

    int answer_deceit = getNumWins(ken, naomi, n); 
    int answer_normal = n - getNumWins(naomi, ken, n);

    printf("Case #%d: ", i_test+1);
    printf("%d %d\n", answer_deceit, answer_normal);
  }
}
