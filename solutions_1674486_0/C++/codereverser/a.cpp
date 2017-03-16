#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int mat[1001][1001];
int Ms[1001];
int s[1001][11];
bool found;
set<int> seen;
void pathcalc(int from, int N) { 
    if (found) return;
    if (seen.count(from)) { return; }
    seen.insert(from);
    int M = Ms[from];
    for (int j=1; j<=M; j++) { 
        int to = s[from][j];
        if (mat[from][to] == 1) { found = true; break; }
        mat[from][to] = 1;
        pathcalc(to, N);
        for (int k=1; k<=N; k++) { 
            if (mat[to][k]) {
                if (mat[from][k] == 1) { found = true; break; }
                mat[from][k] = mat[to][k]; 
            }
        }
    }
}
main() {
  int T, N, prob = 1;
  int M;
  int i, j, from, to;
  double sum, new_sum;
  for (cin >> T; T--;) {
    sum = 0;
    cin >> N;
    found = false;
    seen.clear();
    for (i=1; i<=N; i++) {
        Ms[i] = 0;
        for (j=1; j<=N; j++) mat[i][j] = 0;
    }
    for (i=1; i<=N; i++) {
        cin >> Ms[i];
        for (j=1; j<=Ms[i]; j++) cin >> s[i][j];
    }
    
    for (i=1; i<=N; i++) { 
        pathcalc(i, N);
    }
    
    printf("Case #%d: ", prob++);
    if (found) printf("Yes"); else printf("No");
    printf("\n");
  }
}
